﻿/*
ADC_Detection_mode		ADC-n通道-轮询检测
ADC_algorithm			ADC算法，(10次-min-max)/8
ADC_Wait				ADC转换
Delay					延时
Sleep_Work				睡眠

*/

void Delay(int);
void Scan_key(void);


//====================================================
//睡眠
void Sleep_Work(void)
{
	if(!flag1.ON_flag)
	{
		sleep_time++;
		if(sleep_time==10)
		{
			sleep_time = 0;
			DISI();
			//PCONbits.WDTEN = 0;
			PCON = 0x00;
			INTE = C_INT_PBKey;
			INTF = 0;	
			SLEEP();
			INTE = 0;
			INTF = 0;	
			INTE |= C_INT_TMR0;
			//PCONbits.WDTEN = 1;
			PCON = 0x88;
			ENI();
		}
	}
	else
		sleep_time = 0;	
}



// --------------------------------------------------------------------------
// SUBROUTINE of TIME DELAY
void Delay(int count)
{
	int i;
	for (i = 1; i <= count; i++)
	;
}