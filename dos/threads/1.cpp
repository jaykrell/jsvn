#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <stdio.h>

/*
http://www.informit.com/articles/article.aspx?p=167857&seqNum=3
*/
struct x86descriptor_t;
typedef struct x86descriptor_t x86descriptor_t;
struct x86descriptor_t
{
    unsigned Limit1 : 16;
    unsigned Base1 : 16;
    unsigned Base2 : 16;
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

unsigned x86descriptor_get_limit(x86descriptor* a)
{
    return ((a->Limit2 << 16) | a->Limit1);
}

void x86descriptor_set_limit(x86descriptor* a, unsigned b)
{
    a->Limit2 = (b >> 16);
    a->Limit1 = b;
}

unsigned x86descriptor_get_base(x86descriptor* a)
{
    return ((a->Base3 << << 32) | (a->Base2 << 16) | (a->Base1));
}

void x86descriptor_set_base(x86descriptor* a, unsigned b)
{
    a->Base3 = (b >> 32);
    a->Base2 = (b >> 16);
    a->Base1 = b;
}

typedef struct Thread_t Thread_t;

typedef struct Thread_t
{
    /* winnt.h */
    /* 0 */ size_t EH;
    /* 4 */ size_t StackBase;
    /* 8 */ size_t StackLimit;
    /* 12,16,20 */ size_t Reserved[3];
    /* 24 */ Thread_t * Self;
    Thread_t* Next;
    char* (*Start)(char* Parameter);
    char* Parameter;
    jmp_buf Context;
    char* ExitValue;
    unsigned Exited : 1;
} Thread_t;

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

extern Thread_t Thread2;
Thread_t Thread1 = { &Thread2, Thread1_Entry };
Thread_t Thread2 = { &Thread1, Thread2_Entry };

void Thread_Init(void)
{
    jmp_buf jb;
    x86descriptor_t sel;

    setjmp(jb);
    /*
    jb.__eax = 0;
    jb.__ebx = 0;
    jb.__edx = 0;
    jb.__esi = 0;
    jb.__edi = 0;
    jb.__ebp = 0;
    */
    jb.__esp = (size_t) calloc(1, 1UL << 16);
    jb.__eip = _Thread_Start;
    __dpmi_get_descriptor(jb.ds, &sel);
}

int main()
{
    Thread_t t;

    memset(&t, 0, sizeof(t));
    try
    {
        t.Start = &ThreadMain;
        t.Parameter = (char*) (size_t) 123;
        Thread_Run(&t);
    }
    catch (...)
    {
        exit(2);
    }
    return 0;
}
