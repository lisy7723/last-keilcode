#include "reg51.h"
#define uchar unsigned char
#define out1 P0
#define out2 P2
sbit jia=P1^0;
sbit jian=P1^1;
int num=0;
int i=0;
int j=0;
uchar code1[16]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
void init(){

}
void delay(uchar time){
    for(i=time;i>0;i--)
    for(j=255;j>0;j--);
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
        out1=code1[num/10];
        out2=code1[num%10];
    }
    return 0;
}