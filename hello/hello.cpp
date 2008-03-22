#include <stdlib.h>
#include <setjmpex.h>
#include <stdio.h>
#include <windows.h>

void template_printf(const char* t)
{
    printf(t);
}

int main()
{
    printf("%x\n", sizeof(jmp_buf));
    exit(1);
#if !defined(_MSC_VER) || defined(_CPPUNWIND)
    try
    {
#endif
        template_printf("hello\n");

#if !defined(_MSC_VER) || defined(_CPPUNWIND)
        throw 1;
    }
    catch (int)
    {
        template_printf("caught exception\n");
    }
#endif
    return 0;
}
