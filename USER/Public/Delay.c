#include "Delay.h"
 

//��ʱ��us
void Delay_us(u16 us)
{
	u32 tt;
	while (us--)
	{
		tt = 24; 
		while (tt--)
			;
	}
}

//��ʱ��ms
void Delay_ms(u16 msNum)
{
	u32 tt;
	while (msNum--)
	{
		tt = 24000; //168000
		while (tt--)
			;
	}
}

//��ʱ����
void Delay_s(float time_s)
{
	u32 time_int = (u32) (time_s * 1000.0);
	Delay_ms(time_int);	
}

