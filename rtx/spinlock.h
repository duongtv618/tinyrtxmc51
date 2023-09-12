#ifndef SPINLOCK_H
#define SPINLOCK_H

#include "os.h"

typedef char lock_t;

void lock(lock_t *);
void unlock(lock_t *);
char try_lock(lock_t *);

#endif