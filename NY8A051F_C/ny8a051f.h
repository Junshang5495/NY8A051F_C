/*!
 * \file       ny8a051f.h
 * \brief      NY8A051F header file
 * \author     HuangTing
 * \date       2023.03.01
 * \details    define register
 */

#ifndef NY8A051F_H_ZC3DOMIF
#define NY8A051F_H_ZC3DOMIF

#ifndef __CPU_HAS_SET
#  ifdef __SDCC
#    warning "Use NY8.h instead of <icbody>.h for consistency."
#  endif
#endif

#include <ny8common.h>

// R-Page special function register {{{
extern __at(0x0000) __sfr INDF;
//! TMR0 (Timer0 Register)
extern __at(0x0001) __sfr TMR0;

//! PCL (Low Byte of PC[9:0])
extern __at(0x0002) __sfr PCL;

//! STATUS (Status Register)
/**
 * |---------------+------+------+------+------+------+------+------+------|
 * |               | Bit7 | Bit6 | Bit5 | Bit4 | Bit3 | Bit2 | Bit1 | Bit0 |
 * |---------------+------+------+------+------+------+------+------+------|
 * |               | GP7  | GP6  | GP5  | /TO  | /PD  | Z    | DC   | C    |
 * |---------------+------+------+------+------+------+------+------+------|
 * | R/W Property  | R/W  | R/W  | R/W  | R/W  | R/W  | R/W  | R/W  | R/W  |
 * |---------------+------+------+------+------+------+------+------+------|
 * | Initial Value | 0    | 0    | 0    | 1    | 1    | X    | X    | X    |
 * |---------------+------+------+------+------+------+------+------+------|
 *
 */
extern __at(0x0003) __sfr STATUS;
extern __at(0x0004) __sfr FSR;
typedef struct __PORTBbits_t
{
    unsigned PB0    : 1;
    unsigned PB1    : 1;
    unsigned PB2    : 1;
    unsigned PB3    : 1;
    unsigned PB4    : 1;
    unsigned PB5    : 1;
    unsigned GP6    : 1;
    unsigned GP7    : 1;
} __PORTBbits_t;

//! PortB (PortB Data Register)
extern __at(0x0006) __sfr PORTB;
extern __at(0x0006) volatile __PORTBbits_t PORTBbits; //!< PortB Data Register
__sbit PB0 = PORTB : 0;
__sbit PB1 = PORTB : 1;
__sbit PB2 = PORTB : 2;
__sbit PB3 = PORTB : 3;
__sbit PB4 = PORTB : 4;
__sbit PB5 = PORTB : 5;

typedef struct __PCONbits_t
{
    unsigned GP0    : 1;
    unsigned GP1    : 1;
    unsigned GP2    : 1;
    unsigned LVREN  : 1;
    unsigned GP4    : 1;
    unsigned LVDEN  : 1;
    unsigned EIS    : 1;
    unsigned WDTEN  : 1;
} __PCONbits_t;

//! PCON (Power Control Register)
extern __at(0x0008) __sfr PCON;
extern __at(0x0008) volatile __PCONbits_t PCONbits; //!< PCON (Power Control Register)
__sbit LVREN = PCON : 3;
__sbit LVDEN = PCON : 5;
__sbit EIS   = PCON : 6;
__sbit WDTEN = PCON : 7;

typedef struct __BWUCONbits_t
{
    unsigned WUPB0  : 1;
    unsigned WUPB1  : 1;
    unsigned WUPB2  : 1;
    unsigned WUPB3  : 1;
    unsigned WUPB4  : 1;
    unsigned WUPB5  : 1;
    unsigned        : 1;
    unsigned        : 1;
} __BWUCONbits_t;

//! BWUCON (PortB Wake-up Control Register)
extern __at(0x0009) __sfr BWUCON;
extern __at(0x0009) volatile __BWUCONbits_t BWUCONbits; //!< BWUCON (PortB Wake-up Control Register)
__sbit WUPB0 = BWUCON : 0;
__sbit WUPB1 = BWUCON : 1;
__sbit WUPB2 = BWUCON : 2;
__sbit WUPB3 = BWUCON : 3;
__sbit WUPB4 = BWUCON : 4;
__sbit WUPB5 = BWUCON : 5;

