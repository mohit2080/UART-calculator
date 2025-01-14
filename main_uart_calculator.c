// main_uart_calculator.c

#include"header.h"

int main()
{
char p[8];
int i,n1,n2,n3;
char ch;

uart0_init(9600);

while(1)
{
uart0_tx_string("enter expression: eg. 32+40\r\n");
uart0_rx_string(p,8);
uart0_tx_string(p);

i=0,n1=0,n2=0;
while(p[i]>='0' && p[i]<='9')
n1=n1*10 + (p[i++]-48);

ch=p[i++];

while(p[i]>='0' && p[i]<='9')
n2=n2*10 + (p[i++]-48);

switch(ch)
{
case '+' : n3=n1+n2;
			uart0_integer(n3);
			uart0_tx_string("\r\n");
			break;
case '-' : n3=n1-n2;
			uart0_integer(n3);
			uart0_tx_string("\r\n");
			break;
case '/' : n3=n1/n2;
			uart0_integer(n3);
			uart0_tx_string("\r\n"); 
			break;
case '*' : n3=n1*n2;
			uart0_integer(n3);
		   uart0_tx_string("\r\n");
			break;
case '%' : n3=n1%n2;
			uart0_integer(n3);
		   uart0_tx_string("\r\n");
			break;

default: uart0_tx_string("enter correct choice\r\n");
}
}
}
