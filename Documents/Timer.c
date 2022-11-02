
#include <REG52.h>

#define TIMER0_VALUE_25msec 0xA5FF
#define TIMER0_H ((TIMER0_VALUE_25msec & 0XFF00)>>8)
#define TIMER0_L ((TIMER0_VALUE_25msec & 0X00FF)
 
 sbit led0=P1^0;
 
 
 
 void main()
 {
 int cnt=0;
 TMOD = 0x01;
 TH0 =  0XA5;
 TL0 =  0XFF;
 
 TR0=1;
		while(1)
		{
		
		//while(TF0==0);
		if(TF0==1)
		{
		TF0=0;
		TH0= 0xA5;
		TL0= 0xFF;
		//cnt++;
		if (cnt==40){

		led0=~led0;
			cnt=0;
		}
		}
      }
 }

