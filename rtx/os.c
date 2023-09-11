#include "os.h"
#include <stdint.h>
#include "8051.h"

#define STACK_START 0x20
#define MAX_TASK 3
#define TIMER0_INT_ENABLE (ET0 = 1)

#define save_context()           \
    {                            \
        __asm__("push ACC\n\t"); \
        __asm__("push DPL\n\t"); \
        __asm__("push DPH\n\t"); \
        __asm__("push b\n\t");   \
        __asm__("push ar2\n\t"); \
        __asm__("push ar3\n\t"); \
        __asm__("push ar4\n\t"); \
        __asm__("push ar5\n\t"); \
        __asm__("push ar6\n\t"); \
        __asm__("push ar7\n\t"); \
        __asm__("push ar0\n\t"); \
        __asm__("push ar1\n\t"); \
        __asm__("push PSW\n\t"); \
        current_SP = SP;         \
    }

#define restore_context()       \
    {                           \
        SP = current_SP;        \
        __asm__("pop PSW\n\t"); \
        __asm__("pop ar1\n\t"); \
        __asm__("pop ar0\n\t"); \
        __asm__("pop ar7\n\t"); \
        __asm__("pop ar6\n\t"); \
        __asm__("pop ar5\n\t"); \
        __asm__("pop ar4\n\t"); \
        __asm__("pop ar3\n\t"); \
        __asm__("pop ar2\n\t"); \
        __asm__("pop b\n\t");   \
        __asm__("pop DPH\n\t"); \
        __asm__("pop DPL\n\t"); \
        __asm__("pop ACC\n\t"); \
        __asm__("reti\n\t");    \
    }


static uint8_t current_SP = STACK_START;
static uint16_t _tick = 0;
static uint8_t taskcnt = 0;
static uint8_t tasknum = 0;

static uint8_t tasksp[MAX_TASK] = {0, 0, 0};

// static void save_context(void) __naked;
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

// static void save_context(void) __naked
// {
//     __asm__("push ACC\n\t");
//     __asm__("push DPL\n\t");
//     __asm__("push DPH\n\t");
//     __asm__("push b\n\t");
//     __asm__("push ar2\n\t");
//     __asm__("push ar3\n\t");
//     __asm__("push ar4\n\t");
//     __asm__("push ar5\n\t");
//     __asm__("push ar6\n\t");
//     __asm__("push ar7\n\t");
//     __asm__("push ar0\n\t");
//     __asm__("push ar1\n\t");
//     __asm__("push PSW\n\t");
//     current_SP = SP;
// }

// static void restore_context(void) __naked
// {
//     SP = current_SP;
//     __asm__("pop PSW\n\t");
//     __asm__("pop ar1\n\t");
//     __asm__("pop ar0\n\t");
//     __asm__("pop ar7\n\t");
//     __asm__("pop ar6\n\t");
//     __asm__("pop ar5\n\t");
//     __asm__("pop ar4\n\t");
//     __asm__("pop ar3\n\t");
//     __asm__("pop ar2\n\t");
//     __asm__("pop b\n\t");
//     __asm__("pop DPH\n\t");
//     __asm__("pop DPL\n\t");
//     __asm__("pop ACC\n\t");
//     __asm__("reti\n\t");
// }

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

void os_yeild(void)
{
    /** Set timer value to -3 so that it need 3 machine cycle
     * ignore to use tf0 set to 1 cause it can cause unexpected
     * behavior
    */
    TH0 = 0xFF;
    TL0 = 0xFC;
}

static void switch_to(void)
{
    tasksp[taskcnt] = current_SP;

    // find the next task to run, return in taskcnt
    if (++taskcnt >= tasknum)
        taskcnt = 0;

    current_SP = tasksp[taskcnt];
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
    tasksp[tasknum++] = current_SP;
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

    //task [0] will be the first task to go
    if (taskcnt >= tasknum)
        taskcnt = 0;
    current_SP = tasksp[taskcnt];
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