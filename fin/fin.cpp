#include <stdio.h>


#define PASTEx(x,y) x##y
#define PASTE(x,y) PASTEx(x,y)

#define FINALLY(code) \
 class PASTE(FINALLY1_, __LINE__) {public: PASTE(FINALLY1_, __LINE__)() { } ~PASTE(FINALLY1_, __LINE__)() { code ; }} \
 PASTE(FINALLY2_, __LINE__)

int main(int argc, char** argv)
{
FILE* f = 0;
FINALLY(if (f) fclose(f));

f = fopen(argv[1], "r");

return 0;
}
