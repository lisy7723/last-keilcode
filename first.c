#include "reg51.h"
#define uchar unsigned char
#define uint unsigned int
#define out P1
int mode[8] = { 0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80 };
int p = 0;
int time = 20;
void init() {
	TMOD = 0x01;
	TR0 = 1;
	ET0 = 1;
	EA = 1;
	TH0 = 0x4B;
	TL0 = 0x00;
}
void time0Interrupt() interrupt 1{
	TH0 = 0x4B;
	TL0 = 0x00;
	if (--time) return;
	time = 20;
	out = mode[p = ++p % 8];
}
int main(){
    init();
	while (1);
	return 0;
}