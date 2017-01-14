/*this program is made to welcome our customers*/

#include"readshape.h"
#include"readfile.h"
#include"menu.h"
#include"fillpoly.h"
#include<graphics.h>
#include<Windows.h>
#include"circlestruct.h"
#include"line.h"
#include"bar.h"
#include<stdio.h>
#include"mouselineandpoly.h"
#include"handletrans.h"
#include"pixelline.h"
struct CIRCLE a[10] = { 0 };
struct linestruct ll[10] = { 0 };
struct drawpoli poli[10] = { 0 };
struct barstruct square[10] = { 0 };
struct mouse_msg msg = { 0 };
int main(void)
{
	initgraph(1200, 650);//创建画布
	line(5, 0, 5, 645);
	line(5, 645, 1195, 645);
	line(1195, 0, 1195, 645);
	line(905, 0, 905, 645);//绘制画板的基本界面
	setviewport(0, 0, 1190, 640, 1);//设置边框，不过2017后没什么太大意义
	setbkcolor(EGERGB(255,255,255)); //设置背景颜色
	setcolor(BLACK);//设置字体颜色
	setfont(-15, 0, "楷体");//字体
	int x = 0,y = 0,pri = 1;//xy 用来记录鼠标  pri已经2017后过时，没有实际意义
	for (; is_run(); delay_fps(10))//循环体来保证程序持续运行
	{
		reac();//全屏视窗，然后划线
		setcolor(EGERGB(169, 167, 167));
		line(5, 0, 5, 645);
		line(5, 645, 1195, 645);
		line(1195, 0, 1195, 645);
		line(905, 0, 905, 645);
		setcolor(BLACK);//保持界面完整
		you();//进入右侧界面
		xyprintf(0, 0, "欢迎来到画板程序                            ");//欢迎界面
		xyprintf(0, 15, "是否读取  (按shift切换输入法至英文)");
		xyprintf(0, 50, "1.读取我的历史文件");
		xyprintf(0, 70, "0.新建画板");
		while (mousemsg())//如果鼠标有动作
		{
			msg = getmouse();
		}
		x = msg.x;
		y = msg.y;
		if ((y > 40 && y < 70 && msg.is_left() && x>910) || keystate(49))//这里为读取分支
		{
			you();
			flushkey();
			clearviewport();
			readfile();
			menu(pri, 1);
		}
		if ((y > 70 && y < 90 && msg.is_left() && x>910) || keystate(50))//新建分支
		{
			you();
			flushkey();
			clearviewport();
			menu2();
		}
	}
	//下面的是键盘按键操作的代码，已经过了时效期
	/*if (pri == 1)//读取文件
	{
	d = 1;
	readpoly();
	menu(pri, d);
	}
	else if (pri == 0)//新建画板
	{
	menu2();
	}
	/*you();
	xyprintf(20, 10, "是否退出画板程序  ");
	xyprintf(20, 30, "1.退出");
	xyprintf(20, 50, "0.否  ");
	int y = 0;
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
	if (y > 30 && y < 50)
	{
	break;
	}
	if (y > 50 && y < 70)
	{

	}
	zuo();*/
	/*chc = getch();
	if (chc == '1')
	break;*/
	return 0;
}
