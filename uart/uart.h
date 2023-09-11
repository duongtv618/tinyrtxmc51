#ifndef UART_H
#define UART_H

#include "8051.h"
#include "stdint.h"

#define UART_MODE_IT_REC 0
#define UART_MODE_IT_TRANS 1

#define UART_INTERRUPT_ENABLE (ES = 1)
#define UART_INTERRUPT_DISABLE (ES = 0)

void uart_init(void);
void uart_put_char(char);
void uart_put_string(const char *);
char uart_is_rx_ready(void);
char uart_read_char(void);
void print_int8_t(int8_t);

void uart_ISR(void) __interrupt SI0_VECTOR __naked;

#endif