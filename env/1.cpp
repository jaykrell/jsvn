#ifdef __cplusplus
extern "C" {
#endif

int printf(const char* a, ...);

#ifdef __cplusplus
}
#endif

#if defined(_WIN32) || defined(_M_MPPC)
__declspec(dllexport) void Export1(void) { }
#endif

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

void Main(void)
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
}

int main()
{
    Main();
    return 0;
}

#if (_MSC_VER > 800) && !defined(__WATCOMC__)

/* for Windows CE */

void __stdcall WinMain(void)
{
    Main();
}

#endif
