#include "j.h"
#include <stdlib.h>

long
jk_malloc(
    void ** pp,
    size_t n)
{
    void * p;

    jk_function(jk_malloc);
    jk_profile_count_function_call();

    *pp = 0;
    p = malloc(n);
    *pp = p;
    if (p == 0)
    {
        return jk_out_of_memory_error;
    }
    return 0;
}

void
jk_free(
    void ** pp)
{
    void * p = *pp;

    jk_function(jk_free);
    jk_profile_count_function_call();

    *pp = 0;
    if (p != 0)
    {
        jk_function(jk_free_non_null);
        jk_profile_count_function_call();
        free(p);
    }
}
