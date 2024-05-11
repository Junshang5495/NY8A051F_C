;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.2.2 #0 (MSVC)
;--------------------------------------------------------
; NY8A port
;--------------------------------------------------------
	.file	"main.c"
	list	p=NY8A051F,c=on
	#include "ny8a051f.inc"
	.debuginfo language C89
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
	extern	_clear_ram
	extern	_multi_16b
	extern	_T0MD
	extern	_PCON1
	extern	_BODCON
	extern	_PS0CV
	extern	_IOSTB
	extern	_OSCCR
	extern	_TBHD
	extern	_TBHP
	extern	_IRCR
	extern	_BZ1CR
	extern	_PS1CV
	extern	_PWM1DUTY
	extern	_T1CR2
	extern	_T1CR1
	extern	_TMR1
	extern	_PCHBUF
	extern	_FSR
	extern	_STATUS
	extern	_PCL
	extern	_TMR0
	extern	_INDF
	extern	_INTFbits
	extern	_INTEbits
	extern	_BPHCONbits
	extern	_BPLCONbits
	extern	_BWUCONbits
	extern	_PCONbits
	extern	_PORTBbits
	extern	__nyc_ny8_startup
;--------------------------------------------------------
; global declarations
;--------------------------------------------------------
	extern	_long_key_work
	extern	_main
	extern	_isr
	extern	_Sleep_Work
	extern	_Initialize_Timer1
	extern	_Initialize_Timer0
	extern	_INTF
	extern	_INTE
	extern	_BPHCON
	extern	_BPLCON
	extern	_BWUCON
	extern	_PCON
	extern	_PORTB
	extern	_flag1
	extern	_temp1
	extern	_sleep_time
	extern	_long_time
	extern	_long_star
	extern	_key_keep
	extern	_key_down
	extern	_key_per
	extern	_key_cur
	extern	_int_time2
	extern	_int_time1
	extern	_TMR_temp
	extern	_Initialize_GPIO
	extern	_Initialize_RAM
	extern	_Delay
	extern	_Scan_key

	extern PSAVE
	extern SSAVE
	extern WSAVE
	extern STK12
	extern ___STK12
	extern STK11
	extern ___STK11
	extern STK10
	extern ___STK10
	extern STK09
	extern ___STK09
	extern STK08
	extern ___STK08
	extern STK07
	extern ___STK07
	extern STK06
	extern ___STK06
	extern STK05
	extern ___STK05
	extern STK04
	extern ___STK04
	extern STK03
	extern ___STK03
	extern STK02
	extern ___STK02
	extern STK01
	extern ___STK01
	extern STK00
	extern ___STK00

.segment "share_bank"
PSAVE:
	.res 1
.segment "share_bank"
SSAVE:
	.res 1
.segment "share_bank"
WSAVE:
	.res 1
.segment "share_bank"
___STK12:
STK12:
	.res 1
.segment "share_bank"
___STK11:
STK11:
	.res 1
.segment "share_bank"
___STK10:
STK10:
	.res 1
.segment "share_bank"
___STK09:
STK09:
	.res 1
.segment "share_bank"
___STK08:
STK08:
	.res 1
.segment "share_bank"
___STK07:
STK07:
	.res 1
.segment "share_bank"
___STK06:
STK06:
	.res 1
.segment "share_bank"
___STK05:
STK05:
	.res 1
.segment "share_bank"
___STK04:
STK04:
	.res 1
.segment "share_bank"
___STK03:
STK03:
	.res 1
.segment "share_bank"
___STK02:
STK02:
	.res 1
.segment "share_bank"
___STK01:
STK01:
	.res 1
.segment "share_bank"
___STK00:
STK00:
	.res 1

;--------------------------------------------------------
; global definitions
;--------------------------------------------------------
.segment "uninit"
_TMR_temp:
	.res 1
	.debuginfo complex-type (symbol "_TMR_temp" 1 global "Register.h" 10 (basetype 1 unsigned))

.segment "uninit"
_int_time1:
	.res 1
	.debuginfo complex-type (symbol "_int_time1" 1 global "Register.h" 13 (basetype 1 unsigned))

.segment "uninit"
_int_time2:
	.res 1
	.debuginfo complex-type (symbol "_int_time2" 1 global "Register.h" 13 (basetype 1 unsigned))

.segment "uninit"
_key_cur:
	.res 1
	.debuginfo complex-type (symbol "_key_cur" 1 global "Register.h" 14 (basetype 1 unsigned))

.segment "uninit"
_key_per:
	.res 1
	.debuginfo complex-type (symbol "_key_per" 1 global "Register.h" 14 (basetype 1 unsigned))

