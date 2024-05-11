/* =========================================================================

=========================================================================*/
#include <ny8.h>
#include "ny8_constant.h"
#include "Register.h"
#include "Initialize.h"
#include "Function.h"

#define UPDATE_REG(x)	__asm__("MOVR _" #x ",F")



//--------------- INTERRUPT SERVICE ROUTINE --------------------------------
void isr(void) __interrupt(0)
{
	if (INTFbits.T0IF)
	{
		TMR0 = TMR0_temp;
		//PORTB ^= 1;								// PB0 Toggle
		INTF = (unsigned char)~(C_INT_TMR0);	// Clear T0IF flag
		//flag1.T_flag =1;
	}
	
	if (INTFbits.T1IF)
	{
		//PORTB ^= 1;								// PB0 Toggle
		INTF = (unsigned char)~(C_INT_TMR1);	// Clear T1IF flag
		flag1.T_flag =1;
	}
}
	
void main(void)
{
// SYSTEM INITIALIZATION
	Initialize_GPIO();
	Initialize_RAM();
	//Initialize_Timer0();
	Initialize_Timer1();
	ENI();
    UPDATE_REG(PORTB);
    
    

     while(1)
    {
        CLRWDT();
		if(flag1.T_flag)		//100us
		{
			flag1.T_flag = 0;
			PORTB ^= 1;
			
			int_time1++;
			if(int_time1 == 200)	//20ms
			{
				int_time1 =0;
				Scan_key();
			}
		}

    }
}


//======================================
//按键扫描
void Scan_key(void)
{
	key_per = key_cur;	
	//key_cur = PORTB&0x20;			//高有效
	key_cur = (~PORTB)&0x20;		//低有效
		
	key_down = (~key_per) & key_cur;
	key_keep = key_per & key_cur;
	
	if(key_down & Key)
	{
		key_keep = 1;
	}
}

//=====================================
//按键长按	
void long_key_work(void)
{
	switch(long_star)
	{
	case 0:
		if(key_down & Key)	//有按键-按下
		{
			long_star = 1;
			long_time = 0;
		}
		break;
	
	case 1:
		if(key_keep & Key)	//长按计时
		{
			long_time++;
			if(long_time == 150) //20ms*150 =3s
			{
				long_time = 0;	//长按
				long_star = 2;
			}
		}
		else	//短按
		{
			long_star = 0;
		}
		break;
		
	default:
		if(!(key_keep & Key))	//等待-长按按键松开
		{
			long_star = 0;
		}
		break;
	}
}