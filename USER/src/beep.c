#include "beep.h" 
#include "bitband.h"

/**
  * @brief  beep��ʼ������
	* @note		beep��Ӧ������Ϊ PF8������ߵ�ƽ��,����͵�ƽ����
  * @param  ��
  * @retval ��
  */
void beep_init(void)
{
	GPIO_InitTypeDef f;
	/*ʹ��GPIOF��ʱ��*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

	/*����PF8Ϊ���ģʽ,�����������,����ģʽ*/
	f.GPIO_Pin = GPIO_Pin_8 ;
	f.GPIO_Mode = GPIO_Mode_OUT;
	f.GPIO_OType = GPIO_OType_PP;
	f.GPIO_Speed = GPIO_Low_Speed;
	GPIO_Init(GPIOF, &f);
	
	/*����beepȱʡΪ����*/
	PFout(8) = 0;
}

/**
  * @brief  beep״̬���ƺ���
  * @note		beep��Ӧ������Ϊ PF8������ߵ�ƽ��,����͵�ƽ����
  * @param  beep_state ָ��beep�Ƶ�״̬����ѡ��Ϊ BEEP_ON,BEEP_OFF
  * @retval ��
  */
void beep_ctrl(int beep_state)
{
	PFout(8) = beep_state;
}
