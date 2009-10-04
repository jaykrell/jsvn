#include "j.h"
#include <errno.h>

long
jk_get_errno(
    void)
{
    long err = errno;
    if (err == 0)
        err = -1;
    else if (err > 0)
        err = -err;
    return err;
}
