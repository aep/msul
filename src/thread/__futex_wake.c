#include "futex.h"
#include "syscall.h"
#define __NEED_time_t
#define __NEED_struct_timespec
#include <bits/alltypes.h>

int __futex_wake(volatile void *ftx, int count)
{
    return __futex(ftx, FUTEX_WAKE, count, 0);
}
