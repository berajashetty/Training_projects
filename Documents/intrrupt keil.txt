#include<reg51.h>

sbit led_main= P0^0;
sbit led_intr0= P0^1;
sbit led_intr1= P0^2;

//#define LED P0

delay()
{
int i;
for (i=0;i<1000;i++);
}
void intr0_external() interrupt 0
{
	 led_intr0=0;
	 delay();
	 led_intr0=1;
	 delay();
}

void intr1_external() interrupt 2
{
	 led_intr1=0;
	 delay();
	 led_intr1=1;
	 delay();
}

void main()
{
		EA=1;
		EX0=1;
		IT0=1;
	
 while(1)
	{
	  led_main =0;
		delay();
		led_main=1;
		delay();
	}
}


