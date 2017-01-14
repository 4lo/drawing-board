//画一个填充多边形
#include<graphics.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"fillpoly.h"
#include"cac.h"
#include"handletrans.h"
int polynumber = 0;//记录多边形的个数和序号
extern mouse_msg msg;
void drawapoli()
{
	you();
	clearviewport();
	xyprintf(0, 100,
		"请输入多边形的边数,不要超过10");
	int rec,i0 = 0;//rec用来记录多边形边数
	do//用来检验输入是否正确的
	{
		poli[polynumber].x = getch() - 48;
		if (poli[polynumber].x < 10)
		{
			break;
		}
		xyprintf(0, 120,
			"请输入10以下的数字");
	} while(1);//检查输入是否为10以下，2017因为彻底用getch()代替了getInteger()，所以已经没必要
	you();
	clearviewport();
	zuo();
	char point[100] = {0};
	do
	{
		rec = inputbox_getline
		("输入三位数坐标，相邻用逗号隔开,最后一个不用 ",
			"例如   100,200,300,100,050,040  （二位数则百位为0，如030）",
			point, 
			100);//输入坐标字符串
		if (rec == (poli[polynumber].x * 8 - 1))break;//检验字符个数，一个顶点对应8个字符，最后一个点少一个字符
		you();
		xyprintf(0, 120, "输入存在错误，请重新输入");
	} while (1);
	zuo();
	int i = 0;
	while (i < 2 * poli[polynumber].x)//以‘,’为间隔拆分字符串并将每个块分到一个数组元素中
	{
		if (i != 0)
			poli[polynumber].token[i] = atoi(strtok(NULL, ","));
		else poli[polynumber].token[i] = atoi(strtok(point, ","));
		i++;
	}
	you();
	coc();
	int y = 0;//鼠标的颜色选择
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
	char s[255];//存储，和矩形类似
	sprintf(s, "POLY\\POLY%d.txt", polynumber);
	FILE *fp = fopen(s, "w");
	fprintf(fp, "%d,", poli[polynumber].x);
	int i1 = 0;
	while (i1 < poli[polynumber].x * 2)//由于多边形边数不可定，所以用循环依次存储，read is the same
	{
		fprintf(fp, "%3d,",
			poli[polynumber].token[i1]);
		i1++;
	}
	fprintf(fp, "%3d,",
		poli[polynumber].c);
	fclose(fp);//存储多边形结构体的数值的数值
	fillpoly(poli[polynumber].x,
		poli[polynumber].token);
	clearcoc();
	Sleep(500);
	you();
	xyprintf(0, 10, "是否重画前一个多边形");
	xyprintf(0, 30, "1   是");
	xyprintf(0, 50, "2   否");
	xyprintf(0, 70, "3   画上上个");
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
	polynumber++;//多边形计数+1s
}