#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <stdio.h>

extern "C"
{

typedef struct Thread_t Thread_t;

typedef struct Thread_t
{
    Thread_t* NextThread;
    char* (*Start)(char* Parameter);
    char* Parameter;
    jmp_buf Context;
    char* ExitValue;
    unsigned ThreadDone : 1;
} Thread_t;

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
}

void Thread_Init(void)
{
    jmp_buf jb;

    setjmp(jb); /* get segment registers */
    jb.__eax = 0;
    jb.__ebx = 0;
    jb.__edx = 0;
    jb.__esi = 0;
    jb.__edi = 0;
    jb.__ebp = 0;
    jb.__esp = (size_t) calloc(1, 1UL << 16);
    jb.__eip = _Thread_Start;
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
