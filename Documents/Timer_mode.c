#include <REG52.h>

#define TIMER0_VALUE_25msec 0xA5FF
#define TIMER0_H ((TIMER0_VALUE_25msec & 0XFF00)>>8)
#define TIMER0_L ((TIMER0_VALUE_25msec & 0X00FF)
 
 sbit led0=P1^0;
 //sbit led1=P1^1;
 
 void timer0_interrupt() interrupt 3
{
	 unsigned int i;
   TH0= TIMER0_H;
   TL0= TIMER0_L;
	 if (i==0)
	 {
		i=0;
		led0=~led0; 
    }	
		else
		i++;
	}
 
 
 void main()
 {
 int cnt=0;
 TMOD = 0x01;
	 
  TH0= TIMER0_H;
  TL0= TIMER0_L;
 //TH1 =  0XA5;
 //TL1 =  0XFF;
 
 TH0 =  0XA5;
 TL0 =  0XFF;
	 
	 EA=1;
	 ET0=1;
	 TR0=1;
		while(1)
		{
		
		//while(TF0==0);
		if(TF0==1)
		{
		TF0=0;
		TH0= 0xA5;
		TL0= 0xFF;
		cnt++;
		if (cnt=40)
			{
		cnt=0;
		led0=~led0;
			}
		}
		
		/*if(TF1==1)
		{
		TF1=0;
		TH1= 0xA5;
		TL1= 0xFF;
		cnt2++;
		if (cnt2==120)
			{
		cnt2=0;
		led1=~led1;
      }
    }*/
     }
 }

