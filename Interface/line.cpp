//ֱ�ߣ�����x1y1x2y2���洢
#include<graphics.h>
#include"line.h"
#include<stdio.h>
#include"handletrans.h"
int linenumber = 0;
void drawline()
{
	flushkey();
	you();
	xyprintf(0, 100, "������x1(���س�)");
	ll[linenumber].x1 = getInteger();
	setfont(-15, 0, "����");
	xyprintf(0, 100, "������y1(���س�)");
	ll[linenumber].y1 = getInteger();
	setfont(-15, 0, "����");
	xyprintf(0, 100, "������x2(���س�)");
	ll[linenumber].x2 = getInteger();
	setfont(-15, 0, "����");
	xyprintf(0, 100, "������y2(���س�)");
	ll[linenumber].y2 = getInteger();
	setfont(-15, 0, "����");
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
	fclose(fp);//�洢ֱ�߽ṹ�����ֵ����ֵ
	linenumber++;
}