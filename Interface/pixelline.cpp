//2017����ɵĵ�һ�����£����ڰ������߸������
#include<graphics.h>
#include"handletrans.h"
extern mouse_msg msg;
int pixelline()
{
	you();
	clearviewport();
	xyprintf(0, 0, "����סCtrl�ٿ�ʼ����");
	xyprintf(0, 20, "�����ּ��˳���");
	zuo(); 
	int i = 1, x[100000] = { 0 }, y[100000] = {0},*p1,*p2;//�����㹻����������洢���
	p1 = &x[i];
	p2 = &y[i];
	getkey();
	getmouse();
	mousepos(p1, p2);//��ȡ��ǰ���λ�ò���ָ��洢�������˴�ԭ�㻭�ߵ�����
	i++;

	for (; is_run(); /*delay_fps(10000)*/)
	{
		p1 = &x[i];//�������
		p2 = &y[i];
		msg = getmouse();
		if (keystate(0x1))
		{
			mousepos(p1, p2);
			line(x[i], y[i], x[i - 1], y[i - 1]);
			i++;
			flushmouse();//����flush����������Ĳ�һ����Ŀ��û����
			flushkey();
			//if (keystate(VK_CONTROL) == 0)
			//break;
		}
		if (keystate(VK_CONTROL) == 0)//Ctrl�������˳�
			break;
	}
	flushmouse();
	flushkey();//Ŀ��û��
	you();
	clearviewport();//����
	return 0;

}