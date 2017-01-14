#include<graphics.h>
#include"circlestruct.h"
#include"line.h"
#include<stdio.h>
#include"handletrans.h"
int readcircle()
{
	flushkey();
	xyprintf(0, 0, "请输入读取的序号");
	int x = getch() - 48;//保证用getch获得真值
	xyprintf(0, 0, "                      ");
	char read1[40] = { 0 };//用来缓冲的暂数组
	char s[255];//这个数组用来拼接获得的数字和CIRCLE的
	sprintf(s, "CIRCLE\\CIRCLE%d.txt", x);//拼接他们
	FILE *pt = fopen(s, "r");//打开文件
	fgets(read1,40,pt);//把读取到的东西放在read1里
	fclose(pt);//关闭文件
	int read2[3] = { 0 };
	int i = 0;
	while (i < 3)//以逗号为间隔拆分
	{
		if (i != 0)
			read2[i] = atoi(strtok(NULL, ","));
		else read2[i] = atoi(strtok(read1, ","));
		i++;
	}
	zuo();
	circle(read2[0], read2[1],read2[2]);//画出文件里记录的圆
	you();
	return 0;
}

void readbar()
{
	flushkey();
	xyprintf(0, 0, "请输入读取的序号");//和圆一样
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
	switch (read2[4])//读取颜色
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
	xyprintf(0, 0, "请输入读取的序号");//一样
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
	xyprintf(0, 0, "请输入读取的序号");
	xyprintf(0, 15, "                                                ");
	int x = getch(); 
	xyprintf(0, 0, "                      ");
	char read1[400] = { 0 };//特意把数组放大
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
