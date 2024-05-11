/*
;Initialize_GPIO
;Initialize_Timer0
;Initialize_FSR

*/


void Initialize_GPIO(void);
void Initialize_RAM(void);

//==================================
void Initialize_GPIO(void)
{	
//
	BPHCON = (unsigned char) ~( C_PB3_PHB | C_PB2_PHB);
	IOSTB = C_PB3_Input | C_PB2_Input;
	PORTB =	0xFF;
	BWUCON = 0x00;
}

//==================================
//T=(256-TMR0)*分频/Fcpu
//TMR =256-(T-7)*Fcpu/分频
#define TMR0_temp 256-(100-6)*4/4
void Initialize_Timer0(void)
{
	TMR0 = TMR0_temp;
	T0MD = C_PS0_TMR0 | C_PS0_Div4;
	//T0MD = C_TMR0_LowClk | C_TMR0_Clk | C_PS0_Div4;	//外部晶振 频率=32768/256/分频
	INTE |= C_INT_TMR0;
}

//==================================
//Timer1=Tcpu*分频*TMR1
void Initialize_Timer1(void)
{
	TMR1 = 99;
	T1CR1 = C_TMR1_Reload | C_TMR1_En;
	T1CR2 = C_TMR1_ClkSrc_Inst | C_PS1_Div2;
	INTE |= C_INT_TMR1;
}

//==================================
void Initialize_RAM(void)
{
	for(temp1=0x10;temp1<0x3C;temp1++)
	{
		FSR =temp1;
		INDF =0x00;
	}
}










