typedef int BOOL;
#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <wchar.h>
typedef unsigned __int64 UINT64;

typedef struct _DOUBLE_STRING {
    wchar_t a[sizeof(double) * 2 + 1];
} DOUBLE_STRING;

wchar_t NibbleToHexChar(unsigned char a)
{
    return L"0123456789abcdef"[a];
}

void ByteToHexChars(unsigned char a, wchar_t b[2])
{
    b[0] = NibbleToHexChar(a >> 4);
    b[1] = NibbleToHexChar(a & 0xF);
}

unsigned char NibbleCharToByte(wchar_t a)
/* This is offset by one so it can be used as a boolean to see if the character is valid hex. */
{
    if (a >= L'0' && a <= L'9')
        return (a - L'0' + 1);
    else if (a >= L'a' && a <= L'f')
        return (a - L'a' + 10 + 1);
    else if (a >= L'A' && a <= L'F')
        return (a - L'A' + 10 + 1);
    else
        return 0;
}

unsigned char HexCharsToByte(const wchar_t a[2])
/* This is offset by one so it can be used as a boolean to see if the characters are valid hex. */
{
    unsigned char b;
    unsigned char c;
    if (!(b = NibbleCharToByte(a[0])))
        return 0;
    if (!(c = NibbleCharToByte(a[1])))
        return 0;
    return ((((b - 1) << 4) | (c - 1)) + 1);
}

void ConvertDoubleToString(double d, DOUBLE_STRING* s)
{
    unsigned char* p = (unsigned char*) &d;
    unsigned i;
    s->a[sizeof(double) * 2] = 0;
    for (i = 0 ; i != sizeof(double) ; ++i)
    {
        ByteToHexChars(p[i],  &s->a[i * 2]);
    }
}

BOOL ConvertStringToDouble(const wchar_t* s, double* d)
{
    unsigned char* p = (unsigned char*) d;
    unsigned i;
    if (wcslen(s) != (sizeof(double) * 2))
        return FALSE;
    for (i = 0 ; i != sizeof(double) ; ++i)
    {
        if (!(p[i] = HexCharsToByte(&s[i * 2])))
            return FALSE;
        p[i] -= 1;
    }
    return TRUE;
}

int main()
{
    DOUBLE_STRING s;
    double d[] = { 0, -1, 3.1415 };
    double e[sizeof(d) / sizeof(d[0])];
    unsigned i;
    
    for (i = 0 ; i != sizeof(d) / sizeof(d[0]) ; ++i)
    {
        ConvertDoubleToString(0, &s);
        wprintf(L"%ls\n", s.a);
        if (!ConvertStringToDouble(s.a, &e[i]))
        {
            wprintf(L"error\n");
        }
        else
        {
            wprintf(L"%f %f\n", d[i], e[i]);
            wprintf(L"%I64x %f\n", (*(UINT64*) &d[i]), *(UINT64*) &e);
        }
    }

    return 0;
}
