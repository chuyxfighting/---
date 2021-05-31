#include "led.h" 
#include "bitband.h"

/**
  * @brief  LED��ʼ������
	* @note		LED��Ӧ�����ŷֱ�Ϊ PF9,PF10,PE13,PE14������͵�ƽ��,����ߵ�ƽ����
  * @param  ��
  * @retval ��
  */
void led_init(void)
{
	GPIO_InitTypeDef f, e;
	/*ʹ��GPIOE,GPIOF��ʱ��*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	
	/*����PF9,PF10,PE13,PE14Ϊ���ģ,����������ͣ�����ģʽ*/
	e.GPIO_Pin = GPIO_Pin_13 |GPIO_Pin_14;
	e.GPIO_Mode = GPIO_Mode_OUT;
	e.GPIO_OType = GPIO_OType_PP;
	e.GPIO_Speed = GPIO_Low_Speed;
	f.GPIO_Pin = GPIO_Pin_9 |GPIO_Pin_10;
	f.GPIO_Mode = GPIO_Mode_OUT;
	f.GPIO_OType = GPIO_OType_PP;
	f.GPIO_Speed = GPIO_Low_Speed;
	GPIO_Init(GPIOE, &e);
	GPIO_Init(GPIOF, &f);
	
	/*����LED0,LED1,LED2,LED3ȱʡΪϨ��*/
	GPIO_SetBits(GPIOE, GPIO_Pin_13 | GPIO_Pin_14);
	GPIO_SetBits(GPIOF, GPIO_Pin_9 | GPIO_Pin_10);	
}

/**
  * @brief  LED״̬���ƺ���
  * @note		LED��Ӧ�����ŷֱ�Ϊ PF9,PF10,PE13,PE14;����͵�ƽ��,����ߵ�ƽ����
	* @param  led_num ָ��Ҫ������һյLED��״̬��
			��ѡ��Ϊ LED_D1,LED_D2,LED_D3,LED_D4
  * @param  led_state ָ��LED�Ƶ�״̬����ѡ��Ϊ LED_ON,LED_OFF
  * @retval ��
  */
void led_ctrl(int led_num, int led_state)
{
	switch(led_num)
	{
		case LED_D1:
			PFout(9) = led_state;
			break;
		case LED_D2:
			PFout(10) = led_state;
			break;
		case LED_D3:
			PEout(13) = led_state;
			break;
		case LED_D4:
			PEout(14) = led_state;
			break;	
	}
}




