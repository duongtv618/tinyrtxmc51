#include <8051.h>
#include <string.h>

#define INTERRUPT_ENABLE (IE = 0x96)

unsigned char curSP = 0;
unsigned short _tick = 0;

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
		curSP = SP;             \
	}

#define restore_context() \
	{                     \
		SP = curSP;       \
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

struct task_s
{
	unsigned short pc;
	unsigned char sp;
} task1, task2;

void uart_init(void);
void uart_put_char(char);
void uart_put_string(const char *);
char uart_is_rx_ready(void);
char uart_read_char(void);

void delay_us(unsigned short);
void delay_ms(unsigned short);
void delay_tick(unsigned short);

void timer0_init(void);
void timer0_start(void);

void task1_func(void);
void task2_func(void);

void task_create(void);

void switch_to(void);

void Timer0_ISR(void) __interrupt 1 __naked
{
	TF0 = 0;
	TH0 = 0xdb;
	TL0 = 0xff;

	++_tick;
	save_context();
	switch_to();
	restore_context();
}

enum
{
	TASK1,
	TASK2
} curTask = TASK1;

void main()
{
	// INTERRUPT_ENABLE;
	EA = 1;
	ET0 = 1;

	// uart_init();
	timer0_init();
	timer0_start();

	task1.sp = 0x1f;
	task2.sp = 0x55;

	task1.pc = (unsigned short)(&task1_func);
	task2.pc = (unsigned short)(&task2_func);

	// add task1
	// put address of task1 bewlow task space, start with sp
	__data unsigned char __at(0x1f) a = (task1.pc) & 0xff;
	__data unsigned char __at(0x20) b = ((task1.pc) >> 8) & 0xff;

	task1.sp += 14;

	// add task2
	// put address of task2 below the stack space
	__data unsigned char __at(0x55) c = (task2.pc) & 0xff;
	__data unsigned char __at(0x56) d = ((task2.pc) >> 8) & 0xff;

	task2.sp += 14;
	curSP = task1.sp;

	// restore first task
	restore_context();

	while (1)
		;
}

void delay_tick(unsigned short tick)
{
	tick += _tick;
	while (_tick < tick)
		;
}

void switch_to(void)
{
	if (curTask == TASK1)
	{
		task1.sp = curSP;
		curTask = TASK2;
		curSP = task2.sp;
	}
	else
	{
		task2.sp = curSP;
		curTask = TASK1;
		curSP = task1.sp;
	}
}

void delay_us(unsigned short us)
{
	while (--us)
		;
}
void delay_ms(unsigned short ms)
{
	while (--ms)
		delay_us(1000);
}

void task1_func(void)
{
	int a = 0;
	P1 = 0xff;
	P3_4 = 0;
	P3_3 = 1;
	while (1)
	{
		P1 = ~P1;
		P3_4 = !P3_4;
		P3_3 = !P3_3;
		delay_tick(10);
	}
}

void task2_func(void)
{
	uart_init();
	while (1)
	{
		uart_put_string("Hello, toi la duong day!\n");
		delay_tick(20);
	}
}

void timer0_init(void)
{
	TMOD += 0x01;
	TH0 = 0xdb;
	TL0 = 0xff;
}

void timer0_start(void)
{
	TR0 = 1;
}

void uart_init(void)
{
	SCON = 0x50;
	TMOD += 0X20;
	TH1 = 0xE8;
	TH0 = 0xE8;
	TR1 = 1;
}

void uart_put_char(char c)
{
	SBUF = c;
	while (TI == 0)
		;
	TI = 0;
}

char uart_is_rx_ready(void)
{
	return RI;
}

char uart_read_char(void)
{
	RI = 0;
	return SBUF;
}

void uart_put_string(const char *str)
{
	unsigned char i = 0;
	while (*str)
		uart_put_char(*str++);
}
