#include<stdio.h>
#include"handletrans.h"
#include<graphics.h>
#include"readshape.h"
#include"circlestruct.h"
extern mouse_msg msg;
int readfile()
{
	int x = 0, y = 0;
	for (; is_run(); delay_fps(10))
	{
		flushkey();
		you();
		xyprintf(0, 0, "��ӭʹ�û������              ");
		xyprintf(0, 240, "1��ȡ�����");
		xyprintf(0, 260, "2��ȡԲ");
		xyprintf(0, 280, "3��ȡ����");
		xyprintf(0, 300, "4��ȡֱ��");
		xyprintf(0, 500, "5�˳���ȡ");
		while (mousemsg())
		{
			msg = getmouse();
		}
		x = msg.x;
		y = msg.y;//����������
		if ((y > 240 && y < 260 && msg.is_left() && x>910) || keystate(49))//��ȡ�����
		{
			you();
			clearviewport();
			readpoly();
		}
		if ((y > 260 && y < 280 && msg.is_left() && x>910) || keystate(50))//��ȡԲ
		{

			you();
			clearviewport();
			readcircle();
		}
		if ((y > 280 && y < 300 && msg.is_left() && x>910) || keystate(51))//��ȡ����
		{
			you();
			clearviewport();
			readbar();
		}
		if ((y > 300 && y < 320 && msg.is_left() && x>910) || keystate(52))//��ȡֱ��
		{
			you();
			clearviewport();
			readline();
		}
		if ((y > 500 && y < 520 && msg.is_left() && x>910) || keystate(53))//�˳�
		{
			you();
			clearviewport();
			return 0;
		}
	}
}