//! PCHBUF (High Byte of PC)
/**
 * PCHBUF[1:0]: Buffer of the 9th bit, 8th bit of PC
 *
 * |---------------+------+------+------+------+------+------+------+------|
 * |               | Bit7 | Bit6 | Bit5 | Bit4 | Bit3 | Bit2 | Bit1 | Bit0 |
 * |---------------+------+------+------+------+------+------+-------------|
 * |               | -    | -    | -    | -    | -    | GP2  | PCHBUF[1:0] |
 * |---------------+------+------+------+------+------+--------------------|
 * | R/W Property  | -    | -    | -    | -    | -    |        R/W         |
 * |---------------+------+------+------+------+------+--------------------|
 * | Initial Value | X    | X    | X    | X    | X    |        000         |
 * |---------------+------+------+------+------+------+--------------------|
 *
 */
extern __at(0x000a) __sfr PCHBUF;

typedef struct __BPLCONbits_t
{
    unsigned        : 1;
    unsigned        : 1;
    unsigned        : 1;
    unsigned        : 1;
    unsigned PLPB0  : 1;
    unsigned PLPB1  : 1;
    unsigned PLPB2  : 1;
    unsigned PLPB3  : 1;
} __BPLCONbits_t;

//! BPLCON (PortB Pull-Low Resistor Control Register)
/**
 * |---------------+--------+--------+--------+--------+------+------+------+------|
 * |               | Bit7   | Bit6   | Bit5   | Bit4   | Bit3 | Bit2 | Bit1 | Bit0 |
 * |---------------+--------+--------+--------+--------+------+------+------+------|
 * |               | /PLPB3 | /PLPB2 | /PLPB1 | /PLPB0 | -    | -    | -    | -    |
 * |---------------+--------+--------+--------+--------+------+------+------+------|
 * | R/W Property  | R/W    | R/W    | R/W    | R/W    | -    | -    | -    | -    |
 * |---------------+--------+--------+--------+--------+------+------+------+------|
 * | Initial Value | 1      | 1      | 1      | 1      | 1    | 1    | 1    | 1    |
 * |---------------+--------+--------+--------+--------+------+------+------+------|
 *
 */
extern __at(0x000b) __sfr BPLCON;
extern __at(0x000b) volatile __BPLCONbits_t BPLCONbits; //!< BPLCON (PortB Pull-Low Resistor Control Register)
__sbit PLPB0 = BPLCON : 4;
__sbit PLPB1 = BPLCON : 5;
__sbit PLPB2 = BPLCON : 6;
__sbit PLPB3 = BPLCON : 7;

typedef struct __BPHCONbits_t
{
    unsigned PHPB0  : 1;
    unsigned PHPB1  : 1;
    unsigned PHPB2  : 1;
    unsigned PHPB3  : 1;
    unsigned PHPB4  : 1;
    unsigned PHPB5  : 1;
    unsigned        : 1;
    unsigned        : 1;
} __BPHCONbits_t;

//! BPHCON (PortB Pull-High Resistor Control Register)
/**
 * |---------------+------+------+--------+--------+--------+--------+--------+--------|
 * |               | Bit7 | Bit6 | Bit5   | Bit4   | Bit3   | Bit2   | Bit1   | Bit0   |
 * |---------------+------+------+--------+--------+--------+--------+--------+--------|
 * |               | -    | -    | /PHPB5 | /PHPB4 | /PHPB3 | /PHPB2 | /PHPB1 | /PHPB0 |
 * |---------------+------+------+--------+--------+--------+--------+--------+--------|
 * | R/W Property  | -    | -    | R/W    | R/W    | R/W    | R/W    | R/W    | R/W    |
 * |---------------+------+------+--------+--------+--------+--------+--------+--------|
 * | Initial Value | 0    | 0    | 1      | 1      | 1      | 1      | 1      | 1      |
 * |---------------+------+------+--------+--------+--------+--------+--------+--------|
 *
 */
