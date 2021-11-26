#include "reg52.h"
#include "intrins.h"
typedef unsigned char u8;
typedef unsigned int u16;
#define A P0
sbit led1=P2^2;
sbit led2=P2^3;
sbit led3=P2^4;
u8 a[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x00};
u8 c,d,g,i;

void delay(u16 i)
{
  while(i--)
  {
  
  }
}
void Time0Int()
{
	TMOD|=0x01;
	TH0=0XFC;
	TL0=0X18;
	ET0=1;
	EA=1;
	TR0=1;
}

void light()
{
	led1=0;led2=0;led3=0;
}
void ssq()
{
	if(g==160)
	{
		g=0;
  }
 A=a[16];
	g++;
 c=g%16;
 A=a[c];
}
void main()
{
	Time0Int();
	while(1)
	{
	 light();
	}
 }
void Time0() interrupt 1
{
	 static u16 i;
	TH0=0XFC;
	TL0=0X18;
	i++;
	if(i==1000)
	{
	   i=0;
		 ssq();
		 
  }
	
	
}
    