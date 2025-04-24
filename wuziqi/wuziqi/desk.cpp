#include <easyx.h>
#include <Windows.h>
#include <iostream>
#include "desk.h"

void desk::printDesk() {
	initgraph(width, height);
	setbkcolor(RGB(213,200,160));
	cleardevice();
	printLines();
	printNoticeBoard();
	resetNote();
	//system("pause");
}
void desk::printLines() {
	int x1 = 41, y1 = 41, x2, y2;
	setlinecolor(BLACK);
	for (x2 = 615, y2 = 41; y2 <= 615; y2 += 41) {
		line(x1, y1, x2, y2);
		y1 += 41;
	}
	x1 = 41;
	y1 = 41;
	for (x2 = 41, y2 = 615; x2 <= 615; x2 += 41) {
		line(x1, y1, x2, y2);
		x1 += 41;
	}
}

void desk::printNoticeBoard() {
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillroundrect(x1, y1, x2, y2, 5, 5);
}

void desk::printNote(int cnt) {
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	RECT r = { x3, y3, x4, y4 };
	switch (cnt) {
	case 0:
		drawtext(_T("先手胜利"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		y3 += 31;
		y4 += 31;
		break;
	case 1:
		drawtext(_T("后手胜利"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		y3 += 31;
		y4 += 31;
		break;
	case 2:
		drawtext(_T("你已经下过这里了"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		y3 += 31;
		y4 += 31;
		break;
	case 3:
		drawtext(_T("不要这样先生!(摆手"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		y3 += 31;
		y4 += 31;
		break;
	case 4:
		drawtext(_T("电脑胜利"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		y3 += 31;
		y4 += 31;
		break;
    case 5:
		drawtext(_T("玩家胜利"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		y3 += 31;
		y4 += 31;
		break;
	case -1:
		drawtext(_T("待开发"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	
	if (y4 > 598) {
		resetNote();
	}
}

void desk::resetNote() {
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillroundrect(x1, y1, x2, y2, 5, 5);
	x3 = 635;
	y3 = 41;
	x4 = 937;
	y4 = 71;
}

int desk::ifexit() {
	resetNote();
	x3 += 30;
	x4 -= 30;
	y3 += 15;
	y4 += 45;
	for (int i = 0; i < 3; i++) {
		setlinecolor(BLACK);
		setfillcolor(WHITE);
		fillroundrect(x3, y3, x4, y4, 5, 5);
		ifexittext(i);
		y3 += 76;
		y4 += 76;
	}
	int exitn = getexitmouse();
	return exitn;
}

void desk::ifexittext(int cnt) {
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	RECT r = { x3, y3, x4, y4 };
	switch (cnt) {
	case 0:
		drawtext(_T("退出"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		break;
	case 1:
		drawtext(_T("再来一局"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		break;
	case 2:
		drawtext(_T("回到菜单"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		break;
	}
}

int desk::getexitmouse() {
	exitreset();
	x3 += 30;
	x4 -= 30;
	y3 += 15;
	y4 += 15;
	ExMessage msg;
	int menuNum = -1;
	while (menuNum == -1) {
		if (peekmessage(&msg, EX_MOUSE) && msg.message == WM_LBUTTONDOWN) {
			if (msg.x >= x3 && msg.x <= x4 && msg.y >= y3 && msg.y <= y4) {
				menuNum = 0;
			}
			else if (msg.x >= x3 && msg.x <= x4 && msg.y >= y3 + 76 && msg.y <= y4 + 76) {
				menuNum = 1;
			}
			else if (msg.x >= x3 && msg.x <= x4 && msg.y >= y3 + 76 * 2 && msg.y <= y4 + 76 * 2) {
				menuNum = 2;
			}
		}
	}
	//resetNote();
	//cleardevice();
	//closegraph();
	return menuNum;
}

void desk::exitreset() {
	x3 = 635;
	y3 = 41;
	x4 = 937;
	y4 = 101;
}