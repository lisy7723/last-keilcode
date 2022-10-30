#include <reg52.h>
#define uchar unsigned char
#define uint  unsigned  int
code uchar seg7code[10]= {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
sbit ST=P3^6;
sbit OE=P3^7;
sbit EOC=P3^2;
sbit ALE=P3^3;
void delay(uchar t)
{
    while(t--);
}

void seg_disp(uchar n,uchar num,uchar dot)
{
    P0=0XFF;
    P2=0x01<<(n+4);
    P0=seg7code[num]&(~(dot<<7));
    delay(100);
}

void disp(uint num)
{
    seg_disp(0,num/1000,1);
    seg_disp(1,num%1000/100,0);
    seg_disp(2,num%100/10,0);
    seg_disp(3,num%100,0);
}

uint read_ADC0809(void)
{
    uint ADC_Value;
    OE=0;
    ST=0;
    ALE=0;
    ALE=1;
    ST=1;
    ALE=0;
    ST=0;
    delay(10);
    while(!EOC);
    OE=1;
    ADC_Value=P1;
    OE=0;
    return ADC_Value;
}

void main()
{
    while(1)
    {
        disp(read_ADC0809()*196/10);
    }
}
