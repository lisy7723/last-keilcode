#include "reg51.h"
#define uchar unsigned char
uchar code1[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
uchar T=20;
uchar now=0;
void init(){
	TMOD=0x01;
	TR0=1;
	ET0=1;
	EA=1;
	TH0=0x4B;
	TL0=0x00;
	SCON=0x00;
}
void time0Interrupt() interrupt 1{
	TH0=0x4B;
	TL0=0x00;
	if(--T) return;
	T=20;
	SBUF=now<10?code1[now++]:code1[now=0];
	while(!TI);
	TI=0;
}
int main(){
	init();
	while(1);
	return 0;
}


