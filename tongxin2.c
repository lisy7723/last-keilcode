#include "reg51.h"
#define uchar unsigned char
#define out P1
uchar out1[16];
uchar i=0,j=0;
uchar T=20;
void init(){
	TMOD=0x21;
	PCON=0x00;
	EA=1;
	TH1=0xFA;
	TL1=0xFA;
	TH0=0x4B;
	TL0=0x00;
	SCON=0xD0;
	ES=1;
	TR1=1;
	TR0=0;
	ET0=0;
	RI=0;
}
void chuanInterrupt()interrupt 4{
	if(RI){
		out1[i++]=SBUF;
		RI=0;
	}
}
void timeInterrupt()interrupt 1{
	TH0=0x4B;
	TL0=0x00;
	if(--T) return;
	T=20;
	out=j<16?out1[j++]:out1[j=0];
}
int main(){
	init();
	while(1){
		if(i>15){
			TR0=1;
			ET0=1;
		}
	}
	return 0;
}