/*this program is made to welcome our customers*/

#include"readshape.h"
#include"readfile.h"
#include"menu.h"
#include"fillpoly.h"
#include<graphics.h>
#include<Windows.h>
#include"circlestruct.h"
#include"line.h"
#include"bar.h"
#include<stdio.h>
#include"mouselineandpoly.h"
#include"handletrans.h"
#include"pixelline.h"
struct CIRCLE a[10] = { 0 };
struct linestruct ll[10] = { 0 };
struct drawpoli poli[10] = { 0 };
struct barstruct square[10] = { 0 };
struct mouse_msg msg = { 0 };
int main(void)
{
	initgraph(1200, 650);//��������
	line(5, 0, 5, 645);
	line(5, 645, 1195, 645);
	line(1195, 0, 1195, 645);
	line(905, 0, 905, 645);//���ƻ���Ļ�������
	setviewport(0, 0, 1190, 640, 1);//���ñ߿򣬲���2017��ûʲô̫������
	setbkcolor(EGERGB(255,255,255)); //���ñ�����ɫ
	setcolor(BLACK);//����������ɫ
	setfont(-15, 0, "����");//����
	int x = 0,y = 0,pri = 1;//xy ������¼���  pri�Ѿ�2017���ʱ��û��ʵ������
	for (; is_run(); delay_fps(10))//ѭ��������֤�����������
	{
		reac();//ȫ���Ӵ���Ȼ����
		setcolor(EGERGB(169, 167, 167));
		line(5, 0, 5, 645);
		line(5, 645, 1195, 645);
		line(1195, 0, 1195, 645);
		line(905, 0, 905, 645);
		setcolor(BLACK);//���ֽ�������
		you();//�����Ҳ����
		xyprintf(0, 0, "��ӭ�����������                            ");//��ӭ����
		xyprintf(0, 15, "�Ƿ��ȡ  (��shift�л����뷨��Ӣ��)");
		xyprintf(0, 50, "1.��ȡ�ҵ���ʷ�ļ�");
		xyprintf(0, 70, "0.�½�����");
		while (mousemsg())//�������ж���
		{
			msg = getmouse();
		}
		x = msg.x;
		y = msg.y;
		if ((y > 40 && y < 70 && msg.is_left() && x>910) || keystate(49))//����Ϊ��ȡ��֧
		{
			you();
			flushkey();
			clearviewport();
			readfile();
			menu(pri, 1);
		}
		if ((y > 70 && y < 90 && msg.is_left() && x>910) || keystate(50))//�½���֧
		{
			you();
			flushkey();
			clearviewport();
			menu2();
		}
	}
	//������Ǽ��̰��������Ĵ��룬�Ѿ�����ʱЧ��
	/*if (pri == 1)//��ȡ�ļ�
	{
	d = 1;
	readpoly();
	menu(pri, d);
	}
	else if (pri == 0)//�½�����
	{
	menu2();
	}
	/*you();
	xyprintf(20, 10, "�Ƿ��˳��������  ");
	xyprintf(20, 30, "1.�˳�");
	xyprintf(20, 50, "0.��  ");
	int y = 0;
	for (; is_run(); delay_fps(10))
	{
	while (mousemsg())
	{
	msg = getmouse();
	}
	if (keystate(0x1))
	{
	y = msg.y;
	break;
	}
	}
	if (y > 30 && y < 50)
	{
	break;
	}
	if (y > 50 && y < 70)
	{

	}
	zuo();*/
	/*chc = getch();
	if (chc == '1')
	break;*/
	return 0;
}
