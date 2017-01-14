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
		setcolor(BLACK);//用来保护界面
		you();
		xyprintf(0, 0, "欢迎使用画板程序              ");
		xyprintf(0, 240, "做些啥好呢");
		xyprintf(0, 260, "1.重画");
		xyprintf(0, 280, "2.画一个多边形");
		xyprintf(0, 300, "3.画一个圆");
		xyprintf(0, 320, "4.画一条线");
		xyprintf(0, 340, "5.画一个矩形");
		xyprintf(0, 360, "6.用鼠标画线或多边形");
		xyprintf(0, 380, "7.鼠绘");
		xyprintf(0, 400, "8.橡皮");
		xyprintf(0, 420, "9.后退");
		while (mousemsg())
		{
			msg = getmouse();
		}
		x = msg.x;
		y = msg.y;

		if ((y > 260 && y < 280 && msg.is_left() && x>910) || keystate(49))//清左侧屏幕分支
		{
			zuo();
			clearviewport();
			you();
		}
		if ((y > 280 && y < 300 && msg.is_left() && x>910) || keystate(50))//画多边形分支
		{
			zuo();
			drawapoli();
			you();
		}
		if ((y > 300 && y < 320 && msg.is_left() && x>910) || keystate(51))//画圆分支
		{
			zuo();
			drawcircle();
			you();
		}
		if ((y > 320 && y < 340 && msg.is_left() && x>910) || keystate(52))//画直线分支
		{
			zuo();
			drawline();
			you();
		}
		if ((y > 340 && y < 360 && msg.is_left() && x>910) || keystate(53))//画矩形分支
		{
			zuo();
			drawabar();
			you();
		}
		if ((y > 360 && y < 380 && msg.is_left() && x>910) || keystate(54))//鼠标画多边形和直线
		{
			zuo();
			mouse();
			you();
		}
		if ((y > 380 && y < 400 && msg.is_left() && x>910) || keystate(55))//鼠标画任意线
		{
			zuo();
			pixelline();
			you();
		}
		if ((y > 400 && y < 420 && msg.is_left() && x>910) || keystate(56))//橡皮
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
	{xyprintf(0, 380, "再想想你要选哪个"); }
	}
	you();*/
	/*xyprintf(0, 220, "还继续画吗，1.否 0.是              ");
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
		setcolor(BLACK);//这是用来保护界面的
		you();
		xyprintf(0, 0, "欢迎使用画板程序              ");
		xyprintf(0, 240, "做些啥好呢（按下相应数字选择）");//输出选项让用户选择
		xyprintf(0, 260, "1.清屏");
		xyprintf(0, 280, "2.画一个多边形");
		xyprintf(0, 300, "3.画一个圆");
		xyprintf(0, 320, "4.画一条线");
		xyprintf(0, 340, "5.画一个矩形");
		xyprintf(0, 360, "6.用鼠标画线或多边形");
		xyprintf(0, 380, "7.鼠绘");
		xyprintf(0, 400, "8.橡皮");
		xyprintf(0, 420, "9.后退");
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
	//曾经的键盘键入选择，已经遗弃
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
	xyprintf(0, 360, "再想想你要选哪个");
	zuo();
	}
	}
	you();
	xyprintf(0, 0, "还继续画吗，1.是 0.否                                            ");
	chc = getch();
	zuo();
	if (chc == '0')
	break;*/
	return 0;
}