
#ifndef REGISTER_H
#define REGISTER_H

typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long u32;

//--------------- GLOBAL DEFINITION ----------------------------------------
u8 TMR_temp;

//u8 flag1,flag2;
u8 int_time1,int_time2;
u8 key_cur,key_per,key_down,key_keep;
u8 long_star,long_time;
u8 sleep_time;

//bit define
/*
__sbit T_FLAG = flag1 : 0;		//定时标志
__sbit adc_flag = flag1 : 1;	//1=10次采样完成
__sbit ON_flag = flag1 : 2;		//1=工作状态
*/

 __at(0x003F) unsigned char temp1;
 

typedef struct flag
{
    unsigned T_flag    : 1;
    unsigned ON_flag    : 1;

}flag;

flag flag1;


//io define
 #define P_CS 	PB0
 #define Key  	0x20



#endif

	 