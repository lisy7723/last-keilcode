#include "reg51.h"
#define uchar unsigned char
#define out P0
#define outcom P3
int n=0;
sbit jia=P1^0;
sbit jian=P1^1;
int num=0;
int cnum;
int i=0;
int j=0;
uchar code1[16]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
void init(){
    TMOD=0x01;
    TR0=1;
    ET0=1;
    EA=1;
    TH0=0x3C;
    TL0=0XAF;
}

int main(){
 init();
 while(1){
        if(jia==0){
            if(num<99){
                num++;
            }else{
                num=0;
            }
      while(1){
                if(jia==1) break;
            }
        }
        if(jian==0){
            if(num>0){
                num--;
            }else{
                num=99;
            }
   while(1){
                if(jian==1) break;
            }
        }
    }
 return 0;
}
void timeInterrupt() interrupt 2{
    TH0=0x3C;
    TL0=0XAF;
    outcom=(0x01<<n);//00000001  00000001 n=0
    cnum=num;
    for(i=0;i<n;i++){
        cnum/=10;
    }
    cnum%=10;
    out=code1[cnum];
  n=!n;
}