extern __at(0x000c) __sfr BPHCON;
extern __at(0x000c) volatile __BPHCONbits_t BPHCONbits; //!< BPHCON (PortB Pull-High Resistor Control Register)
__sbit PHPB0 = BPHCON : 0;
__sbit PHPB1 = BPHCON : 1;
__sbit PHPB2 = BPHCON : 2;
__sbit PHPB3 = BPHCON : 3;
__sbit PHPB4 = BPHCON : 4;
__sbit PHPB5 = BPHCON : 5;

typedef struct __INTEbits_t
{
    unsigned T0IE   : 1; //!< T0IE=1,  enable Timer0 overflow interrupt
    unsigned PBIE   : 1; //!< PBIE=1,  enable PortB input change interrupt.
    unsigned INTIE  : 1; //!< INTIE=1, enable external interrupt.
    unsigned T1IE   : 1; //!< T1IE=1,  enable Timer1 underflow interrupt.
    unsigned LVDIE  : 1; //!< LVDIE=1, enable low-voltage detector interrupt.
    unsigned        : 1;
    unsigned WDTIE  : 1; //!< WDTIE=1, enable WDT timeout interrupt.
    unsigned        : 1;
} __INTEbits_t;

//! INTE (Interrupt Enable Register)
/**
 * |---------------+------+-------+------+-------+------+-------+------+------|
 * |               | Bit7 | Bit6  | Bit5 | Bit4  | Bit3 | Bit2  | Bit1 | Bit0 |
 * |---------------+------+-------+------+-------+------+-------+------+------|
 * |               | -    | WDTIE | -    | LVDIE | T1IE | INTIE | PBIE | T0IE |
 * |---------------+------+-------+------+-------+------+-------+------+------|
 * | R/W Property  | -    | R/W   | -    | R/W   | R/W  | R/W   | R/W  | R/W  |
 * |---------------+------+-------+------+-------+------+-------+------+------|
 * | Initial Value | X    | 0     | X    | 0     | 0    | 0     | 0    | 0    |
 * |---------------+------+-------+------+-------+------+-------+------+------|
 *
 */
extern __at(0x000e) __sfr INTE;
extern __at(0x000e) volatile __INTEbits_t INTEbits; //!< INTE (Interrupt Enable Register)
__sbit T0IE  = INTE : 0;
__sbit PBIE  = INTE : 1;
__sbit INTIE = INTE : 2;
__sbit T1IE  = INTE : 3;
__sbit LVDIE = INTE : 4;
__sbit WDTIE = INTE : 6;

typedef struct __INTFbits_t
{
    unsigned T0IF   : 1;
    unsigned PBIF   : 1;
    unsigned INTIF  : 1;
    unsigned T1IF   : 1;
    unsigned LVDIF  : 1;
    unsigned        : 1;
    unsigned WDTIF  : 1;
    unsigned        : 1;
} __INTFbits_t;

//! INTF (Interrupt Flag Register)
/**
 * |---------------+------+-------+------+-------+------+-------+------+------|
 * |               | Bit7 | Bit6  | Bit5 | Bit4  | Bit3 | Bit2  | Bit1 | Bit0 |
 * |---------------+------+-------+------+-------+------+-------+------+------|
 * |               | -    | WDTIF | -    | LVDIF | T1IF | INTIF | PBIF | T0IF |
 * |---------------+------+-------+------+-------+------+-------+------+------|
 * | R/W Property  | -    | R/W   | -    | R/W   | R/W  | R/W   | R/W  | R/W  |
 * |---------------+------+-------+------+-------+------+-------+------+------|
 * | Initial Value | 0    | 0     | 0    | 0     | 0    | 0     | 0    | 0    |
 * |---------------+------+-------+------+-------+------+-------+------+------|
 *
 */
