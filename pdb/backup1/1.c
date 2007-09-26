typedef struct _FOO
{
 __int64 fooi;
} FOO;

__declspec(dllexport)
int FooF(FOO* f)
{
    return f->fooi;
}
