#include <graphics.h>
#include <stdio.h>
#include"cac.h"
#include"fillpoly.h"
#include"line.h"
#include"handletrans.h"
extern mouse_msg msg;
extern int polynumber;
int mousenumber = 0;
int mouse()
{
	flushkey();
	int x = 0, a[100] = { 0 };
	you();
	clearviewport();
	xyprintf(0, 0, "输入顶点个数,画线则直接键入2");
	int i = getch();
	zuo();
	if (i > 50)
	{
		you();
		coc();
		int x = 0, y = 0;
		for (; is_run(); delay_fps(10))
		{
			while (mousemsg())
			{
				msg = getmouse();
			}
			x = msg.x;
			y = msg.y;
			if ((y > 0 && y < 20 && msg.is_left() && x>910) || keystate(49))
			{
				zuo();
				setfillcolor(RED);
				poli[polynumber].c = 1;
				clearcoc();
				Sleep(500);
				break;
			}
			if ((y > 20 && y < 40 && msg.is_left() && x>910) || keystate(50))
			{
				zuo();
				setfillcolor(BLACK);
				poli[polynumber].c = 2;
				clearcoc();
				Sleep(500);
				break;
			}
			if ((y > 40 && y < 60 && msg.is_left() && x>910) || keystate(51))
			{
				zuo();
				setfillcolor(BLUE);
				poli[polynumber].c = 3;
				clearcoc();
				Sleep(500);
				break;
			}
			if ((y > 60 && y < 80 && msg.is_left() && x>910) || keystate(52))
			{
				zuo();
				setfillcolor(YELLOW);
				poli[polynumber].c = 4;
				clearcoc();
				Sleep(500);
				break;
			}
			if ((y > 80 && y < 100 && msg.is_left() && x>910) || keystate(53))
			{
				zuo();
				setfillcolor(EGERGB(255, 255, 255));
				poli[polynumber].c = 5;
				clearcoc();
				Sleep(500);
				break;

			}
		}
	}
	for (; is_run(); delay_fps(10))
	{
		while (mousemsg())
		{
			msg = getmouse();
			
		}//用鼠标结构体和getmouse获取点的坐标，并存在a中
		if (keystate(0x1))
		{
			a[x * 2] = msg.x;
			a[x * 2 + 1] = msg.y;
			x++;
		}
		you();
		xyprintf(0, 100, "已记录了%d个点", x);
		zuo();
		if (x == (i-48))break;
	}
	fillpoly(x, a);
	if (x == 2)
	{
		char s[255];
		sprintf(s, "LINE\\LINE%d.txt", linenumber);
		FILE *fp = fopen(s, "a");
		fprintf(fp, "%3d,%3d,%3d,%3d", ll[linenumber].x1, ll[linenumber].y1, ll[linenumber].x2, ll[linenumber].y2);
		fclose(fp);//存储直线结构体的数值的数值
		linenumber++;
	};
	if (x > 2)
	{
		char s[255];
		sprintf(s, "POLY\\POLY%d.txt", polynumber);
		FILE *fp = fopen(s, "w");
		fprintf(fp, "%d,", i-48);
		int i1 = 0;
		while (i1 < (i-48) * 2)
		{
			fprintf(fp, "%3d,",a[i1]);
			i1++;
		}
		fprintf(fp, "%3d,", poli[polynumber].c);
		fclose(fp);
		polynumber++;
	};
	fillpoly(x, a);
	you();
	clearviewport();
	Sleep(500);

	return 0;
}