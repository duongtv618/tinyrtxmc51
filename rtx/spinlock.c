#include "spinlock.h"

void lock(lock_t *slock)
{
    // wait util lock is free
    while (slock[0] == 1)
        ;
    
    ENTER_CRITICAL_SECTION;
    slock[0] = 1;
    EXIT_CRITICAL_SECTION;
}

void unlock(lock_t * slock)
{
    ENTER_CRITICAL_SECTION;
    slock[0] = 0;
    EXIT_CRITICAL_SECTION;
}

char try_lock(lock_t * slock)
{
    char t;

    ENTER_CRITICAL_SECTION;
    t = slock[0];
    EXIT_CRITICAL_SECTION;
    if (t == 1)
        return 0;

    ENTER_CRITICAL_SECTION;
    slock[0] = 1;
    EXIT_CRITICAL_SECTION;
    return 1;
}