#include "bt.h"
#include "gec_uart.h"
#include "bsp.h"
#include "motor.h"
#include "led.h"
#include "track.h"


void Serial_Rcv(void)
{
	if(USART_GetITStatus(USART2,USART_IT_RXNE) == SET)/*�ж�һ�����ǵ��жϱ�־λ�ǲ�����ı�����*/
	{
		//��������
		SerialData = USART_ReceiveData(USART2);
		//bt_Ctrl();
		//�ֶ�������жϱ�־λ
		USART_ClearITPendingBit(USART2,USART_IT_RXNE);
	}
}
  

void bt_Init()
{
	//1.���ڳ�ʼ��
	Gec_UART_Init(USART2,9600,USART_Parity_No,8,1);
	//2.дһ���жϲ�ע��
	BSP_IntVectSet(BSP_INT_ID_USART2,Serial_Rcv);
	//3.ʹ���ж�
	BSP_IntEn(BSP_INT_ID_USART2);
}
void bt_Ctrl()
{
	while(1)
	{
		
		if(SerialData == AutoCtrl)
		{
			//track();
			RunMode = AutoCtrl;
			break;
		}
		if(SerialData == FORWARD)
		{
			//����ǰ��
			car_forward();
			//led_ctrl(LED_D1,LED_ON);
		}
		if(SerialData == BACK)
		{
			//���ú���
			car_back();
			//led_ctrl(LED_D2,LED_ON);
		}
		if(SerialData == TURN_LEFT)
		{
			//������ת
			turn_left();
			//led_ctrl(LED_D3,LED_ON);
		}
		if(SerialData == TURN_RIGHT)
		{
			//������ת
			turn_right();
			//led_ctrl(LED_D4,LED_ON);
		}
		if(SerialData == STOP)
		{
			//����ֹͣ
			car_stop();
			//led_ctrl(LED_D4,LED_OFF);
		}
		
	}
	
}



