#include<graphics.h>
#include"fillpoly.h"
#include"circlestruct.h"
#include"line.h"
#include"bar.h"
#include"mouselineandpoly.h"
#include"handletrans.h"
#include"pixelline.h"
#include"eraser.h"
extern struct CIRCLE a[10];
extern mouse_msg msg;
extern int circlenumber;
int menu(int a, int b)
{   
	int x = 0, y = 0;
	for (; is_run(); delay_fps(10))
	{
		flushkey();
		reac();
		setcolor(EGERGB(169, 167, 167));
		line(5, 0, 5, 645);
		line(5, 645, 1195, 645);
		line(1195, 0, 1195, 645);
		line(905, 0, 905, 645);
		setcolor(BLACK);//������������
		you();
		xyprintf(0, 0, "��ӭʹ�û������              ");
		xyprintf(0, 240, "��Щɶ����");
		xyprintf(0, 260, "1.�ػ�");
		xyprintf(0, 280, "2.��һ�������");
		xyprintf(0, 300, "3.��һ��Բ");
		xyprintf(0, 320, "4.��һ����");
		xyprintf(0, 340, "5.��һ������");
		xyprintf(0, 360, "6.����껭�߻�����");
		xyprintf(0, 380, "7.���");
		xyprintf(0, 400, "8.��Ƥ");
		xyprintf(0, 420, "9.����");
		while (mousemsg())
		{
			msg = getmouse();
		}
		x = msg.x;
		y = msg.y;

		if ((y > 260 && y < 280 && msg.is_left() && x>910) || keystate(49))//�������Ļ��֧
		{
			zuo();
			clearviewport();
			you();
		}
		if ((y > 280 && y < 300 && msg.is_left() && x>910) || keystate(50))//������η�֧
		{
			zuo();
			drawapoli();
			you();
		}
		if ((y > 300 && y < 320 && msg.is_left() && x>910) || keystate(51))//��Բ��֧
		{
			zuo();
			drawcircle();
			you();
		}
		if ((y > 320 && y < 340 && msg.is_left() && x>910) || keystate(52))//��ֱ�߷�֧
		{
			zuo();
			drawline();
			you();
		}
		if ((y > 340 && y < 360 && msg.is_left() && x>910) || keystate(53))//�����η�֧
		{
			zuo();
			drawabar();
			you();
		}
		if ((y > 360 && y < 380 && msg.is_left() && x>910) || keystate(54))//��껭����κ�ֱ��
		{
			zuo();
			mouse();
			you();
		}
		if ((y > 380 && y < 400 && msg.is_left() && x>910) || keystate(55))//��껭������
		{
			zuo();
			pixelline();
			you();
		}
		if ((y > 400 && y < 420 && msg.is_left() && x>910) || keystate(56))//��Ƥ
		{
			zuo();
			eraser();
			you();
		}
		if ((y > 420 && y < 440 && msg.is_left() && x>910) || keystate(57))
		{
			you();
			clearviewport();
			break;
		}
	}
	/*zuo();
	x = getch();
	switch (x)
	{
	case '1': clearviewport();
	break;
	case '2': drawapoli();
	break;
	case '3': circlestruct();
	break;
	case '4': drawline();
	break;
	case '5': drawabar();
	break;
	case '6': mouse();
	break;
	case '7': return 0;
	break;
	default:
	{xyprintf(0, 380, "��������Ҫѡ�ĸ�"); }
	}
	you();*/
	/*xyprintf(0, 220, "����������1.�� 0.��              ");
	chc = getch();
	xyprintf(0, 220, "                               ");
	if (chc == '1')
	break;*/
	return 0;
}
int menu2()
{
	
	int x = 0;/* chc;*/
	int y = 0;

	
	for (; is_run(); delay_fps(10))
	{
		flushkey();
		reac();
		setcolor(EGERGB(169, 167, 167));
		line(5, 0, 5, 645);
		line(5, 645, 1195, 645);
		line(1195, 0, 1195, 645);
		line(905, 0, 905, 645);
		setcolor(BLACK);//�����������������
		you();
		xyprintf(0, 0, "��ӭʹ�û������              ");
		xyprintf(0, 240, "��Щɶ���أ�������Ӧ����ѡ��");//���ѡ�����û�ѡ��
		xyprintf(0, 260, "1.����");
		xyprintf(0, 280, "2.��һ�������");
		xyprintf(0, 300, "3.��һ��Բ");
		xyprintf(0, 320, "4.��һ����");
		xyprintf(0, 340, "5.��һ������");
		xyprintf(0, 360, "6.����껭�߻�����");
		xyprintf(0, 380, "7.���");
		xyprintf(0, 400, "8.��Ƥ");
		xyprintf(0, 420, "9.����");
		while (mousemsg())
		{
			msg = getmouse();
		}
		x = msg.x;
		y = msg.y;
		if ((y > 260 && y < 280 && msg.is_left() && x>910) || keystate(49))
		{
			zuo();
			clearviewport();
			you();
		}
		if ((y > 280 && y < 300 && msg.is_left() && x>910) || keystate(50))
		{
			zuo();
			drawapoli();
			you();
		}
		if ((y > 300 && y < 320 && msg.is_left() && x>910) || keystate(51))
		{
			zuo();
			drawcircle();
			you();
		}
		if ((y > 320 && y < 340 && msg.is_left() && x>910) || keystate(52))
		{
			zuo();
			drawline();
			you();
		}
		if ((y > 340 && y < 360 && msg.is_left() && x>910) || keystate(53))
		{
			zuo();
			drawabar();
			you();
		}
		if ((y > 360 && y < 380 && msg.is_left() && x>910) || keystate(54))
		{
			zuo();
			mouse();
			you();
		}
		if ((y > 380 && y < 400 && msg.is_left() && x>910) || keystate(55))
		{
			zuo();
			pixelline();
			you();
		}
		if ((y > 400 && y < 420 && msg.is_left() && x>910) || keystate(56))
		{
			zuo();
			eraser();
			you();
		}
		if ((y > 420 && y < 440 && msg.is_left() && x>910) || keystate(57))
		{
			you();
			clearviewport();
			break;
		}
	}
	//�����ļ��̼���ѡ���Ѿ�����
	/*x = getch();
	switch (x)
	{
	case '1':
	{
	drawapoli();
	break;
	}
	case '2':
	circlestruct();
	break;
	case '3': drawline();
	break;
	case '4': drawabar();
	break;
	case '5': mouse();
	break;
	case '6': return 0;
	break;
	default:
	{
	you();
	xyprintf(0, 360, "��������Ҫѡ�ĸ�");
	zuo();
	}
	}
	you();
	xyprintf(0, 0, "����������1.�� 0.��                                            ");
	chc = getch();
	zuo();
	if (chc == '0')
	break;*/
	return 0;
}