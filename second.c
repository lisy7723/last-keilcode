#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
#define out P2
#define outk P1 
uchar code1[16]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
void delayms(uint j){
uchar i;
for(;j>0;j--)
  	{
	 i=250;
   	 while(--i);
   	 i=249;
   	 while(--i);
   	}
}
uchar scan(){
    uchar k=16;
    uchar m,n,in;
    outk=0xf0;
    if((outk&0xf0)!=0xf0){
        for(m=0;m<4;m++){
            outk=~(0x01<<m);
            for(n=0;n<4;n++){
                in=outk;             
                in=in>>(4+n);
                if((in&0x01)==0){
                    delayms(10);
                    if((in&0x01)==0){k=n+m*4;break;}
                }
						}
	 	    if(k!=16){break;}
		    }
    }
		return k;
}
void main(void)
{
uchar key;
while(1)
	{
	key=scan();if(key!=16)out=code1[key];
	}
}