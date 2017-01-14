#include<graphics.h>
void zuo()//设置左右操作区域
{
	setviewport(0, 0, 906, 640, 1);
}
void you()
{
	setviewport(910, 0, 1190, 640, 1);
}
void reac()//设置全屏视窗，用来画线，保持界面完整
{
	setviewport(0, 0, 1200, 650, 1);
}