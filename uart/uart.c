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
    while (str[i])
        uart_put_char(str[i++]);
}

void uart_ISR(void) __interrupt SI0_VECTOR __naked
{
    if (UART_MODE_IT_REC == mode)
    {
        RI = 0;
        uart_rec_it_callback(SBUF);
    }
    else
    {
        TI = 0;
        if (cur_buf[0] != 0)
        {
            SBUF = cur_buf[0];
            cur_buf++;
        }
        else
        {
            trans_complete = 1;
        }
    }

    __asm__("reti\n\t");
}

void uart_set_mode_it(char m)
{
    mode = m;
    UART_INTERRUPT_ENABLE;
}
void uart_put_char_it(char c)
{
    SBUF = c;
}

void uart_put_string_it(const char *str)
{
    if (NOT_COMPLETE == trans_complete)
        return;

    if (str[0] == 0)
        return;

    trans_complete = NOT_COMPLETE;
    SBUF = str[0];
    cur_buf = str + 1;
}

void uart_rec_it(void (*func)(char))
{
    uart_rec_it_callback = func;
}