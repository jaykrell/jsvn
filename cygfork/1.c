#include <stdio.h>
#include <process.h>

int main()
{
    int pid;
    const char * arg[] = {"cmd", 0};

    fprintf(stderr, "aa\n");

    pid = spawnvp(0, arg[0], arg);
    fprintf(stderr, "bb\n");
    fprintf(stderr, "xx %d xx\n", pid);
    waitpid(pid);
    fprintf(stderr, "cc\n");

    return 0;
}
