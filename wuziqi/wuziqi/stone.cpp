#include <graphics.h>
#include "stone.h"
void whiteStone::printStone(int a,int b) {
	a = a * 41;
	b = b * 41;
	setlinecolor(WHITE);
	setfillcolor(WHITE);
	fillcircle(a, b, radius);
}

void blackStone::printStone(int a,int b) {
	a = a * 41;
	b = b * 41;
	setlinecolor(BLACK);
	setfillcolor(BLACK);
	fillcircle(a, b, radius);
}