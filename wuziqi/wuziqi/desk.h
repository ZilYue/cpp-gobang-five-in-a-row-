#pragma once
class desk {
private:
	int width;
	int height;
	int x1;
	int y1;
	int x2;
	int y2;
public:
	int x3, y3, x4, y4;
	void resetNote();
	desk():width(957),height(655),x1(635),y1(41),x2(937),y2(615){}
	void printDesk();
	void printLines();
	void printNoticeBoard();
	void printNote(int cnt);
	int ifexit();
	void ifexittext(int cnt);
	int getexitmouse();
	void exitreset();
};

/*
    width = 957;
	height = 655;
	x1 = 635;
	y1 = 41;
	x2 = 937;
	y2 = 615;
*/