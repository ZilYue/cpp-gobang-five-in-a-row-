#pragma once
#include <graphics.h>
class stone {
protected:
	int radius;
public:
	stone() : radius(18){}
};

class whiteStone : public stone {
public:
    void printStone(int a, int b);
};

class blackStone : public stone {
public:
	void printStone(int a, int b);
};