#include "main.h"

#define BAUDATE 115200

void UART0_Init(void)
{
	InitialUART0_Timer3(BAUDATE);			//ʹ�ÿ��ʼ��UART0
	set_EA;									//�����ж�
	set_ES;									//ʹ�ܴ����ж�
	set_PS;									//�������ȼ���λΪ1
	set_PSH;								//�������ȼ���λΪ1
	clr_TI;
	clr_RI;
}

void UART0_ISR (void)   interrupt 4     	//UART0�жϺ�4
{
	clr_TI;
	clr_RI;
}