.segment "uninit"
_key_down:
	.res 1
	.debuginfo complex-type (symbol "_key_down" 1 global "Register.h" 14 (basetype 1 unsigned))

.segment "uninit"
_key_keep:
	.res 1
	.debuginfo complex-type (symbol "_key_keep" 1 global "Register.h" 14 (basetype 1 unsigned))

.segment "uninit"
_long_star:
	.res 1
	.debuginfo complex-type (symbol "_long_star" 1 global "Register.h" 15 (basetype 1 unsigned))

.segment "uninit"
_long_time:
	.res 1
	.debuginfo complex-type (symbol "_long_time" 1 global "Register.h" 15 (basetype 1 unsigned))

.segment "uninit"
_sleep_time:
	.res 1
	.debuginfo complex-type (symbol "_sleep_time" 1 global "Register.h" 16 (basetype 1 unsigned))

.segment "uninit"
_flag1:
	.res 1
	.debuginfo complex-type (symbol "_flag1" 1 global "Register.h" 35 (struct "flag" (member "_T_flag" 0 "Register.h" 30 (bit 0 1)) (member "_ON_flag" 0 "Register.h" 31 (bit 1 1))))

;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
.segment "uninit", 0x2000003f
_temp1:
	.debuginfo complex-type (symbol "_temp1" 1 global "Register.h" 25 (basetype 1 unsigned))

	.res	1
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
.segment "uninit"
r0x100E:
	.res	1
.segment "uninit"
r0x100D:
	.res	1
.segment "uninit"
r0x100F:
	.res	1
.segment "uninit"
r0x1010:
	.res	1
.segment "uninit"
r0x1011:
	.res	1
.segment "uninit"
r0x100C:
	.res	1
.segment "uninit"
___sdcc_saved_fsr:
	.res	1
	.debuginfo complex-type (symbol "___sdcc_saved_fsr" 1 global "" 0 (basetype 1 unsigned))
.segment "uninit"
___sdcc_saved_stk00:
	.res	1
	.debuginfo complex-type (symbol "___sdcc_saved_stk00" 1 global "" 0 (basetype 1 unsigned))
.segment "uninit"
___sdcc_saved_stk01:
	.res	1
	.debuginfo complex-type (symbol "___sdcc_saved_stk01" 1 global "" 0 (basetype 1 unsigned))
;--------------------------------------------------------
; initialized data
;--------------------------------------------------------
;--------------------------------------------------------
; initialized absolute data
;--------------------------------------------------------
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;	udata_ovr
;--------------------------------------------------------
; reset vector 
;--------------------------------------------------------
ORG	0x0000
	LGOTO	__nyc_ny8_startup
;--------------------------------------------------------
; interrupt and initialization code
;--------------------------------------------------------
ORG 0x0008
	MGOTO	__sdcc_interrupt

.segment "code"
__sdcc_interrupt:
;***
;  pBlock Stats: dbName = I
;***
;2 compiler assigned registers:
;   STK00
;   STK01
;; Starting pCode block
_isr:
; 0 exit points
	.line	15, "main.c"; 	void isr(void) __interrupt(0)
	MOVAR	WSAVE
	SWAPR	STATUS,W
	CLRR	STATUS
	MOVAR	SSAVE
	MOVR	PCHBUF,W
	CLRR	PCHBUF
	MOVAR	PSAVE
	MOVR	FSR,W
	MOVAR	___sdcc_saved_fsr
	MOVR	STK00,W
	MOVAR	___sdcc_saved_stk00
	MOVR	STK01,W
	MOVAR	___sdcc_saved_stk01
	.line	17, "main.c"; 	if (INTFbits.T0IF)
	BTRSS	_INTFbits,0
	MGOTO	_02054_DS_
	.line	19, "main.c"; 	TMR0 = TMR0_temp;
	MOVIA	0xa2
	MOVAR	_TMR0
	.line	21, "main.c"; 	INTF = (unsigned char)~(C_INT_TMR0);	// Clear T0IF flag
	MOVIA	0xfe
	MOVAR	_INTF
_02054_DS_:
	.line	25, "main.c"; 	if (INTFbits.T1IF)
	BTRSS	_INTFbits,3
	MGOTO	_02057_DS_
	.line	28, "main.c"; 	INTF = (unsigned char)~(C_INT_TMR1);	// Clear T1IF flag
	MOVIA	0xf7
	MOVAR	_INTF
	.line	29, "main.c"; 	flag1.T_flag =1;
	BSR	_flag1,0
