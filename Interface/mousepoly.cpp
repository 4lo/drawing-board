#include<graphics.h>
int mousepoly()
{	
	int *x, *y,x1 = 0, y1 = 0;
	mouse_msg msg = { 0 };
	x = &x1, y = &y1;
	getmouse();
	while (mousemsg())
		mousepos(x, y);
	xyprintf(200, 300, "%d,%d", x1, y1);
	return 0;
}