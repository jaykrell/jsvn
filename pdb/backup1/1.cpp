typedef struct _FOO
{
 int fooi;
} FOO;

__declspec(dllexport)
int FooF(FOO* f) { return f->fooi; }