extern __at(0x000f) __sfr INTF;
extern __at(0x000f) volatile __INTFbits_t INTFbits; //!< INTF (Interrupt Flag Register)
__sbit T0IF  = INTF : 0;
__sbit PBIF  = INTF : 1;
__sbit INTIF = INTF : 2;
__sbit T1IF  = INTF : 3;
__sbit LVDIF = INTF : 4;
__sbit WDTIF = INTF : 6;

// R-Page special function register }}}

// F-Page special function register {{{
// --------------------------------------------------------

//! IOSTB (PortB I/O Control Register)
/**
 * IOPBx: PBx I/O mode selection, 0 ≤ x ≤ 5.
 * IOPBx=1, PBx is input mode.
 * IOPBx=0, PBx is output mode.
 */
extern __at(0x00800006) volatile __fpage IOSTB;

//! PS0CV (Prescaler0 Counter Value Register)
/**
 * While reading PS0CV, it will get current value of Prescaler0 counter.
 */
extern __at(0x0080000a) volatile __fpage PS0CV;

//! BODCON (PortB Open-Drain Control Register)
/**
 * ODPBx: Enable/disable open-drain of PBx, 0 ≤ x ≤ 5.
 *      ODPBx=1, enable open-drain of PBx.
 *      ODPBx=0, disable open-drain of PBx.
 *      GP3: General purpose register bit.
 */
extern __at(0x0080000c) volatile __fpage BODCON;

//! PCON1 (Power Control Register1)
/**
 * |----------------+------+--------+-------+-------+-------+-------+------+------|
 * |                | Bit7 | Bit6   | Bit5  | Bit4  | Bit3  | Bit2  | Bit1 | Bit0 |
 * |                +------+--------+-------+-------+-------+-------+------+------|
 * |                | GIE  | LVDOUT | LVDS3 | LVDS2 | LVDS1 | LVDS0 | GP1  | T0EN |
 * |----------------+------+--------+-------+-------+-------+-------+------+------|
 * | R/W Property   | R/W  | R      | R/W   | R/W   | R/W   | R/W   | R/W  | R/W  |
 * |----------------+------+--------+-------+-------+-------+-------+------+------|
 * | Initial Value  |   0  | X      |   0   |   0   |   0   |   0   |   0  |  1   |
 * |----------------+------+--------+-------+-------+-------+-------+------+------|
 *
 */
extern __at(0x0080000f) volatile __fpage PCON1;

// F-Page special function register }}}

// S-Page special function register {{{

//! TMR1 (Timer1 Register)
extern __at(0x01000000) volatile __spage TMR1;

//! T1CR1 (Timer1 Control Register1)
/**
 * |---------------+---------+---------+------+------+------+------+------+------|
 * |               | Bit7    | Bit6    | Bit5 | Bit4 | Bit3 | Bit2 | Bit1 | Bit0 |
 * |---------------+---------+---------+------+------+------+------+------+------|
 * |               | PWM1OEN | PWM1OAL | -    | -    | -    | T1OS | T1RL | T1EN |
 * |---------------+---------+---------+------+------+------+------+------+------|
 * | R/W Property  | W       | W       | -    | -    | -    | R/W  | R/W  | R/W  |
 * |---------------+---------+---------+------+------+------+------+------+------|
 * | Initial Value | 0       | 0       | X    | X    | X    | 0    | 0    | 0    |
 * |---------------+---------+---------+------+------+------+------+------+------|
 *
 */
extern __at(0x01000001) volatile __spage T1CR1;

//! T1CR2 (Timer1 Control Register2)
/**
 * |---------------+------+------+------+------+--------+------+------+------|
 * |               | Bit7 | Bit6 | Bit5 | Bit4 | Bit3   | Bit2 | Bit1 | Bit0 |
 * |---------------+------+------+------+------+--------+------+------+------|
 * |               | -    | -    | T1CS | T1CE | /PS1EN |     PS1SE[2:0]     |
 * |---------------+------+------+------+------+--------+------+------+------|
 * | R/W Property  | -    | -    | R/W  | R/W  | R/W    | R/W  | R/W  | R/W  |
 * |---------------+------+------+------+------+--------+------+------+------|
 * | Initial Value | X    | X    | 1    | 1    | 1      | 1    | 1    | 1    |
 * |---------------+------+------+------+------+--------+------+------+------|
 *
 */
