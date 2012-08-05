#include "futex.h"
#include "syscall.h"
#define __NEED_time_t
#define __NEED_struct_timespec
#include <bits/alltypes.h>


int __futex_wait(volatile void *ftx, int val, const struct timespec *timeout)
{
    return __futex(ftx, FUTEX_WAIT, val, (void*)timeout);
}
