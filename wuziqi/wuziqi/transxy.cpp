#include <easyx.h>
#include "transxy.h"

void transxy::getxy(int a, int b) {
	x = a;
	y = b;
}

void transxy::resetxy() {
	x = -1;
	y = -1;
}

void transxy::getmousexy(int* a, int* b) {
	start:
	resetxy();
	ExMessage msg;
	int tempx = -1;
	int tempy = -1;
	while ((tempx == -1) || (tempy == -1)) {
		if (peekmessage(&msg, EX_MOUSE) && msg.message == WM_LBUTTONDOWN) {
			tempx = msg.x;
			tempy = msg.y;
		}
	}
	for (int i = 1; i <= 15; i++) {
		if ((41 * i - 18) <= tempx && tempx <= (41 * i + 18)) {
			x = i;
		}
		if ((41 * i - 18) <= tempy && tempy <= (41 * i + 18)) {
			y = i;
		}
	}
	if ((x == -1) || (y == -1)) {
		goto start;
	}else{
		*a = x;//从0开始的坐标
	    *b = y;
	}
}
