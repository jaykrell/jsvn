#include <stdio.h>

/* make sure templates work */
#if !defined(_MSC_VER) || (_MSC_VER > 800)

template <class T>
void template_printf(T t)
{
    printf(t);
}

#else

void template_printf(const char* t)
{
    printf(t);
}

#endif

int main()
{
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