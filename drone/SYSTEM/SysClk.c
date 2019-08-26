#include "main.h"

void SysClk_Init(void)
{
	unsigned char hircmap0,hircmap1;
	unsigned int trimvalue16bit;
	
	set_HIRCEN;						//����HIRC����
	while(CKSWT & 0x20 != 0x20);	//�ȴ���������
	clr_OSC0;
	clr_OSC1;						//�л�ʱ��Դ��HIRC
	while(CKEN & 0x01);				//�ȴ�ʱ��Դ�л����
	CKDIV = 0x00;					//ϵͳʱ�Ӳ���Ƶ
	
	//ʹ�����³������HIRC��16.6MHZ����С���ڲ��������
	
	set_IAPEN;						//ʹ��IAP
	IAPAL = 0x30;
	IAPAH = 0x00;					//��ȡ��ַ
	IAPCN = READ_UID;				//��UID
	set_IAPGO;						//����IAP
	hircmap0 = IAPFD;				//HIRCУ׼ֵ��λ
	IAPAL = 0x31;
	IAPAH = 0x00;					//��ȡ��ַ
	set_IAPGO;						//����IAP
	hircmap1 = IAPFD;				//HIRCУ׼ֵ��λ
	clr_IAPEN;						//ʧ��IAP
	trimvalue16bit = ((hircmap0<<1)+(hircmap1&0x01));
	
	//HIRCУ׼ֵ��ȥ15����16M+15*40KHZ = 16.6MHZ
	trimvalue16bit = trimvalue16bit - 15;
	
	hircmap1 = trimvalue16bit&0x01;
	hircmap0 = trimvalue16bit>>1;
	TA=0XAA;
	TA=0X55;						//��TA����
	RCTRIM0 = hircmap0;				//�޸�ֵд��Ĵ���
	TA=0XAA;
	TA=0X55;						//��TA����
	RCTRIM1 = hircmap1;				//�޸�ֵд��Ĵ���
}	
