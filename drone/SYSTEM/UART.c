#include "main.h"

#define BAUDATE 256000

void UART_Init(void)
{
	InitialUART0_Timer3(BAUDATE);			//ʹ�ÿ��ʼ��UART0
	set_EA;									//�����ж�
	set_ES;									//ʹ�ܴ����ж�
	set_PS;									//�������ȼ���λΪ1
	set_PSH;								//�������ȼ���λΪ1
}
