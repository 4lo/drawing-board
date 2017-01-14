//这是用来画矩形的函数，分为鼠标画和键盘键入画
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
	Sleep(100);//防止误触，因为鼠标容易多次点击
	you();
	clearviewport();
	zuo();
	you();
	xyprintf(0, 10, "0.用鼠标");
	xyprintf(0, 30, "1.用键盘");//选择界面
	int x = 0,y = 0;
		for (; is_run(); delay_fps(10))//监控鼠标
		{
			while (mousemsg())
			{
				msg = getmouse();
			}
			x = msg.x;
			y = msg.y;
			if ((y > 10 && y < 30 && msg.is_left() && x>910)||keystate(49))//用鼠标分支
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
				square[barnumber].x1 = a[0];
				square[barnumber].y1 = a[1];
				square[barnumber].x2 = a[2];
				square[barnumber].y2 = a[3];//记录矩形的基本信息
				you();
				break;
			}
			if ((y > 30 && y < 50 && msg.is_left() && x>910)||keystate(50))//键入分支
			{
				clearviewport();
				xyprintf(0, 0, "左上角点x");
				square[barnumber].x1 = getInteger();
				setfont(-15, 0, "楷体");
				xyprintf(0, 0, "左上角点y");
				square[barnumber].y1 = getInteger();
				setfont(-15, 0, "楷体");
				xyprintf(0, 0, "右下角点x");
				square[barnumber].x2 = getInteger();
				setfont(-15, 0, "楷体");
				xyprintf(0, 0, "右下角点y");
				square[barnumber].y2 = getInteger();
				setfont(-15, 0, "楷体");
				break;
			}
		}
	you();//进入操作界面
	Sleep(500);//两个分支从这里集合起来
	clearviewport();
	coc();//打印了颜色选择
	for (; is_run(); delay_fps(10))//监控鼠标
	{
		while (mousemsg())
		{
			msg = getmouse();
		}
		x = msg.x;
		y = msg.y;
		if ((y > 0 && y < 20 && msg.is_left() && x>910) || keystate(49))//红色
		{
			zuo();
			setfillcolor(RED);
			square[barnumber].c = 1;
			break;
		}
		if ((y > 20 && y < 40 && msg.is_left() && x>910) || keystate(50))//黑色
		{
			zuo();
			setfillcolor(BLACK);
			square[barnumber].c = 2;
			break;
		}
		if ((y > 40 && y < 60 && msg.is_left() && x>910) || keystate(51))//蓝色
		{
			zuo();
			setfillcolor(BLUE);
			square[barnumber].c = 3;
			break;
		}
		if ((y > 60 && y < 80 && msg.is_left() && x>910) || keystate(52))//黄色
		{
			zuo();
			setfillcolor(YELLOW);
			square[barnumber].c = 4;
			break;
		}
		if ((y > 80 && y < 100 && msg.is_left() && x>910) || keystate(53))//白色
		{
			zuo();
			setfillcolor(EGERGB(255, 255, 255));
			square[barnumber].c = 5;
			break;
		}
	}
	//在这里进行矩形的绘出
	bar(square[barnumber].x1,
		square[barnumber].y1,
		square[barnumber].x2,
		square[barnumber].y2);
	//eraser();曾进行过橡皮功能的测试
	char s[255];//以下为存储
	sprintf(s, "BAR\\BAR%d.txt", barnumber);
	FILE *fp = fopen(s, "w");
	fprintf(fp, "%3d,%3d,%3d,%3d,%3d",
		square[barnumber].x1,
		square[barnumber].y1,
		square[barnumber].x2,
		square[barnumber].y2,
		square[barnumber].c);
	fclose(fp);//存储矩形结构体的数值的数值
	you();
	clearviewport();
	xyprintf(0, 0, "是否重画前一个矩形");//以下为重画
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
		if (y > 30 && y < 50 && msg.is_left() && x>910)//画上一个，用 【数量-1】 
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
		if (y > 50 && y < 70 && msg.is_left() && x>910)//退出
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
	barnumber++;//计数+1s
}