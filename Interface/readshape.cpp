#include<graphics.h>
#include"circlestruct.h"
#include"line.h"
#include<stdio.h>
#include"handletrans.h"
int readcircle()
{
	flushkey();
	xyprintf(0, 0, "�������ȡ�����");
	int x = getch() - 48;//��֤��getch�����ֵ
	xyprintf(0, 0, "                      ");
	char read1[40] = { 0 };//���������������
	char s[255];//�����������ƴ�ӻ�õ����ֺ�CIRCLE��
	sprintf(s, "CIRCLE\\CIRCLE%d.txt", x);//ƴ������
	FILE *pt = fopen(s, "r");//���ļ�
	fgets(read1,40,pt);//�Ѷ�ȡ���Ķ�������read1��
	fclose(pt);//�ر��ļ�
	int read2[3] = { 0 };
	int i = 0;
	while (i < 3)//�Զ���Ϊ������
	{
		if (i != 0)
			read2[i] = atoi(strtok(NULL, ","));
		else read2[i] = atoi(strtok(read1, ","));
		i++;
	}
	zuo();
	circle(read2[0], read2[1],read2[2]);//�����ļ����¼��Բ
	you();
	return 0;
}

void readbar()
{
	flushkey();
	xyprintf(0, 0, "�������ȡ�����");//��Բһ��
	int x = getch() - 48;
	xyprintf(0, 0, "                      ");
	char read1[40] = { 0 };
	char s[255];
	sprintf(s, "BAR\\BAR%d.txt", x);
	FILE *pt = fopen(s, "r");
	fgets(read1, 40, pt);
	fclose(pt);
	int read2[5] = { 0 };
	int i = 0;
	while (i < 5)
	{
		if (i != 0)
			read2[i] = atoi(strtok(NULL, ","));
		else read2[i] = atoi(strtok(read1, ","));
		i++;
	}
	switch (read2[4])//��ȡ��ɫ
	{
	case 1 :setfillcolor(RED);
		break;
	case 2 :setfillcolor(BLACK);
		break;
	case 3 :setfillcolor(BLUE);
		break;
	case 4 :setfillcolor(YELLOW);
		break;
	case 5:setfillcolor(EGERGB(255, 255, 255));
		break;
	}
	zuo();
	bar(read2[0], read2[1], read2[2], read2[3]);
	you();
}
int readline()
{
	flushkey();
	xyprintf(0, 0, "�������ȡ�����");//һ��
	int x = getch() - 48;
	xyprintf(0, 0, "                      ");
	char read1[40] = { 0 };
	char s[255];
	sprintf(s, "LINE\\LINE%d.txt", x);
	FILE *pt = fopen(s, "r");
	fgets(read1, 40, pt);
	fclose(pt);
	int read2[40] = { 0 };
	int i = 0;
	while (i < 4)
	{
		if (i != 0)
			read2[i] = atoi(strtok(NULL, ","));
		else read2[i] = atoi(strtok(read1, ","));
		i++;
	}
	zuo();
	line(read2[0], read2[1], read2[2],read2[3]);
	you();
	return 0;
}
int readpoly()
{
	flushkey();
	xyprintf(0, 0, "�������ȡ�����");
	xyprintf(0, 15, "                                                ");
	int x = getch(); 
	xyprintf(0, 0, "                      ");
	char read1[400] = { 0 };//���������Ŵ�
	char s[255];
	sprintf(s, "POLY\\POLY%d.txt", x - 48);
	FILE *pt = fopen(s, "r");
	int t = fgetc(pt);
	fgets(read1, 400, pt);
	fclose(pt);
	int read2[100] = { 0 };
	int i = 0;
	while (i < ( t-48 ) * 2 + 1)
	{
		if (i != 0)
			read2[i] = atoi(strtok(NULL, ","));
		else read2[i] = atoi(strtok(read1, ","));
		i++;
	}
	zuo();
	switch (read2[i - 1])
	{
	case 1 :setfillcolor(RED);
		break;
	case 2 :setfillcolor(BLACK);
		break;
	case 3 :setfillcolor(BLUE);
		break;
	case 4 :setfillcolor(YELLOW);
		break;
	case 5:setfillcolor(EGERGB(255,255,255));
		break;
	}
	fillpoly(t-48,read2);
	you();
	return 0;
}
