//��һ���������
#include<graphics.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"fillpoly.h"
#include"cac.h"
#include"handletrans.h"
int polynumber = 0;//��¼����εĸ��������
extern mouse_msg msg;
void drawapoli()
{
	you();
	clearviewport();
	xyprintf(0, 100,
		"���������εı���,��Ҫ����10");
	int rec,i0 = 0;//rec������¼����α���
	do//�������������Ƿ���ȷ��
	{
		poli[polynumber].x = getch() - 48;
		if (poli[polynumber].x < 10)
		{
			break;
		}
		xyprintf(0, 120,
			"������10���µ�����");
	} while(1);//��������Ƿ�Ϊ10���£�2017��Ϊ������getch()������getInteger()�������Ѿ�û��Ҫ
	you();
	clearviewport();
	zuo();
	char point[100] = {0};
	do
	{
		rec = inputbox_getline
		("������λ�����꣬�����ö��Ÿ���,���һ������ ",
			"����   100,200,300,100,050,040  ����λ�����λΪ0����030��",
			point, 
			100);//���������ַ���
		if (rec == (poli[polynumber].x * 8 - 1))break;//�����ַ�������һ�������Ӧ8���ַ������һ������һ���ַ�
		you();
		xyprintf(0, 120, "������ڴ�������������");
	} while (1);
	zuo();
	int i = 0;
	while (i < 2 * poli[polynumber].x)//�ԡ�,��Ϊ�������ַ�������ÿ����ֵ�һ������Ԫ����
	{
		if (i != 0)
			poli[polynumber].token[i] = atoi(strtok(NULL, ","));
		else poli[polynumber].token[i] = atoi(strtok(point, ","));
		i++;
	}
	you();
	coc();
	int y = 0;//������ɫѡ��
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
	if ((y > 0 && y < 20) || keystate(49))
	{
		zuo();
		setfillcolor(RED);
		poli[polynumber].c = 1;
		you();
	}
	if ((y > 20 && y < 40) || keystate(50))
	{
		zuo();
		setfillcolor(BLACK);
		poli[polynumber].c = 2;
		you();
	}
	if ((y > 40 && y < 60) || keystate(51))
	{
		zuo();
		setfillcolor(BLUE);
		poli[polynumber].c = 3;
		you();
	}
	if ((y > 60 && y < 80) || keystate(52))
	{
		zuo();
		setfillcolor(YELLOW);
		poli[polynumber].c = 4;
		you();
	}
	if ((y > 80 && y < 100) || keystate(53))
	{
		zuo();
		setfillcolor(EGERGB(255,255,255));
		poli[polynumber].c = 5;
		you();
	}
	zuo();
	char s[255];//�洢���;�������
	sprintf(s, "POLY\\POLY%d.txt", polynumber);
	FILE *fp = fopen(s, "w");
	fprintf(fp, "%d,", poli[polynumber].x);
	int i1 = 0;
	while (i1 < poli[polynumber].x * 2)//���ڶ���α������ɶ���������ѭ�����δ洢��read is the same
	{
		fprintf(fp, "%3d,",
			poli[polynumber].token[i1]);
		i1++;
	}
	fprintf(fp, "%3d,",
		poli[polynumber].c);
	fclose(fp);//�洢����νṹ�����ֵ����ֵ
	fillpoly(poli[polynumber].x,
		poli[polynumber].token);
	clearcoc();
	Sleep(500);
	you();
	xyprintf(0, 10, "�Ƿ��ػ�ǰһ�������");
	xyprintf(0, 30, "1   ��");
	xyprintf(0, 50, "2   ��");
	xyprintf(0, 70, "3   �����ϸ�");
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
	if ((y > 30 && y < 50) || keystate(49))
	{
		zuo();
		switch (poli[polynumber - 1].c)
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
		fillpoly(poli[polynumber - 1].x,
			poli[polynumber - 1].token);
		you();
	}
	if ((y > 70 && y < 90) || keystate(50))
	{
		zuo();
		switch (poli[polynumber - 2].c)
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
		fillpoly(poli[polynumber - 2].x,
			poli[polynumber - 2].token);
		you();
	}
	you();
	clearviewport();
	zuo();
	flushkey();
	polynumber++;//����μ���+1s
}