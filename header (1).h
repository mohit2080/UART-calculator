#include<lpc21xx.h>

typedef unsigned char u8;
typedef unsigned int u32;

extern void uart0_init(u32 baud);
extern void uart0_tx(u8 data);
extern u8 uart0_rx(void);
extern void uart0_tx_string(char* p);
extern void uart0_rx_string(char* p, u8 maxlen);
extern void uart0_integer(int num);
extern void uart0_float(float num);
