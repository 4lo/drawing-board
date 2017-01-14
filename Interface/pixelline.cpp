//2017年完成的第一个大事，终于把任意线搞出来了
#include<graphics.h>
#include"handletrans.h"
extern mouse_msg msg;
int pixelline()
{
	you();
	clearviewport();
	xyprintf(0, 0, "（按住Ctrl再开始画）");
	xyprintf(0, 20, "（松手即退出）");
	zuo(); 
	int i = 1, x[100000] = { 0 }, y[100000] = {0},*p1,*p2;//定义足够大的数组来存储鼠标
	p1 = &x[i];
	p2 = &y[i];
	getkey();
	getmouse();
	mousepos(p1, p2);//获取当前鼠标位置并用指针存储，避免了从原点画线的尴尬
	i++;

	for (; is_run(); /*delay_fps(10000)*/)
	{
		p1 = &x[i];//持续获得
		p2 = &y[i];
		msg = getmouse();
		if (keystate(0x1))
		{
			mousepos(p1, p2);
			line(x[i], y[i], x[i - 1], y[i - 1]);
			i++;
			flushmouse();//这种flush好像和我理解的不一样，目测没有用
			flushkey();
			//if (keystate(VK_CONTROL) == 0)
			//break;
		}
		if (keystate(VK_CONTROL) == 0)//Ctrl弹开则退出
			break;
	}
	flushmouse();
	flushkey();//目测没用
	you();
	clearviewport();//清屏
	return 0;

}