_02057_DS_:
	.line	31, "main.c"; 	}
	MOVR	___sdcc_saved_stk01,W
	MOVAR	STK01
	MOVR	___sdcc_saved_stk00,W
	MOVAR	STK00
	MOVR	___sdcc_saved_fsr,W
	MOVAR	FSR
	MOVR	PSAVE,W
	MOVAR	PCHBUF
	CLRR	STATUS
	SWAPR	SSAVE,W
	MOVAR	STATUS
	SWAPR	WSAVE,F
	SWAPR	WSAVE,W
END_OF_INTERRUPT:
	RETIE	

;--------------------------------------------------------
; code
;--------------------------------------------------------
; code_main	code
;***
;  pBlock Stats: dbName = M
;***
;has an exit
;functions called:
;   _Initialize_GPIO
;   _Initialize_RAM
;   _Initialize_Timer1
;   _Scan_key
;   _Initialize_GPIO
;   _Initialize_RAM
;   _Initialize_Timer1
;   _Scan_key
;; Starting pCode block
.segment "code"; module=main, function=_main
	.debuginfo subprogram _main
_main:
; 2 exit points
	.line	36, "main.c"; 	Initialize_GPIO();
	MCALL	_Initialize_GPIO
	.line	37, "main.c"; 	Initialize_RAM();
	MCALL	_Initialize_RAM
	.line	39, "main.c"; 	Initialize_Timer1();
	MCALL	_Initialize_Timer1
	.line	40, "main.c"; 	ENI();
	ENI
	.line	41, "main.c"; 	UPDATE_REG(PORTB);
	MOVR	_PORTB,F
_02067_DS_:
	.line	47, "main.c"; 	CLRWDT();
	clrwdt
	.line	48, "main.c"; 	if(flag1.T_flag)		//100us
	BTRSS	_flag1,0
	MGOTO	_02067_DS_
	.line	50, "main.c"; 	flag1.T_flag = 0;
	BCR	_flag1,0
	.line	51, "main.c"; 	PORTB ^= 1;
	MOVIA	0x01
	XORAR	_PORTB,F
	.line	53, "main.c"; 	int_time1++;
	INCR	_int_time1,F
	.line	54, "main.c"; 	if(int_time1 == 200)	//20ms
	MOVR	_int_time1,W
	XORIA	0xc8
	BTRSS	STATUS,2
	MGOTO	_02067_DS_
	.line	56, "main.c"; 	int_time1 =0;
	CLRR	_int_time1
	.line	57, "main.c"; 	Scan_key();
	MCALL	_Scan_key
	MGOTO	_02067_DS_
	.line	62, "main.c"; 	}
	RETURN	
; exit point of _main

;***
;  pBlock Stats: dbName = C
;***
;has an exit
;; Starting pCode block
.segment "code"; module=main, function=_long_key_work
	.debuginfo subprogram _long_key_work
_long_key_work:
; 2 exit points
	.line	86, "main.c"; 	switch(long_star)
	MOVR	_long_star,W
	BTRSC	STATUS,2
	MGOTO	_02079_DS_
	MOVR	_long_star,W
	XORIA	0x01
	BTRSC	STATUS,2
	MGOTO	_02082_DS_
	MGOTO	_02088_DS_
_02079_DS_:
	.line	89, "main.c"; 	if(key_down & Key)	//有按键-按下
	BTRSS	_key_down,5
	MGOTO	_02092_DS_
	.line	91, "main.c"; 	long_star = 1;
	MOVIA	0x01
	MOVAR	_long_star
	.line	92, "main.c"; 	long_time = 0;
	CLRR	_long_time
	.line	94, "main.c"; 	break;
	MGOTO	_02092_DS_
_02082_DS_:
	.line	97, "main.c"; 	if(key_keep & Key)	//长按计时
	BTRSS	_key_keep,5
	MGOTO	_02086_DS_
	.line	99, "main.c"; 	long_time++;
	INCR	_long_time,F
	.line	100, "main.c"; 	if(long_time == 150) //20ms*150 =3s
	MOVR	_long_time,W
	XORIA	0x96
	BTRSS	STATUS,2
	MGOTO	_02092_DS_
	.line	102, "main.c"; 	long_time = 0;	//长按
	CLRR	_long_time
	.line	103, "main.c"; 	long_star = 2;
	MOVIA	0x02
	MOVAR	_long_star
	MGOTO	_02092_DS_
_02086_DS_:
	.line	108, "main.c"; 	long_star = 0;
	CLRR	_long_star
	.line	110, "main.c"; 	break;
	MGOTO	_02092_DS_
_02088_DS_:
	.line	113, "main.c"; 	if(!(key_keep & Key))	//等待-长按按键松开
	BTRSC	_key_keep,5
	MGOTO	_02092_DS_
	.line	115, "main.c"; 	long_star = 0;
	CLRR	_long_star
