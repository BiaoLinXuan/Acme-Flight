#include "main.h"

void SysClk_Init(void)
{
	set_HIRCEN;						//����HIRC����
	while(CKSWT & 0x20 != 0x20);	//�ȴ���������
	clr_OSC0;
	clr_OSC1;						//�л�ʱ��Դ��HIRC
	while(CKEN & 0x01);				//�ȴ�ʱ��Դ�л����
	CKDIV = 0x00;					//ϵͳʱ�Ӳ���Ƶ
}
