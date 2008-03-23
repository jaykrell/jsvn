#include <assert.h>
#include <dpmi.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned long UINT32;

struct x86descriptor_t; typedef struct x86descriptor_t x86descriptor_t;
struct Context_t; typedef struct Context_t Context_t;
struct Thread_t; typedef struct Thread_t Thread_t;

Thread_t* GetCurrentThread(void);
UINT32 GetContext(Context_t*);
void   SetContext(const Context_t*);
UINT32 GetDS(void);

struct Context_t
{
    UINT32 eip,ebx,ecx,edx,ebp,edi,esi,esp;
    UINT16 fs;
};

/*
http://www.informit.com/articles/article.aspx?p=167857&seqNum=3
*/
struct x86descriptor_t
{
    unsigned Limit1 : 16;
    unsigned Base1 : 16;
    unsigned Base2 : 8;
    unsigned Type : 4;
    unsigned S : 1;
    unsigned DPL : 2;
    unsigned P : 1;
    unsigned Limit2 : 4;
    unsigned AVL : 1;
    unsigned Reserved : 1;
    unsigned DB : 1;
    unsigned G : 1;
    unsigned Base3 : 8;
};

unsigned x86descriptor_get_limit(x86descriptor_t* a)
{
    return ((a->Limit2 << 16) | a->Limit1);
}

void x86descriptor_set_limit(x86descriptor_t* a, unsigned b)
{
    a->Limit2 = (b >> 16);
    a->Limit1 = b;
}

unsigned x86descriptor_get_base(x86descriptor_t* a)
{
    return ((a->Base3 << 24) | (a->Base2 << 16) | (a->Base1));
}

void x86descriptor_set_base(x86descriptor_t* a, unsigned b)
{
    a->Base3 = (b >> 24);
    a->Base2 = (b >> 16);
    a->Base1 = b;
}

struct Thread_t
{
    /* winnt.h */
    /* 0 */ size_t EH;
    /* 4 */ size_t StackBase;
    /* 8 */ size_t StackLimit;
    /* 12,16,20 */ size_t Reserved[3];
    /* 24 */ Thread_t * Self;
    Thread_t* Next;
    char* (*Entry)(char* Parameter);
    char* Parameter;
    Context_t Context;
    char* ExitValue;
    unsigned Exited : 1;
};

/* winnt.h */
__inline__ Thread_t * GetCurrentThread(void)
{
    Thread_t *ret;

    __asm__ __volatile__ (
        "mov{l} {%%fs:0x18,%0|%0,%%fs:0x18}\n"
        : "=r" (ret)
        : /* no inputs */
    );

    return ret;
}

void Scheduler_Yield()
{
    Thread_t* t = GetCurrentThread();
    if (GetContext(&t->Context))
        return;
    /* obviously need work here to pick next thread */
    SetContext(&t->Next->Context);
}

char* Thread1_Entry(char* a)
{
    unsigned b;
    for (b = 0 ; b != 20 ; ++b)
    {
        printf("thread 1 %x ", a);
        fflush(stdout);
        Scheduler_Yield();
    }
    return 0;
}

char* Thread2_Entry(char* a)
{
    unsigned b;
    for (b = 0 ; b != 20 ; ++b)
    {
        printf("thread 2 %x ", a);
        fflush(stdout);
        Scheduler_Yield();
    }
    return 0;
}

void _Thread_Entry(Thread_t* t)
{
    t->ExitValue = t->Entry(t->Parameter);
    printf("thread end\n");
    /* need work here */
    exit(2);
}

void Thread_Init(Thread_t* t)
{
    Context_t Context;
    x86descriptor_t d;

    t->Self = t;
    GetContext(&Context);
    Context.esp = (size_t) calloc(1, 1UL << 16);
    Context.esp += ((1UL << 16) - 4);
    *((UINT32*)Context.esp) = (UINT32) t;
    Context.esp -= 4;
    *((UINT32*)Context.esp) = (UINT32) _Thread_Entry;
    Context.esp -= 4;
    Context.fs = __dpmi_create_alias_descriptor(GetDS());
    __dpmi_get_descriptor(Context.fs, &d);
    assert(d.G == 0);
    x86descriptor_set_limit(&d, 0x18+3);
    x86descriptor_set_base(&d, x86descriptor_get_base(&d) + (size_t) t);
    __dpmi_set_descriptor(Context.fs, &d);
/*
    Context.fs = __dpmi_allocate_ldt_descriptors(1);
    __dpmi_set_segment_base_address(Context.fs, (size_t) t);
    __dpmi_set_segment_limit(Context.fs, 0x18 + 3);
*/
    t->Context = Context;
}

void Thread_Run(Thread_t* t)
{
    SetContext(&t->Context);
}

int main()
{
    Thread_t Thread1 = { 0 };
    Thread_t Thread2 = { 0 };

    Thread1.Next = &Thread2;
    Thread1.Entry = Thread1_Entry;
    Thread2.Next = &Thread1;
    Thread2.Entry = Thread2_Entry;

    Thread1.Parameter = (char*) (size_t) 0x123;
    Thread2.Parameter = (char*) (size_t) 0x456;
    Thread_Init(&Thread1);
    Thread_Init(&Thread2);
    Thread_Run(&Thread1);

    return 0;
}
