#include "main.h"

void PWM_Init(void)
{
	clr_PWMRUN;							//ʧ��PWM
	set_CLRPWM;							//���PWM����
	
	PWM4_P01_OUTPUT_ENABLE;				//ʹ��PWM1���
	PWM3_P00_OUTPUT_ENABLE;				//ʹ��PWM2���
	PWM2_P10_OUTPUT_ENABLE;				//ʹ��PWM3���
	PWM0_P12_OUTPUT_ENABLE;				//ʹ��PWM4���
	
	PWM_IMDEPENDENT_MODE;				//PWM�����ڶ���ģʽ
	set_PWMTYP;							//��Ե����ģʽ
	PWM_CLOCK_FSYS;						//ϵͳʱ����Ϊʱ��Դ
	
	clr_PWMDIV0;
	clr_PWMDIV1;
	clr_PWMDIV2;						//PWM����Ƶ
	
	PWMPH = 0x03;
	PWMPL = 0xFF;						//PWM���ڼ�����,10Bit����
	
	PWM0H = 0x00;
	PWM0L = 0x00;						//PWMͨ��1��ʼ��
	
	PWM2H = 0x00;
	PWM2L = 0x00;						//PWMͨ��2��ʼ��
	
	PWM3H = 0x00;
	PWM3L = 0x00;						//PWMͨ��3��ʼ��
	
	set_SFRPAGE;
	PWM4H = 0x00;
	PWM4L = 0x00;						//PWMͨ��4��ʼ��
	clr_SFRPAGE;
	
	set_LOAD;							//��װ��PWM�Ƚ���ֵ
    set_PWMRUN;							//����PWM

}

void PWM1_SetDuty(uint16_t duty)
{
	PWM0H = (duty & 0xff00)>>8;
	PWM0L = duty & 0xff;
	set_LOAD;
}

void PWM2_SetDuty(uint16_t duty)
{
	PWM2H = (duty & 0xff00)>>8;
	PWM2L = duty & 0x00ff;
	set_LOAD;
}

void PWM3_SetDuty(uint16_t duty)
{
	PWM3H = (duty & 0xff00)>>8;
	PWM3L = duty & 0x00ff;
	set_LOAD;
}

void PWM4_SetDuty(uint16_t duty)
{
	set_SFRPAGE;
	PWM4H = (duty & 0xff00)>>8;
	PWM4L = duty & 0x00ff;
	clr_SFRPAGE;
	set_LOAD;
}