extern __at(0x01000002) volatile __spage T1CR2;

//! PWM1DUTY (PWM1 Duty Register)
extern __at(0x01000003) volatile __spage PWM1DUTY;

//! PS1CV (Prescaler1 Counter Value Register)
extern __at(0x01000004) volatile __spage PS1CV;

//! BZ1CR (Buzzer1 Control Register)
/**
 * |---------------+-------+------+------+------+------+------+------+------|
 * |               | Bit7  | Bit6 | Bit5 | Bit4 | Bit3 | Bit2 | Bit1 | Bit0 |
 * |---------------+-------+------+------+------+------+------+------+------|
 * |               | BZ1EN | -    | -    | -    |     BZ1FSEL[3:0]          |
 * |---------------+-------+------+------+------+---------------------------|
 * | R/W Property  | W     | -    | -    | -    |          W                |
 * |---------------+-------+------+------+------+------+------+------+------|
 * | Initial Value | 0     | X    | X    | X    | 1    | 1    | 1    | 1    |
 * |---------------+-------+------+------+------+------+------+------+------|
 *
 */
extern __at(0x01000005) volatile __spage BZ1CR;

//! IRCR (IR Control Register)
/**
 * |---------------+-----------+------+------+------+------+--------+--------+------|
 * |               | Bit7      | Bit6 | Bit5 | Bit4 | Bit3 | Bit2   | Bit1   | Bit0 |
 * |---------------+-----------+------+------+------+------+--------+--------+------|
 * |               | -         | -    | -    | -    | -    | IRCSEL | IRF57K | IREN |
 * |---------------+-----------+------+------+------+------+--------+--------+------|
 * | R/W Property  | -         | -    | -    | -    | -    | W      | W      | W    |
 * |---------------+-----------+------+------+------+------+--------+--------+------|
 * | Initial Value | X         | X    | X    | X    | X    | 0      | 0      | 0    |
 * |---------------+-----------+------+------+------+------+--------+--------+------|
 *
 */
extern __at(0x01000006) volatile __spage IRCR;

//! TBHP (Table Access High Byte Address Pointer Register)
extern __at(0x01000007) volatile __spage TBHP;

//! TBHD (Table Access High Byte Data Register)
extern __at(0x01000008) volatile __spage TBHD;

//! OSCCR (Oscillation Control Register)
/**
 * |---------------+------+------+------+------+------+------+---------+---------|
 * |               | Bit7 | Bit6 | Bit5 | Bit4 | Bit3 | Bit2 | Bit1    | Bit0    |
 * |---------------+------+------+------+------+------+------+---------+---------|
 * |               | -    | -    | -    | -    | OPMD[1:0]   | STPHOSC | SELHOSC |
 * |---------------+------+------+------+------+-------------+---------+---------|
 * | R/W Property  | -    | -    | -    | -    | R/W         | R/W     | R/W     |
 * |---------------+------+------+------+------+-------------+---------+---------|
 * | Initial Value | X    | X    | X    | X    | 00          | 0       | 1       |
 * |---------------+------+------+------+------+-------------+---------+---------|
 *
 * OPMD[1:0]: Selection of operating mode.
 *
 * |-----------+----------------|
 * | OPMD[1:0] | Operating Mode |
 * |-----------+----------------|
 * | 00        | Normal mode    |
 * | 01        | Halt mode      |
 * | 10        | Standby mode   |
 * | 11        | reserved       |
 * |-----------+----------------|
 *
 */
extern __at(0x0100000f) volatile __spage OSCCR;

// S-Page special function register }}}

// T0MD special function register {{{

//! T0MD Register
extern __at(0x00800000) volatile __t0mdpage T0MD;

// T0MD special function register }}}

#endif /* end of include guard: NY8A051F_H_ZC3DOMIF */
