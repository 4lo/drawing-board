#include<stdio.h>
#include<graphics.h>
#include"circlestruct.h"
#include"cac.h"
#include"handletrans.h"
//int circlenumber = 0;
extern mouse_msg msg;
void circlestruct()
{	
	you();
	clearviewport();
	Sleep(500);
	xyprintf(0, 10, "0.�����");
	xyprintf(0, 30, "1.�ü���");
	zuo();
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
	you();
	clearviewport();
	zuo();
	Sleep(500);
	if (y > 10 && y < 30)
	{
		you();
		xyprintf(0, 0, "�Ȱ�Բ�ģ��ٰ�Բ��һ��");
		zuo();
		int a1[100], x = 0;
		for (; is_run(); delay_fps(5))
		{
			if (keystate(0x1))
			{
				msg = getmouse();
				a1[x * 2] = msg.x;
				a1[x * 2 + 1] = msg.y;
				x++;	
			}
			you();
			xyprintf(0, 100, "�Ѽ�¼��%d����", x);
			zuo();
			if (x == 2)break;
			}
			int x1, x2, y1, y2;
			x1 = a1[0];
			y1 = a1[1];
			x2 = a1[2];
			y2 = a1[3];
			a[circlenumber].x = x1;
			a[circlenumber].y = y1;
			a[circlenumber].r = ((x1 - x2) ^ 2 + (y1 - y2) ^ 2) ^ (1 / 2)/2;
		
	}
	if (y > 30 && y < 50)
	{
		you();
		clearviewport();
		xyprintf(0, 0, "��������뾶r�����س���");
		a[circlenumber].r = getInteger();
		setfont(-15, 0, "����");
		xyprintf(0, 0, "Բ��x�����س���         ");
		a[circlenumber].x = getInteger();
		setfont(-15, 0, "����");
		xyprintf(0, 0, "Բ��y�����س���         ");
		a[circlenumber].y = getInteger();
		setfont(-15, 0, "����");
	}	
	zuo();
	circle(a[circlenumber].x,
		a[circlenumber].y,
		a[circlenumber].r);
	you();
	char s[255];
	sprintf(s,"CIRCLE\\CIRCLE%d.txt",circlenumber);
	FILE *fp = fopen(s, "a");
	fprintf(fp, "%3d,%3d,%3d",
		a[circlenumber].x,
		a[circlenumber].y,
		a[circlenumber].r);
	fclose(fp);//�洢Բ�ṹ�����ֵ����ֵ
	you();
	xyprintf(0, 0, "�Ƿ��ػ�ǰһ��Բ");
	xyprintf(0, 30, "1   ��");
	xyprintf(0, 50, "2   ��");
	xyprintf(0, 70, "3   �����ϸ�");
	Sleep(5000);
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
		zuo();
		circle(a[circlenumber - 1].x,
			a[circlenumber - 1].y,
			a[circlenumber - 1].r);
		you();
	}
	if (y > 70 && y < 90)
	{
		zuo();
		circle(a[circlenumber - 2].x
			, a[circlenumber - 2].y,
			a[circlenumber - 2].r);
		you();
	}
	you();
	clearviewport();
	zuo();
	circlenumber++;
}