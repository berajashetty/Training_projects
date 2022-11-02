#include<reg51.h>

sbit led_main= P1^0;
sbit led_intr0= P1^1;
sbit led_intr1= P1^2;

//#define LED P0

void delay()
	{
	int i,j;
	for (i=0;i<10;i++){
	for (j=0;j<1000;j++);
		
	} 
}
	

/*void intr0_external() interrupt 0
{ 
	int j;
	for(j=0;j<3;j++){
	 led_intr0=0;
	 delay();
	 led_intr0=1;
	 delay();
	}
} */

void intr1_external() interrupt 2
{ 
		int j;
		for(j=0;j<5;j++){
		 led_intr1=0;
		 delay();
		 led_intr1=1;
		 delay();
	}
}
 main()
 {
		EA=1;
		EX0=1;
	  EX1=1;
	  IT1=1;
		IT0=1;
	
 while(1)
	{
	  led_main =0;
		delay();
		led_main=1;
		delay();
	}
 }