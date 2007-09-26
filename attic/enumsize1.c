

#include <stdio.h>

enum A { a = 1 };
enum B { b = 0x100 };
enum C { c = 0x10000 };
enum D { d = 0 };
enum E { e = 0 };

int main()
{
unsigned f[] =
{
 sizeof(a),
 sizeof(b),
 sizeof(c),
 sizeof(d),
 sizeof(e),
 sizeof(enum A),
 sizeof(enum B),
 sizeof(enum C),
 sizeof(enum D),
 sizeof(enum E)
};
unsigned g;
#define number_of(x) (sizeof(x)/sizeof((x)[0]))
for (g = 0 ; g != number_of(f) ; ++g)
{
printf("%u\n", f[g]);
}
return 0;
}
