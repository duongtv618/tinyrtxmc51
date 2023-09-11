#include <8051.h>
#include "os.h"
#include "uart.h"

void task_blink(void);
void task_uart(void);
void task_blink_p3(void);

void main()
{
	os_create_task(task_blink, 0x18);
	os_create_task(task_uart, 0x30);
	os_create_task(task_blink_p3, 0x18);

	os_start_scheduler();
	return;
}

void task_uart(void)
{
	uart_init();

	int8_t count = -127;

	while (1)
	{
		uart_put_string("Hello world! #");
		print_int8_t(++count);
		uart_put_char('\n');
		os_delay_tick(1);
	}
}

void task_blink(void)
{
	while (1)
	{
		P1 = ~P1;
		// os_yeild();
		os_delay_tick(1);
	}
}

void task_blink_p3(void)
{
	uint8_t a = 0;
	while (1)
	{
		a++;
		P2 = a;
		os_yeild();
	}
}