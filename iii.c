#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
#define outscan P1 
#define out P2

uchar code1[16]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
void delay(uint j){
	uchar i;
	for(;j>0;j--){
	 i=250;
   while(--i);
	 i=249;
 	 while(--i);
  }
}
uchar scan(){
    uchar p=16;
    uchar m,n,in;
    outscan=0xf0;
    if((outscan&0xf0)!=0xf0){
        for(m=0;m<4;m++){
            outscan=~(0x01<<m);
            for(n=0;n<4;n++){
                in=outscan;             
                in=in>>(4+n);
                if((in&0x01)==0){
                    delay(10);
                    if((in&0x01)==0){p=n+m*4;break;}
                }
						}
	 	    if(p!=16){break;}
		    }
    }
		return p;
}
int main(){
	uchar p;
	while(1){
		p=scan();
		if(p!=16) out=code1[p];
	}
}