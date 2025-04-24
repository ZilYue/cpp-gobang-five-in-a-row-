#pragma once
class transxy {
public:
	int x;
	int y;
	transxy():x(-1),y(-1){}
	void resetxy();
	void getxy(int a, int b);
	void getmousexy(int *a, int *b);
};