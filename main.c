#include <8051.h>
#include "os.h"
#include "uart.h"


void task_blink(void);
void task_uart(void);
void task_blink_p3(void);

void main()
{
	os_create_task(task_blink, 0x20);
	os_create_task(task_uart, 0x20);
	os_create_task(task_blink_p3, 0x20);

	os_start_scheduler();
	return;
}

void task_uart(void)
{
	uart_init();
	// uart_set_mode_it(UART_MODE_IT_TRANS);
	while (1)
	{
		uart_put_string("Hello cac ban, to la duong!\n");
		os_delay_tick(10);
	}
	
}

void task_blink(void)
{
	while (1)
	{
		P1 = ~P1;
		os_delay_tick(2);
	}
}

void task_blink_p3(void)
{
	while (1)
	{
		P2 =~ P2;
		os_delay_tick(1);
	}
	
}