/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief A test program for tinyrtx51
 * @version 0.1
 * @date 2023-09-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <8051.h>
#include "os.h"
#include "uart.h"
#include "spinlock.h"

int8_t critical_resource = 0;
lock_t slock;

void task_blink(void);
void task_uart(void);
void task_blink_p3(void);

void main()
{
	os_create_task(task_blink, 0x18);
	os_create_task(task_uart, 0x20);
	os_create_task(task_blink_p3, 0x18);

	os_start_scheduler();
	return;
}

void task_uart(void)
{
	uart_init();

	while (1)
	{
		/** if we dont lock critical_resource
		 * critical_resource's value can be modify
		 * by other task
		 */
		lock(&slock);
		for (int i = 0; i < 10; i++)
		{
			// uart_put_string("Hello world! #");
			print_int8_t(++critical_resource);
			uart_put_char('\n');
		}
		unlock(&slock);
		os_delay_tick(100);
	}
}

void task_blink(void)
{
	while (1)
	{
		if (try_lock(&slock))
		{
			P1 = ~P1;
			critical_resource += 10;
			unlock(&slock);
		}
		os_yeild();
		os_delay_tick(10);
	}
}

void task_blink_p3(void)
{
	uint8_t a = 0;
	while (1)
	{
		a++;
		P2 = a;
		// os_yeild();
		os_delay_tick(100);
	}
}