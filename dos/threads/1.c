#include <dpmi.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <stdio.h>

struct x86descriptor_t; typedef struct x86descriptor_t x86descriptor_t;
struct Context_t; typedef struct Context_t Context_t;
struct Thread_t; typedef struct Thread_t Thread_t;

struct Context_t
{
    jmp_buf jb;
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

Thread_t* GetCurrentThread(void)
{
    /* winnt.h */
    Thread_t* ret;
    __asm__ __volatile__ (
        "mov{l} {%%fs:0x18,%0|%0,%%fs:0x18}\n"
        : "=r" (ret)
        : /* no inputs */
    );
    return ret;
}

void Scheduler_Yield()
{
}

char* Thread1_Entry(char* a)
{
    while (1)
    {
        printf("thread 1\n");
        Scheduler_Yield();
    }
    return 0;
}

char* Thread2_Entry(char* a)
{
    while (1)
    {
        printf("thread 2\n");
        Scheduler_Yield();
    }
    return 0;
}

char* _Thread_Start(char * a)
{
    return a + 1;
}

void Thread_Init(Thread_t* t)
{
    Context_t Context;
    x86descriptor_t d;

    setjmp(Context.jb);
    Context.jb[0].__esp = (size_t) calloc(1, 1UL << 16);
    Context.jb[0].__eip = (size_t) _Thread_Start;
    Context.jb[0].__fs = __dpmi_create_alias_descriptor(Context.jb[0].__ds);
    __dpmi_get_descriptor(Context.jb[0].__fs, &d);
    d.G = 0;
    x86descriptor_set_limit(&d, 0x22);
    x86descriptor_set_base(&d, (size_t) t);
    t->Context = Context;
}

void Thread_Run(Thread_t* t)
{
    longjmp(t->Context.jb, 1);
}

int main()
{
    Thread_t Thread1 = { 0 };
    Thread_t Thread2 = { 0 };

    Thread1.Next = &Thread2;
    Thread1.Entry = Thread1_Entry;
    Thread2.Next = &Thread1;
    Thread2.Entry = Thread2_Entry;

    Thread1.Parameter = (char*) (size_t) 123;
    Thread_Init(&Thread1);
    Thread_Run(&Thread1);

    return 0;
}
