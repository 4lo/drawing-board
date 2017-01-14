#pragma once
void drawline();
struct linestruct//直线结构体
{
	int x1;
	int y1;
	int x2;
	int y2;
};
extern struct linestruct ll[10];
extern int linenumber; //用于记录直线线的个数，并且便于存储数据