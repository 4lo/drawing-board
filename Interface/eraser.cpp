//��Ƥ���ܣ�������Ǧ���ߵ��������������״̬�����Ӵ�������Ӵ���ʵ�־ֲ���Ƥ����Ǧ��һ��ʵ��
#include<graphics.h>
#include"handletrans.h"
extern mouse_msg msg;
void eraser()
{
	Sleep(500);//��ֹ�󴥣������Ը��̣������²���ȫ���ܾ��ý������ã����ײ������ף�
	you();
	clearviewport();
	xyprintf(0, 0, "������Ctrl�˳���Ƥ");
	zuo;
	int x = 0, y = 0;
	for (; is_run(); /*delay_fps(10000)*/)//������꣬��ϧѭ�������죬�㷨���⣬�޷���Ӧ�����ƶ������
	{
		//msg = getmouse();
		if (keystate(0x1))//����������
		{
			zuo();
			while (mousemsg())
			{
				msg = getmouse();
			}
			x = msg.x;
			y = msg.y;//ȡ���������λ�õ�xy
			setviewport(x - 10, y - 10, x + 10, y + 10);//�����Ϊ���ģ�����һ��20x20С�Ӵ�
			clearviewport();//��Ƥ����
			//if (keystate(VK_CONTROL) == 1)break;
		}
		if (keystate(VK_CONTROL) == 1)break;//����ѭ��
	}
}