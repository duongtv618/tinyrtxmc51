#ifndef OS_H
#define OS_H

#include "8051.h"
#include <stdint.h>

#define TASK_STATE_IDLE 0
#define TASK_STATE_RUNNING 1
#define TASK_STATE_SUSPEND 2

#define ENTER_CRITICAL_SECTION INTERRUPT_DISABLE
#define EXIT_CRITICAL_SECTION INTERRUPT_ENABLE

#define INTERRUPT_ENABLE (EA = 1)
#define INTERRUPT_DISABLE (EA = 0)

void os_delay_tick(unsigned short);
void os_create_task(void (*func)(void), uint8_t size);
void os_start_scheduler(void);
void os_yeild(void);
void Timer0_ISR(void) __interrupt TF0_VECTOR __naked;
#endif