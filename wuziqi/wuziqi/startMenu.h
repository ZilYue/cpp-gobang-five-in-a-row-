#pragma once
class startMenu {
private:
	int width;
	int height;
public:
	int x1, x2, y1, y2;
	startMenu():width(200),height(300),x1(15),y1(235),x2(185),y2(285){}
	//顶上留55，其余按键间隔5
	int StartMenu();
	void selectText(int cnt);
	int mouseRet();
	void reset();
	int senteorgote();
	void sgselectText(int cnt);
	int sgmouseRet();

};