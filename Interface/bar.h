#pragma once
void drawabar();
struct barstruct//用来储存矩形的结构体
{
	int x1;
	int y1;
	int x2;
	int y2;
	int c;
};
extern struct barstruct square[10];
extern int barnumber;//用来计数来方便存储txt数据文件