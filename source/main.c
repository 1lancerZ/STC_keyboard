#include "STC15F2K60S2.H"        //���롣
#include "sys.H"                 //���롣
#include "displayer.H" 
#include "key.h"
#include "adc.h"
#include "uart1.h"
#include "uart2.h"

code unsigned long SysClock=11059200;         //���롣����ϵͳ����ʱ��Ƶ��(Hz)���û������޸ĳ���ʵ�ʹ���Ƶ�ʣ�����ʱѡ��ģ�һ��
#ifdef _displayer_H_                          //��ʾģ��ѡ��ʱ���롣���������ʾ������Ñ����޸ġ����ӵȣ� 
// code char decode_table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x00,0x08,0x40,0x01, 0x41, 0x48, 
// 	              /* ���:   0   1    2	   3    4	    5    6	  7   8	   9	 10	   11		12   13    14     15     */
//                 /* ��ʾ:   0   1    2    3    4     5    6    7   8    9  (��)   ��-  ��-  ��-  ����-  ����-   */  
// 	                       0x3f|0x80,0x06|0x80,0x5b|0x80,0x4f|0x80,0x66|0x80,0x6d|0x80,0x7d|0x80,0x07|0x80,0x7f|0x80,0x6f|0x80 };  
//              /* ��С����     0         1         2         3         4         5         6         7         8         9        */
code char decode_table[]={0x3e,0x6d,0x7c,0x38,0x79,0x00};
#endif

unsigned char keynum[] = {0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x10,0x20,0x30,0x40,0x50,0x60,0x70};
char ble = 'u';

void my100mS_callback()
{ unsigned char a;
	if( a != 0) a=a<<1;
	  else a=0x01;
	LedPrint(a);
}

void key_callback(){
	char k;
	k = GetKeyAct(enumKey1);
	if(k == enumKeyPress){
		if(ble == 'u') Uart1Print(keynum,1);
		else if(ble == 'b') Uart2Print(keynum,1);
	}
	else if(k == enumKeyRelease){
		if(ble == 'u') Uart1Print(keynum+7,1);
		else if(ble == 'b') Uart2Print(keynum+7,1);
	}
	k = GetKeyAct(enumKey2);
	if(k == enumKeyPress){
		if(ble == 'u') Uart1Print(keynum+1,1);
		else if(ble == 'b') Uart2Print(keynum+1,1);
	}
	else if(k == enumKeyRelease){
		if(ble == 'u') Uart1Print(keynum+8,1);
		else if(ble == 'b') Uart2Print(keynum+8,1);
	}
//  ���������ADCģ�飬����3��Key3���κβ����ڱ�ģ�鲻�ɼ�⵽�����κ���Ϣ��Ӧ
// 	k = GetKeyAct(enumKey3);
// 	if(k == enumKeyPress){
// 		Uart1Print(keynum+2,1);
// }
}

void nav_callback(){
	char k;
	k = GetAdcNavAct(enumAdcNavKey3);
	if(k == enumKeyPress){
		if(ble == 'u'){
			ble = 'b';
			Seg7Print(2,3,4,5,5,5,5,5);
		}
		else if(ble == 'b'){
			ble = 'u';
			Seg7Print(0,1,2,5,5,5,5,5);
		}
	}
	k = GetAdcNavAct(enumAdcNavKeyUp);
	if(k == enumKeyPress){
		if(ble == 'u') Uart1Print(keynum+2,1);
		else if(ble == 'b') Uart2Print(keynum+2,1);
	}
	else if(k == enumKeyRelease){
		if(ble == 'u') Uart1Print(keynum+9,1);
		else if(ble == 'b') Uart2Print(keynum+9,1);
	}
	k = GetAdcNavAct(enumAdcNavKeyDown);
	if(k == enumKeyPress){
		if(ble == 'u') Uart1Print(keynum+3,1);
		else if(ble == 'b') Uart2Print(keynum+3,1);
	}
	else if(k == enumKeyRelease){
		if(ble == 'u') Uart1Print(keynum+10,1);
		else if(ble == 'b') Uart2Print(keynum+10,1);
	}
	k = GetAdcNavAct(enumAdcNavKeyLeft);
	if(k == enumKeyPress){
		if(ble == 'u') Uart1Print(keynum+4,1);
		else if(ble == 'b') Uart2Print(keynum+4,1);
	}
	else if(k == enumKeyRelease){
		if(ble == 'u') Uart1Print(keynum+11,1);
		else if(ble == 'b') Uart2Print(keynum+11,1);
	}
	k = GetAdcNavAct(enumAdcNavKeyRight);
	if(k == enumKeyPress){
		if(ble == 'u') Uart1Print(keynum+5,1);
		else if(ble == 'b') Uart2Print(keynum+5,1);
	}
	else if(k == enumKeyRelease){
		if(ble == 'u') Uart1Print(keynum+12,1);
		else if(ble == 'b') Uart2Print(keynum+12,1);
	}
	k = GetAdcNavAct(enumAdcNavKeyCenter);
	if(k == enumKeyPress){
		if(ble == 'u') Uart1Print(keynum+6,1);
		else if(ble == 'b') Uart2Print(keynum+6,1);
	}
	else if(k == enumKeyRelease){
		if(ble == 'u') Uart1Print(keynum+13,1);
		else if(ble == 'b') Uart2Print(keynum+13,1);
	}
	
}

void uart2Receive_callback(){
	SetUart2Rxd(keynum,1,0,0);
	Uart1Print(keynum,1);
}

void main() 
{ Uart1Init(2400);
	Uart2Init(9600,Uart2UsedforEXT);
	KeyInit();
//      ADCexpEXT   :  ��������չ�ӿ�EXT����ADC���ܣ�EXT��P1.0��P1.1��������IO����ʹ�ã� 		
	AdcInit(ADCexpEXT);
	DisplayerInit();
  
	SetDisplayerArea(0,7);	
  Seg7Print(0,1,2,5,5,5,5,5);	
	SetEventCallBack(enumEventSys100mS, my100mS_callback);
	SetEventCallBack(enumEventNav, nav_callback);
	SetEventCallBack(enumEventKey, key_callback);
	SetEventCallBack(enumEventUart2Rxd, uart2Receive_callback);
	
  MySTC_Init();	    
	while(1)             	
		{ MySTC_OS();    
		}	             
}                 