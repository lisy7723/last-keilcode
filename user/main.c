#include "stm32f10x.h"
GPIO_InitTypeDef GPIO_InitStructure;
void delay(uint32_t time)
{
	uint32_t i,j;
	for(j=0;j<time;j++)
	for(i=0;i<10000;i++);
}
uint32_t i;
int main(void)
{
  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIOC->BSRR=0xff;
	while (1)
	{
	  for(i=0;i<8;i++)
	  {
		GPIOC->BRR=(1<<i);
		delay(100);
		GPIOC->BSRR=(1<<i);
	  }
	}
}