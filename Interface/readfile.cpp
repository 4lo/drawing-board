#include<stdio.h>
#include"handletrans.h"
#include<graphics.h>
#include"readshape.h"
#include"circlestruct.h"
extern mouse_msg msg;
int readfile()
{
	int x = 0, y = 0;
	for (; is_run(); delay_fps(10))
	{
		flushkey();
		you();
		xyprintf(0, 0, "欢迎使用画板程序              ");
		xyprintf(0, 240, "1读取多边形");
		xyprintf(0, 260, "2读取圆");
		xyprintf(0, 280, "3读取矩形");
		xyprintf(0, 300, "4读取直线");
		xyprintf(0, 500, "5退出读取");
		while (mousemsg())
		{
			msg = getmouse();
		}
		x = msg.x;
		y = msg.y;//获得鼠标坐标
		if ((y > 240 && y < 260 && msg.is_left() && x>910) || keystate(49))//读取多边形
		{
			you();
			clearviewport();
			readpoly();
		}
		if ((y > 260 && y < 280 && msg.is_left() && x>910) || keystate(50))//读取圆
		{

			you();
			clearviewport();
			readcircle();
		}
		if ((y > 280 && y < 300 && msg.is_left() && x>910) || keystate(51))//读取矩形
		{
			you();
			clearviewport();
			readbar();
		}
		if ((y > 300 && y < 320 && msg.is_left() && x>910) || keystate(52))//读取直线
		{
			you();
			clearviewport();
			readline();
		}
		if ((y > 500 && y < 520 && msg.is_left() && x>910) || keystate(53))//退出
		{
			you();
			clearviewport();
			return 0;
		}
	}
}