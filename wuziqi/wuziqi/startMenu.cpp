#include<graphics.h>
#include<string>
#include<cstdlib>
#include"startMenu.h"

int startMenu::StartMenu() {
	initgraph(width, height);
	setbkcolor(RGB(213, 200, 160));
	cleardevice();

	for (int i = 0; i < 3; i++) {
		setlinecolor(BLACK);
		setfillcolor(WHITE);
		fillroundrect(x1, y1, x2, y2, 5, 5);
		selectText(i);
		y1 -= 56;
		y2 -= 56;
	}
	reset();
	int ret = mouseRet();//0退出,1双人,2单人
	return ret;
}


void startMenu::selectText(int cnt) {
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	RECT r = { x1, y1, x2, y2 };
	switch (cnt) {
	case 0:
		drawtext(_T("退出"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		break;
	case 1:
		drawtext(_T("双人"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		break;
	case 2:
		drawtext(_T("单人"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		break;
	}
}

int startMenu::mouseRet() {
	ExMessage msg;
	int menuNum = -1;
	while (menuNum == -1) {
		if (peekmessage(&msg, EX_MOUSE) && msg.message == WM_LBUTTONDOWN) {
			if (msg.x >= x1 && msg.x <= x2 && msg.y >= y1 && msg.y <= y2) {
				menuNum = 0;
			}
			else if (msg.x >= x1 && msg.x <= x2 && msg.y >= y1 - 56 && msg.y <= y2 - 56) {
				menuNum = 1;
			}
			else if (msg.x >= x1 && msg.x <= x2 && msg.y >= y1 - 56 * 2 && msg.y <= y2 - 56 * 2) {
				menuNum = 2;
			}
		}
	}
	reset();
	cleardevice();
	//closegraph();
	return menuNum;
}

void startMenu::reset() {
	x1 = 15;
	y1 = 235;
	x2 = 185;
	y2 = 285;
}

//0为后手,1为先手
int startMenu::senteorgote() {
	for (int i = 0; i < 2; i++) {
		setlinecolor(BLACK);
		setfillcolor(WHITE);
		fillroundrect(x1, y1, x2, y2, 5, 5);
		sgselectText(i);
		y1 -= 56;
		y2 -= 56;
	}
	reset();
	int sgret = sgmouseRet();
	return sgret;
}

void startMenu::sgselectText(int cnt) {
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	RECT r = { x1, y1, x2, y2 };
	switch (cnt) {
	case 0:
		drawtext(_T("后手"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		break;
	case 1:
		drawtext(_T("先手"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		break;
	}
}

int startMenu::sgmouseRet() {
	ExMessage msg;
	int menuNum = -1;
	while (menuNum == -1) {
		if (peekmessage(&msg, EX_MOUSE) && msg.message == WM_LBUTTONDOWN) {
			if (msg.x >= x1 && msg.x <= x2 && msg.y >= y1 && msg.y <= y2) {
				menuNum = 0;
			}
			else if (msg.x >= x1 && msg.x <= x2 && msg.y >= y1 - 56 && msg.y <= y2 - 56) {
				menuNum = 1;
			}
		}
	}
	reset();
	cleardevice();
	closegraph();
	return menuNum;
}

