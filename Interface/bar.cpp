//�������������εĺ�������Ϊ��껭�ͼ��̼��뻭
#include<graphics.h>
#include"bar.h"
#include<stdio.h>
#include"cac.h"
#include"handletrans.h"
#include"eraser.h"
int barnumber = 0;
extern mouse_msg msg;
void drawabar()
{
	Sleep(100);//��ֹ�󴥣���Ϊ������׶�ε��
	you();
	clearviewport();
	zuo();
	you();
	xyprintf(0, 10, "0.�����");
	xyprintf(0, 30, "1.�ü���");//ѡ�����
	int x = 0,y = 0;
		for (; is_run(); delay_fps(10))//������
		{
			while (mousemsg())
			{
				msg = getmouse();
			}
			x = msg.x;
			y = msg.y;
			if ((y > 10 && y < 30 && msg.is_left() && x>910)||keystate(49))//������֧
			{
				Sleep(100);
				zuo();
				int a[100], x = 0;
				for (; is_run(); delay_fps(10))
				{
					while (mousemsg())
					{
						msg = getmouse();
						a[x * 2] = msg.x;
						a[x * 2 + 1] = msg.y;
					}//�����ṹ���getmouse��ȡ������꣬������a��
					if (keystate(0x1))
					{
						x++;
					}
					you();
					xyprintf(0, 100, "�Ѽ�¼��%d����", x);
					zuo();
					if (x == 2)break;
				}
				square[barnumber].x1 = a[0];
				square[barnumber].y1 = a[1];
				square[barnumber].x2 = a[2];
				square[barnumber].y2 = a[3];//��¼���εĻ�����Ϣ
				you();
				break;
			}
			if ((y > 30 && y < 50 && msg.is_left() && x>910)||keystate(50))//�����֧
			{
				clearviewport();
				xyprintf(0, 0, "���Ͻǵ�x");
				square[barnumber].x1 = getInteger();
				setfont(-15, 0, "����");
				xyprintf(0, 0, "���Ͻǵ�y");
				square[barnumber].y1 = getInteger();
				setfont(-15, 0, "����");
				xyprintf(0, 0, "���½ǵ�x");
				square[barnumber].x2 = getInteger();
				setfont(-15, 0, "����");
				xyprintf(0, 0, "���½ǵ�y");
				square[barnumber].y2 = getInteger();
				setfont(-15, 0, "����");
				break;
			}
		}
	you();//�����������
	Sleep(500);//������֧�����Ｏ������
	clearviewport();
	coc();//��ӡ����ɫѡ��
	for (; is_run(); delay_fps(10))//������
	{
		while (mousemsg())
		{
			msg = getmouse();
		}
		x = msg.x;
		y = msg.y;
		if ((y > 0 && y < 20 && msg.is_left() && x>910) || keystate(49))//��ɫ
		{
			zuo();
			setfillcolor(RED);
			square[barnumber].c = 1;
			break;
		}
		if ((y > 20 && y < 40 && msg.is_left() && x>910) || keystate(50))//��ɫ
		{
			zuo();
			setfillcolor(BLACK);
			square[barnumber].c = 2;
			break;
		}
		if ((y > 40 && y < 60 && msg.is_left() && x>910) || keystate(51))//��ɫ
		{
			zuo();
			setfillcolor(BLUE);
			square[barnumber].c = 3;
			break;
		}
		if ((y > 60 && y < 80 && msg.is_left() && x>910) || keystate(52))//��ɫ
		{
			zuo();
			setfillcolor(YELLOW);
			square[barnumber].c = 4;
			break;
		}
		if ((y > 80 && y < 100 && msg.is_left() && x>910) || keystate(53))//��ɫ
		{
			zuo();
			setfillcolor(EGERGB(255, 255, 255));
			square[barnumber].c = 5;
			break;
		}
	}
	//��������о��εĻ��
	bar(square[barnumber].x1,
		square[barnumber].y1,
		square[barnumber].x2,
		square[barnumber].y2);
	//eraser();�����й���Ƥ���ܵĲ���
	char s[255];//����Ϊ�洢
	sprintf(s, "BAR\\BAR%d.txt", barnumber);
	FILE *fp = fopen(s, "w");
	fprintf(fp, "%3d,%3d,%3d,%3d,%3d",
		square[barnumber].x1,
		square[barnumber].y1,
		square[barnumber].x2,
		square[barnumber].y2,
		square[barnumber].c);
	fclose(fp);//�洢���νṹ�����ֵ����ֵ
	you();
	clearviewport();
	xyprintf(0, 0, "�Ƿ��ػ�ǰһ������");//����Ϊ�ػ�
	xyprintf(0, 30, "1   ��");
	xyprintf(0, 50, "2   ��");
	xyprintf(0, 70, "3   �����ϸ�");
	for (; is_run(); delay_fps(10))
	{
		while (mousemsg())
		{
			msg = getmouse();
		}
		x = msg.x;
		y = msg.y;
		if (y > 30 && y < 50 && msg.is_left() && x>910)//����һ������ ������-1�� 
		{
			zuo();
			switch (square[barnumber - 1].c)
			{
			case 1:setfillcolor(RED);
				break;
			case 2:setfillcolor(BLACK);
				break;
			case 3:setfillcolor(BLUE);
				break;
			case 4:setfillcolor(YELLOW);
				break;
			case 5:setfillcolor(EGERGB(255, 255, 255));
				break;
			}
			bar(square[barnumber - 1].x1,
				square[barnumber - 1].y1,
				square[barnumber - 1].x2,
				square[barnumber - 1].y2);
			break;
			you();
		}
		if (y > 50 && y < 70 && msg.is_left() && x>910)//�˳�
		{
			break;
		}
		if (y > 70 && y < 90 && msg.is_left() && x>910)//num-2
		{
			zuo();
			switch (square[barnumber - 2].c)
			{
			case 1:setfillcolor(RED);
				break;
			case 2:setfillcolor(BLACK);
				break;
			case 3:setfillcolor(BLUE);
				break;
			case 4:setfillcolor(YELLOW);
				break;
			case 5:setfillcolor(EGERGB(255, 255, 255));
				break;
			}
			bar(square[barnumber - 2].x1,
				square[barnumber - 2].y1,
				square[barnumber - 2].x2,
				square[barnumber - 2].y2);
			break;
			you();
		}
	}
	you();
	clearviewport();
	zuo();
	barnumber++;//����+1s
}