#include "os.h"
#include <stdint.h>
#include "8051.h"

#define STACK_START 0x20
#define MAX_TASK 3
#define TIMER0_INT_ENABLE (ET0 = 1)

#define save_context()          \
    {                           \
        __asm__("push ACC\n\t	 \
				push DPL\n\t     \
				push DPH\n\t\
				push b\n\t\
				push ar2\n\t\
				push ar3\n\t\
				push ar4\n\t\
				push ar5\n\t\
				push ar6\n\t\
				push ar7\n\t\
				push ar0\n\t\
				push ar1\n\t\
				push PSW\n\t"); \
        current_SP = SP;        \
    }

#define restore_context() \
    {                     \
        SP = current_SP;  \
        __asm__("pop PSW\n\t\
			pop ar1\n\t\
			pop ar0\n\t\
			pop ar7\n\t\
			pop ar6\n\t\
			pop ar5\n\t\
			pop ar4\n\t\
			pop ar3\n\t\
			pop ar2\n\t\
			pop b\n\t\
			pop DPH\n\t\
			pop DPL\n\t\
			pop ACC\n\t\
			reti\n\t");   \
    }

static struct task_s
{
    uint8_t sp;
    uint8_t state;
} task[MAX_TASK];

static uint8_t current_SP = STACK_START;
static uint16_t _tick = 0;
static uint8_t taskcnt = 0;
static uint8_t tasknum = 0;

static void timer0_init(void);
static void timer0_start(void);
static void idle_task(void);
static void switch_to(void);

static void timer0_init(void)
{
    TMOD += 0x01;
    TH0 = 0xdb;
    TL0 = 0xff;
}

static void timer0_start(void)
{
    TR0 = 1;
}

void Timer0_ISR(void) __interrupt TF0_VECTOR __naked
{
    TF0 = 0;
    TH0 = 0xdb;
    TL0 = 0xff;

    ++_tick;
    save_context();
    switch_to();
    restore_context();
}

static void switch_to(void)
{
    task[taskcnt].sp = current_SP;

    // find the next task to run, return in taskcnt
    if (++taskcnt >= tasknum)
        taskcnt = 0;

    current_SP = task[taskcnt].sp;
}

void os_create_task(void (*func)(void), uint8_t size)
{
    static uint8_t cstackptr = STACK_START;

    __data uint8_t __at(0x7f) h = (uint8_t)(func);
    __data uint8_t __at(0x7e) l = (uint8_t)((uint16_t)func >> 8);

    
    __data uint8_t __at(0x7d) sp = cstackptr;

    __asm__("\
		mov 0x7c, r0\n\t\
		mov r0, 0x7d\n\t\
		mov @r0, 0x7f\n\t\
		inc r0\n\t\
		mov @r0, 0x7e\n\t\
		mov r0, 0x7c\n\t\
	");

    current_SP = cstackptr + 14;
    task[taskcnt++].sp = current_SP;
    tasknum++;
    cstackptr += size;
}

void os_start_scheduler(void)
{
    if (tasknum == 0)
        os_create_task(idle_task, 0x20);

    INTERRUPT_ENABLE;
    TIMER0_INT_ENABLE;
    timer0_init();
    timer0_start();
    restore_context();
}
void os_delay_tick(unsigned short tick)
{
    tick += _tick;
    while (_tick < tick)
        ;
}
static void idle_task(void)
{
    while (1)
        ;
}