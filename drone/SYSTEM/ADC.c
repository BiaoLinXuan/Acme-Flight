#include "main.h"

uint16_t ADC_Ch1_Val;
uint16_t ADC_Ch2_Val;
uint16_t ADC_Ch3_Val;
uint16_t ADC_Ch4_Val;

void ADC_Init(void)
{
	AINDIDS = 0xf0;						//�����õ���ADC���Ų��������ֵ�·
	set_ADCEN;							//ʹ��ADC 
	clr_ADCHS0;set_ADCHS1;set_ADCHS2;clr_ADCHS3;//����Ϊͨ��1
	clr_ADCF;							//���ת����ɱ�־λ
	set_EA;								//�����ж�
	set_EADC;							//ʹ��ADC�ж�
}

void ADC_Start_Cvt(void)
{
	if(ADCS == 1 || (ADCCON0 &0x0f) != 0x06)	//ADCģ������ת����������ͨ��û��ת�����
	{
		return;
	}
	CKDIV = 0x02;						//ʱ����ʱ��Ƶ��ADCʱ�Ӳ��ܹ���
	clr_ADCF;							//���ת����ɱ�־λ
	set_ADCS;							//��ʼת��
}

void ADC_ISR(void)   interrupt 11     	//ADC�жϺ�11
{
	switch(ADCCON0 & 0x0f)
	{
		case 0x06:
			ADC_Ch1_Val = (ADCRH<<4) + ADCRL;	//ͨ��1ת�����
			set_ADCHS0;clr_ADCHS1;set_ADCHS2;clr_ADCHS3;//����Ϊͨ��2
			clr_ADCF;							//���ת����ɱ�־λ
			set_ADCS;							//��ʼת��
			break;
		
		case 0x05:
			ADC_Ch2_Val = (ADCRH<<4) + ADCRL;	//ͨ��2ת�����
			clr_ADCHS0;clr_ADCHS1;set_ADCHS2;clr_ADCHS3;//����Ϊͨ��3
			clr_ADCF;							//���ת����ɱ�־λ
			set_ADCS;							//��ʼת��
			break;
		
		case 0x04:
			ADC_Ch3_Val = (ADCRH<<4) + ADCRL;	//ͨ��3ת�����
			set_ADCHS0;set_ADCHS1;set_ADCHS2;clr_ADCHS3;//����Ϊͨ��4
			clr_ADCF;							//���ת����ɱ�־λ
			set_ADCS;							//��ʼת��
			break;
		
		case 0x07:
			ADC_Ch4_Val = (ADCRH<<4) + ADCRL;	//ͨ��4ת�����
			clr_ADCHS0;set_ADCHS1;set_ADCHS2;clr_ADCHS3;//����Ϊͨ��1
			clr_ADCF;							//���ת����ɱ�־λ
			CKDIV = 0x00;						//�ָ�ʱ�ӷ�Ƶ
			break;
	}

}
