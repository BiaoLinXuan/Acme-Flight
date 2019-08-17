#include "main.h"

void GPIO_Init(void)
{
	P06_Quasi_Mode;				//TXD׼˫��
	P07_Quasi_Mode;				//RXD׼˫��
	
	P03_Input_Mode;				//ADCͨ��1��������
	P04_Input_Mode;				//ADCͨ��2��������
	P05_Input_Mode;				//ADCͨ��3��������
	P11_Input_Mode;				//ADCͨ��2��������
	
	P30_Quasi_Mode;				//�ⲿ�ж�0׼˫��
	
	P17_PushPull_Mode;			//LED1�������
	P16_PushPull_Mode;			//LED2�������
	P15_PushPull_Mode;			//LED3�������
	P02_PushPull_Mode;			//LED4�������
	
	P01_PushPull_Mode;			//PWM1�������
	P00_PushPull_Mode;			//PWM2�������
	P10_PushPull_Mode;			//PWM3�������
	P12_PushPull_Mode;			//PWM4�������
	
	set_P0SR_1;					//PWM1��б��
	set_P0SR_0;					//PWM2��б��
	set_P1SR_0;					//PWM3��б��
	set_P1SR_2;					//PWM4��б��
	
	P13_PushPull_Mode;			//SCL�������
	P14_PushPull_Mode;			//SDA�������
}
