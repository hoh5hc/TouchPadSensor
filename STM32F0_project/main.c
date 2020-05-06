#include "main.h"
#include "delay.h"
#include "IO_init.h"
#include "function.h"
uint8_t Padout[2];
uint8_t padnum=0,sign;

int main(void)
{
	if (SysTick_Config(SystemCoreClock / 1000))
  { 
    /* Capture error */ 
    while (1);
  }

led_init();	
TIM_Config();
TIM14_Config();	
	
  while (1)
  {
		switch (padnum ) 
	{	
case 0:
	if(sign==1)
  PadL_init();
	sign=0;
	pad_sense(GPIO_Pin_5,GPIO_Pin_6);
	 Cap_track();
  break;
case 1:
	if(sign==1)
  PadR_init();
	sign=0;
pad_sense(GPIO_Pin_6,GPIO_Pin_5);
	Cap_track();
  break;
default:
  break;
}
		sampletime();	
	
		GPIO_WriteBit(GPIOA, GPIO_Pin_2, Padout[0]);
		GPIO_WriteBit(GPIOA, GPIO_Pin_3, Padout[1]);
  }
	
	
}


