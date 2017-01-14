//直线，超简单x1y1x2y2并存储
#include<graphics.h>
#include"line.h"
#include<stdio.h>
#include"handletrans.h"
int linenumber = 0;
void drawline()
{
	flushkey();
	you();
	xyprintf(0, 100, "请输入x1(按回车)");
	ll[linenumber].x1 = getInteger();
	setfont(-15, 0, "楷体");
	xyprintf(0, 100, "请输入y1(按回车)");
	ll[linenumber].y1 = getInteger();
	setfont(-15, 0, "楷体");
	xyprintf(0, 100, "请输入x2(按回车)");
	ll[linenumber].x2 = getInteger();
	setfont(-15, 0, "楷体");
	xyprintf(0, 100, "请输入y2(按回车)");
	ll[linenumber].y2 = getInteger();
	setfont(-15, 0, "楷体");
	zuo();
	line(ll[linenumber].x1, 
		ll[linenumber].y1, 
		ll[linenumber].x2,
		ll[linenumber].y2);
	char s[255];
	sprintf(s, "LINE\\LINE%d.txt", linenumber);
	FILE *fp = fopen(s, "w");
	fprintf(fp, "%3d,%3d,%3d,%3d", 
		ll[linenumber].x1, 
		ll[linenumber].y1, 
		ll[linenumber].x2, 
		ll[linenumber].y2);
	fclose(fp);//存储直线结构体的数值的数值
	linenumber++;
}