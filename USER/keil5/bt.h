#ifndef __BT_H__
#define __BT_H__



//���������ź�

#define FORWARD    1      //ǰ��
#define BACK       2			//����
#define TURN_LEFT	 3			//��ת
#define TURN_RIGHT 4			//��ת
#define STOP	     5			//ֹͣ

//RunMode
#define AutoCtrl   6			//�Զ�ѭ��
#define BTCtrl	   7			//��������

extern unsigned char SerialData;
extern char RunMode; 

void bt_Init(void);
void Serial_Rcv(void);
void bt_Ctrl(void);

#endif

