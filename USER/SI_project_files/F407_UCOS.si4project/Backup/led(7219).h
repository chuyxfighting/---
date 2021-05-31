#ifndef __LED_H__
#define __LED_H__

//F407�ϣ��Ƶı�� 
#define LED_D1  1
#define LED_D2  2
#define LED_D3  3
#define LED_D4  4


//�ƿ��Ʋ����ĺ�
#define LED_ON 0
#define LED_OFF 1





/*
	led_init:LED��ʼ������
	������
		��
	����ֵ��
		�ޡ�
*/
void led_init(void);


/*
	led_ctrl:�ƿغ���
	@led_num: Ҫ�����ĸ��ƣ��磺
				LED_D1
				LED_D2
				LED_D3
				LED_D4
	@led_state: Ҫ���ƻ��ǹصƣ�
				LED_ON  ����
				LED_OFF �ص�
	����ֵ��
		�ޡ�
*/
void led_ctrl(int led_num, int led_state);




#endif
