#include "main.h"

void ADC_Init(void)
{
	AINDIDS = 0xf0;						//����ADC���Ų��������ֵ�·
	set_ADCEN;							//ʹ��ADC 
}

uint16_t ADC_GetCH1Result(void)
{
	clr_ADCHS0;
	set_ADCHS1;
	set_ADCHS2;
	clr_ADCHS3;							//����Ϊͨ��1
	CKDIV = 0x02;						//ʱ����ʱ��Ƶ��ADCʱ�Ӳ��ܹ���
	clr_ADCF;							//���ת����ɱ�־λ
	set_ADCS;							//��ʼת��
	while(ADCF == 0);					//�ȴ�ת�����
	CKDIV = 0x00;						//�ָ�ʱ�ӷ�Ƶ
	return (ADCRH>>4) + ADCRL;
}

uint16_t ADC_GetCH2Result(void)
{
	set_ADCHS0;
	clr_ADCHS1;
	set_ADCHS2;
	clr_ADCHS3;							//����Ϊͨ��2
	CKDIV = 0x02;						//ʱ����ʱ��Ƶ��ADCʱ�Ӳ��ܹ���
	clr_ADCF;							//���ת����ɱ�־λ
	set_ADCS;							//��ʼת��
	while(ADCF == 0);					//�ȴ�ת�����
	CKDIV = 0x00;						//�ָ�ʱ�ӷ�Ƶ
	return (ADCRH>>4) + ADCRL;
}

uint16_t ADC_GetCH3Result(void)
{
	clr_ADCHS0;
	clr_ADCHS1;
	set_ADCHS2;
	clr_ADCHS3;							//����Ϊͨ��3
	CKDIV = 0x02;						//ʱ����ʱ��Ƶ��ADCʱ�Ӳ��ܹ���
	clr_ADCF;							//���ת����ɱ�־λ
	set_ADCS;							//��ʼת��
	while(ADCF == 0);					//�ȴ�ת�����
	CKDIV = 0x00;						//�ָ�ʱ�ӷ�Ƶ
	return (ADCRH>>4) + ADCRL;
}

uint16_t ADC_GetCH4Result(void)
{
	set_ADCHS0;
	set_ADCHS1;
	set_ADCHS2;
	clr_ADCHS3;							//����Ϊͨ��4
	CKDIV = 0x02;						//ʱ����ʱ��Ƶ��ADCʱ�Ӳ��ܹ���
	clr_ADCF;							//���ת����ɱ�־λ
	set_ADCS;							//��ʼת��
	while(ADCF == 0);					//�ȴ�ת�����
	CKDIV = 0x00;						//�ָ�ʱ�ӷ�Ƶ
	return (ADCRH>>4) + ADCRL;
}