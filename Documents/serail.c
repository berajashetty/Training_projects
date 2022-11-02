#include<reg51.h>

#define baud_rate 0xFA
bit bTx_flag=0;
void main(void);
//void SerialIntialize(void);
void SendByteSerially(unsigned char ascii);
char * string="Hello Bosch";


void ser_int() interrupt 4
{
	
	if(TI)
	{
		bTx_flag=1;
		TI=0;
	}
	
	
}
void main(void)
{
//unsigned char serialdata;
	EA=1;
	ES=1;
	TMOD=((TMOD&0x0F)|0x20);
SCON=0x50;
TH1=baud_rate;
TR1=1;

	while(1)
	{
		while(*string)
		{
		SBUF=*string++;
		while(bTx_flag==0);
		bTx_flag=0;
		}
}
}
/*void sendByteSerially(unsigned char serialdata)
{
SBUF=serialdata;
while(TI==0);
TI=0;
}

unsigned char RecieveByteSerially(void)
{
while(RI==0);
RI=0;
return SBUF;
}*/



