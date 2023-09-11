#include "uart.h"
#include "8051.h"

#define NOT_COMPLETE 0
#define COMPLETE 1

static char mode = UART_MODE_IT_REC;
static char *cur_buf = 0;
static void (*uart_rec_it_callback)(char);
static char trans_complete = 0;

void uart_init(void)
{
    SCON = 0x50;
    TMOD += 0X20;
    TH1 = 0xFD;
    TH0 = 0xFD;
    PCON += 0x80;
    TR1 = 1;
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
    while (str[i])
        uart_put_char(str[i++]);
}

void uart_ISR(void) __interrupt SI0_VECTOR __naked
{
    __asm__("reti");
}