_02092_DS_:
	.line	119, "main.c"; 	}
	RETURN	
; exit point of _long_key_work

;***
;  pBlock Stats: dbName = C
;***
;has an exit
;1 compiler assigned register :
;   r0x100C
;; Starting pCode block
.segment "code"; module=main, function=_Scan_key
	.debuginfo subprogram _Scan_key
_Scan_key:
; 2 exit points
	.line	69, "main.c"; 	key_per = key_cur;	
	MOVR	_key_cur,W
	MOVAR	_key_per
	.line	71, "main.c"; 	key_cur = (~PORTB)&0x20;		//低有效
	COMR	_PORTB,W
	MOVAR	r0x100C
	MOVIA	0x20
	ANDAR	r0x100C,W
	MOVAR	_key_cur
	.line	73, "main.c"; 	key_down = (~key_per) & key_cur;
	COMR	_key_per,W
	MOVAR	r0x100C
	MOVR	_key_cur,W
	ANDAR	r0x100C,W
	MOVAR	_key_down
	.line	74, "main.c"; 	key_keep = key_per & key_cur;
	MOVR	_key_cur,W
	ANDAR	_key_per,W
	MOVAR	_key_keep
	.line	76, "main.c"; 	if(key_down & Key)
	BTRSS	_key_down,5
	MGOTO	_02074_DS_
	.line	78, "main.c"; 	key_keep = 1;
	MOVIA	0x01
	MOVAR	_key_keep
_02074_DS_:
	.line	80, "main.c"; 	}
	RETURN	
; exit point of _Scan_key

;***
;  pBlock Stats: dbName = C
;***
;has an exit
;6 compiler assigned registers:
;   r0x100D
;   STK00
;   r0x100E
;   r0x100F
;   r0x1010
;   r0x1011
;; Starting pCode block
.segment "code"; module=main, function=_Delay
	.debuginfo subprogram _Delay
;local variable name mapping:
	.debuginfo complex-type (local-sym "_count" 2 "Function.h" 46 (basetype 2 signed) split "r0x100E" "r0x100D")
	.debuginfo complex-type (local-sym "_i" 2 "Function.h" 48 (basetype 2 signed) split "r0x100F" "r0x1010")
_Delay:
; 2 exit points
	.line	46, "Function.h"; 	void Delay(int count)
	MOVAR	r0x100D
	MOVR	STK00,W
	MOVAR	r0x100E
	.line	49, "Function.h"; 	for (i = 1; i <= count; i++)
	MOVIA	0x01
	MOVAR	r0x100F
	CLRR	r0x1010
_02035_DS_:
	MOVR	r0x100D,W
	ADDIA	0x80
	MOVAR	r0x1011
	MOVR	r0x1010,W
	ADDIA	0x80
	SUBAR	r0x1011,W
	BTRSS	STATUS,2
	MGOTO	_02048_DS_
	MOVR	r0x100F,W
	SUBAR	r0x100E,W
_02048_DS_:
	BTRSS	STATUS,0
	MGOTO	_02037_DS_
	INCR	r0x100F,F
	BTRSC	STATUS,2
	INCR	r0x1010,F
	MGOTO	_02035_DS_
_02037_DS_:
	.line	51, "Function.h"; 	}
	RETURN	
; exit point of _Delay

;***
;  pBlock Stats: dbName = C
;***
;has an exit
;; Starting pCode block
.segment "code"; module=main, function=_Sleep_Work
	.debuginfo subprogram _Sleep_Work
_Sleep_Work:
; 2 exit points
	.line	18, "Function.h"; 	if(!flag1.ON_flag)
	BTRSC	_flag1,1
	MGOTO	_02026_DS_
	.line	20, "Function.h"; 	sleep_time++;
	INCR	_sleep_time,F
	.line	21, "Function.h"; 	if(sleep_time==10)
	MOVR	_sleep_time,W
	XORIA	0x0a
	BTRSS	STATUS,2
	MGOTO	_02028_DS_
	.line	23, "Function.h"; 	sleep_time = 0;
	CLRR	_sleep_time
	.line	24, "Function.h"; 	DISI();
	DISI
	.line	26, "Function.h"; 	PCON = 0x00;
	CLRR	_PCON
	.line	27, "Function.h"; 	INTE = C_INT_PBKey;
	MOVIA	0x02
	MOVAR	_INTE
	.line	28, "Function.h"; 	INTF = 0;	
	CLRR	_INTF
	.line	29, "Function.h"; 	SLEEP();
	sleep
	.line	30, "Function.h"; 	INTE = 0;
	CLRR	_INTE
	.line	31, "Function.h"; 	INTF = 0;	
	CLRR	_INTF
	.line	32, "Function.h"; 	INTE |= C_INT_TMR0;
	BSR	_INTE,0
	.line	34, "Function.h"; 	PCON = 0x88;
	MOVIA	0x88
	MOVAR	_PCON
	.line	35, "Function.h"; 	ENI();
	ENI
	MGOTO	_02028_DS_
