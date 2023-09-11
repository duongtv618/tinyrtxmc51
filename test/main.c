#include <8051.h>
#include "os.h"
#include "uart.h"

void task_blink(void);
void task_uart(void);
void task_blink_p3(void);

void main()
{
	os_create_task(task_blink, 0x18);
	os_create_task(task_uart, 0x10);
	os_create_task(task_blink_p3, 0x18);

	os_start_scheduler();
	return;
}

/** help function*/
void print_int8_t(int8_t c)
{
	char buf[5];
	char i;
	char negative = 0;
	int8_t temp;

	i = 0;
	temp = c;
	buf[i++] = 0;

	if (c < 0)
	{
		negative = 1;
		c = -c;
	}

	do
	{
		temp = c % 10;
		buf[i++] = temp + '0';
	} while ((c /= 10) > 0);

	if (negative)
		buf[i++] = '-';

	// reverse;
	while (buf[--i])
	{
		uart_put_char(buf[i]);
	}
}

void task_uart(void)
{
	uart_init();
	// uart_set_mode_it(UART_MODE_IT_TRANS);

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
		// P2 = ~P2;
		os_yeild();
	}
}