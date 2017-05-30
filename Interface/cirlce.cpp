//这是画圆的函数 大体上逻辑结构以及代码和矩形差不多
#include<stdio.h>
#include<math.h>
#include"graphics.h"
#include"circlestruct.h"
#include"cac.h"
#include"handletrans.h"
int circlenumber = 0;
extern mouse_msg msg;
void drawcircle()
{
	Sleep(100);//防止鼠标误触
	you();
	clearviewport();
	zuo();
	you();
	xyprintf(0, 10, "1.用鼠标");
	xyprintf(0, 30, "2.用键盘");
	int x = 0,y = 0;
	for (; is_run(); delay_fps(10))
	{
		while (mousemsg())
		{
			msg = getmouse();
		}
		x = msg.x;
		y = msg.y;
		if ((y > 10 && y < 30 && msg.is_left() && x>910) || keystate(49))
		{
			you();
			clearviewport();
			Sleep(500);
			zuo();
			int a1[100], x = 0;
			for (; is_run(); delay_fps(5))
			{
				while (mousemsg())
				{
					msg = getmouse();
					a1[x * 2] = msg.x;
					a1[x * 2 + 1] = msg.y;
				}//用鼠标结构体和getmouse获取点的坐标，并存在a中
				if (keystate(0x1))
				{
					x++;
				}
				you();
				xyprintf(0, 100, "已记录了%d个点", x);
				zuo();
				if (x == 2)break;
			}
			int x1, x2 = 0, y1, y2 = 0, r;
			x1 = (a1[0] - a1[2]);
			x1 = x1 * x1;
			y1 = (a1[1] - a1[3]);
			y1 = y1 * y1;
			r = y1 + x1;
			r = sqrt(r);
			x2 = a1[0];
			y2 = a1[1];
			a[circlenumber].x = x2;
			a[circlenumber].y = y2;
			a[circlenumber].r = r;
			you();
			break;
		}
		if ((y > 30 && y < 50 && msg.is_left() && x>910) || keystate(50))
		{
			you();
			xyprintf(0, 0, "依次输入半径r（按回车）");
			a[circlenumber].r = getInteger();
			setfont(-15, 0, "楷体");
			xyprintf(0, 0, "圆心x（按回车）         ");
			a[circlenumber].x = getInteger();
			setfont(-15, 0, "楷体");
			xyprintf(0, 0, "圆心y（按回车）         ");
			a[circlenumber].y = getInteger();
			setfont(-15, 0, "楷体");
			zuo();
			break;
		}
	}
	zuo();
	circle(a[circlenumber].x,
		a[circlenumber].y,
		a[circlenumber].r);
	you();
	char s[255];
	sprintf(s, "CIRCLE\\CIRCLE%d.txt", circlenumber);
	FILE *fp = fopen(s, "w");
	fprintf(fp, "%3d,%3d,%3d",
		a[circlenumber].x,
		a[circlenumber].y,
		a[circlenumber].r);
	fclose(fp);//存储圆结构体的数值的数值
	you();
	clearviewport();
	xyprintf(0, 0, "是否重画前一个圆");
	xyprintf(0, 30, "1   是");
	xyprintf(0, 50, "2   否");
	xyprintf(0, 70, "3   画上上个");
	for (; is_run(); delay_fps(10))
	{
		while (mousemsg())
		{
			msg = getmouse();
		}
		x = msg.x;
		y = msg.y;
		if ((y > 30 && y < 50 && msg.is_left() && x>910) || keystate(49))
		{
			zuo();
			circle(a[circlenumber - 1].x,
				a[circlenumber - 1].y,
				a[circlenumber - 1].r);
			you();
			break;
		}
		if ((y > 50 && y < 70 && msg.is_left() && x>910) || keystate(50))
			break;
		if ((y > 70 && y < 90 && msg.is_left() && x>910) || keystate(51))
		{
			zuo();
			circle(a[circlenumber - 2].x
				, a[circlenumber - 2].y,
				a[circlenumber - 2].r);
			you();
			break;
		}
	}
	you();
	clearviewport();
	zuo();
	circlenumber++;
}