_02026_DS_:
	.line	39, "Function.h"; 	sleep_time = 0;	
	CLRR	_sleep_time
_02028_DS_:
	.line	40, "Function.h"; 	}
	RETURN	
; exit point of _Sleep_Work

;***
;  pBlock Stats: dbName = C
;***
;has an exit
;; Starting pCode block
.segment "code"; module=main, function=_Initialize_RAM
	.debuginfo subprogram _Initialize_RAM
_Initialize_RAM:
; 2 exit points
	.line	47, "Initialize.h"; 	for(temp1=0x10;temp1<0x3C;temp1++)
	MOVIA	0x10
	MOVAR	_temp1
_02018_DS_:
	.line	49, "Initialize.h"; 	FSR =temp1;
	MOVR	_temp1,W
	MOVAR	_FSR
	.line	50, "Initialize.h"; 	INDF =0x00;
	CLRR	_INDF
	.line	47, "Initialize.h"; 	for(temp1=0x10;temp1<0x3C;temp1++)
	INCR	_temp1,F
;;unsigned compare: left < lit(0x3C=60), size=1
	MOVIA	0x3c
	SUBAR	_temp1,W
	BTRSS	STATUS,0
	MGOTO	_02018_DS_
	.line	52, "Initialize.h"; 	}
	RETURN	
; exit point of _Initialize_RAM

;***
;  pBlock Stats: dbName = C
;***
;has an exit
;; Starting pCode block
.segment "code"; module=main, function=_Initialize_Timer1
	.debuginfo subprogram _Initialize_Timer1
_Initialize_Timer1:
; 2 exit points
	.line	38, "Initialize.h"; 	TMR1 = 99;
	MOVIA	0x63
	SFUN	_TMR1
	.line	39, "Initialize.h"; 	T1CR1 = C_TMR1_Reload | C_TMR1_En;
	MOVIA	0x03
	SFUN	_T1CR1
	.line	40, "Initialize.h"; 	T1CR2 = C_TMR1_ClkSrc_Inst | C_PS1_Div2;
	CLRA	
	SFUN	_T1CR2
	.line	41, "Initialize.h"; 	INTE |= C_INT_TMR1;
	BSR	_INTE,3
	.line	42, "Initialize.h"; 	}
	RETURN	
; exit point of _Initialize_Timer1

;***
;  pBlock Stats: dbName = C
;***
;has an exit
;; Starting pCode block
.segment "code"; module=main, function=_Initialize_Timer0
	.debuginfo subprogram _Initialize_Timer0
_Initialize_Timer0:
; 2 exit points
	.line	28, "Initialize.h"; 	TMR0 = TMR0_temp;
	MOVIA	0xa2
	MOVAR	_TMR0
	.line	29, "Initialize.h"; 	T0MD = C_PS0_TMR0 | C_PS0_Div4;
	MOVIA	0x01
	T0MD	
	.line	31, "Initialize.h"; 	INTE |= C_INT_TMR0;
	BSR	_INTE,0
	.line	32, "Initialize.h"; 	}
	RETURN	
; exit point of _Initialize_Timer0

;***
;  pBlock Stats: dbName = C
;***
;has an exit
;; Starting pCode block
.segment "code"; module=main, function=_Initialize_GPIO
	.debuginfo subprogram _Initialize_GPIO
_Initialize_GPIO:
; 2 exit points
	.line	16, "Initialize.h"; 	BPHCON = (unsigned char) ~( C_PB3_PHB | C_PB2_PHB);
	MOVIA	0xf3
	MOVAR	_BPHCON
	.line	17, "Initialize.h"; 	IOSTB = C_PB3_Input | C_PB2_Input;
	MOVIA	0x0c
	IOST	_IOSTB
	.line	18, "Initialize.h"; 	PORTB =	0xFF;
	MOVIA	0xff
	MOVAR	_PORTB
	.line	19, "Initialize.h"; 	BWUCON = 0x00;
	CLRR	_BWUCON
	.line	20, "Initialize.h"; 	}
	RETURN	
; exit point of _Initialize_GPIO


;	code size estimation:
;	  182+    0 =   182 instructions (  364 byte)

	end
