#include <REGX52.H>

typedef unsigned int u16;
typedef unsigned char u8;

sbit L1=P0^0;
sbit K1=P3^2;
sbit K2=P3^3;

void delay1ms(void)
{
    unsigned char a,b,c;
    for(c=1;c>0;c--)
        for(b=142;b>0;b--)
            for(a=2;a>0;a--);
}

void delay(u16 n)
{
	while(n--)
	{
		delay1ms();
	}
}

void exti0_init(void)
{
	IT0=1;//�����ⲿ�жϵĴ�����ʽ
	EX0=1;//���ⲿ�ж�0
	EA=1;//�����жϿ���
}

void exti1_init(void)
{
	IT1=1;//�����ⲿ�жϵĴ�����ʽ
	EX1=1;//���ⲿ�ж�0
	EA=1;//�����жϿ���
}

void exti0() interrupt 0
{
	delay(10);
	if(K1==0)
	{
		L1=!L1;
	}
}

void exti1() interrupt 2
{
	delay(10);
	if(K2==0)
	{
		L1=!L1;
	}
}

void main()
{
	
	exti1_init();
	while(1)
	{
		
	}
}