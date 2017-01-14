//橡皮功能，受自由铅笔线的启发，读出鼠标状态后，用视窗和清楚视窗来实现局部橡皮，和铅笔一样实用
#include<graphics.h>
#include"handletrans.h"
extern mouse_msg msg;
void eraser()
{
	Sleep(500);//防止误触，还可以更短，但是怕不安全（总觉得进出不好，容易不明不白）
	you();
	clearviewport();
	xyprintf(0, 0, "按两下Ctrl退出橡皮");
	zuo;
	int x = 0, y = 0;
	for (; is_run(); /*delay_fps(10000)*/)//监视鼠标，可惜循环不够快，算法问题，无法适应高速移动的鼠标
	{
		//msg = getmouse();
		if (keystate(0x1))//如果左键按下
		{
			zuo();
			while (mousemsg())
			{
				msg = getmouse();
			}
			x = msg.x;
			y = msg.y;//取得鼠标所在位置的xy
			setviewport(x - 10, y - 10, x + 10, y + 10);//以鼠标为中心，建立一个20x20小视窗
			clearviewport();//橡皮核心
			//if (keystate(VK_CONTROL) == 1)break;
		}
		if (keystate(VK_CONTROL) == 1)break;//跳出循环
	}
}