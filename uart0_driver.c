//uart0_driver.c

#include"header.h"

#define RDR (U0LSR&1)
#define THRE ((U0LSR>>5)&1)

void uart0_init(u32 baud)
{
u32 result=0;
u32 a[5]={15,30,60,15,15};
u32 pclk=a[VPBDIV]*1000000;

result=pclk/(16*baud);

PINSEL0 |= 0X05;

U0LCR=0X83;
U0DLL=(result & 0XFF);
U0DLM=(result >> 8) & 0XFF;
U0LCR=0X03;
}

void uart0_tx(u8 data)
{
U0THR=data;
while(THRE==0);
}

u8 uart0_rx(void)
{
while(RDR==0);
return U0RBR;
}

void uart0_tx_string(char* p)
{
while(*p)
{
U0THR=*p;
while(THRE==0);
p++;
}
}

void uart0_rx_string(char* p, u8 maxlen)
{
int i;
for(i=0;i<maxlen;i++)
{
while(RDR==0);
p[i]=U0RBR;

if(U0RBR=='\r')
break;
}
p[++i]='\n';
}

void uart0_integer(int num)
{
int i,a[15];

if(num==0)
{
uart0_tx('0');
return;
}

if(num<0)
{
uart0_tx('-');
num=-num;
}

i=0;
while(num)
{
a[i]=num%10 +48;
num /= 10;
i++;
}

for(i=i-1;i>=0;i--)
uart0_tx(a[i]);

}

void uart0_float(float num)
{
float f;
int n;

if(num<0)
{
uart0_tx('-');
num=-num;
}

n=num;
uart0_integer(n);
uart0_tx('.');

f=num-n;
f=f*1000000;
n=f;
uart0_integer(n);
}
