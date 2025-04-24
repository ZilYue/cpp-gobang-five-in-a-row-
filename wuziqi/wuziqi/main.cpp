#include <iostream>
#include <easyx.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<cstdlib>
#define N 15
#include "desk.h"
#include "stone.h"
#include "startMenu.h"
#include "transxy.h"
startMenu sm;
desk md;
transxy tr;
whiteStone ws;
blackStone bs;
//md.printNote(int cnt); 0先手,1后手,2下原位,3不要这样,4玩家,5电脑

int ifEnd(char p[N][N], int y, int x) {//'0'是没有赢,'1'是玩家赢,'2'是电脑赢 
	int end = 0;
	char ck = p[y][x];

	if (p[y + 1][x] == ck && p[y + 2][x] == ck && p[y + 3][x] == ck && p[y + 4][x] == ck && y + 4 < N) {
		end = 1;
	}
	if (p[y][x + 1] == ck && p[y][x + 2] == ck && p[y][x + 3] == ck && p[y][x + 4] == ck && x + 4 < N) {
		end = 1;
	}
	if (p[y + 1][x + 1] == ck && p[y + 2][x + 2] == ck && p[y + 3][x + 3] == ck && p[y + 4][x + 4] == ck && y + 4 < N && x + 4 < N) {
		end = 1;
	}
	if (p[y + 1][x - 1] == ck && p[y + 2][x - 2] == ck && p[y + 3][x - 3] == ck && p[y + 4][x - 4] == ck && x - 4 >= 0) {
		end = 1;
	}

	if (ck == '0' && end == 1) {
		end = 2;
	}
	return end;
}

int crossDesk(char p[N][N]) {//遍历棋盘 
	int end = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (p[i][j] != '-') {
				end = ifEnd(p, i, j);
				if (end > 0) break;
			}
		}
		if (end > 0) break;
	}
	return end;
}

int ifWin(char p[N][N]) {
	int end = crossDesk(p);
	int flag = 1;
	switch (end) {
	case 0:
		break;
	case 1:
		//printf("玩家胜利\n");
		md.printNote(1);
		flag = 0;
		break;
	case 2:
		//printf("电脑胜利\n");
		md.printNote(0);
		flag = 0;
		break;
	}
	return flag;
}
int doublegameprocess() {//输入先手后手信息
start:
	char desk[N][N];
	memset(desk, '-', 15 * 15);
	int flag = 1;
	//printdesk(desk);
	int ifstarted = -1;
	while (flag) {
		
	a:
		/*
		char tempx;
		int y;
		getchar();
		printf("输入x坐标:");
		scanf("%c", &tempx);
		// 处理输入缓冲区中的换行符
		getchar();
		printf("输入y坐标:");
		scanf("%d", &y);
		int x = tempx - 'a';
		*/
		int x = -1;
		int y = -1;
		int *px = &x;
		int *py = &y;
		tr.getmousexy(px, py);
		if (x < 0 || x > N || y < 1 || y > N) {
			//printf("坐标输入错误\n");
			goto a;
		}
		else if (desk[y - 1][x - 1] == '#') {
			//printf("你已经下过这里了\n");
			md.printNote(2);
			goto a;
		}
		else if (desk[y - 1][x - 1] == '0') {
			//printf("不要这样先生!(摆手\n");
			md.printNote(3);
			goto a;
		}
		else {
			desk[y - 1][x - 1] = '#';
			bs.printStone(x, y);
			//printdesk(desk);
		}
		//int end = ifEnd(desk,y,x);
		//flag = ifWin(desk,end);
		flag = ifWin(desk);
		if (flag == 0) {
			int next = md.ifexit();
			return next;
		}

	b:
		//printf("现在你帮电脑下\n");
		/*
		char tempx1;
		int y1;
		getchar();
		printf("输入x坐标:");
		scanf("%c", &tempx1);
		// 处理输入缓冲区中的换行符
		getchar();
		printf("输入y坐标:");
		scanf("%d", &y1);
		int x1 = tempx1 - 'a';
		*.
		*/
		int x1 = -1;
		int y1 = -1;
		int* px1 = &x1;
		int* py1 = &y1;
		tr.getmousexy(px1, py1);
		if (x1 < 0 || x1 > N || y1 < 1 || y1 > N) {
			//printf("坐标输入错误\n");
			goto b;
		}
		else if (desk[y1 - 1][x1 - 1] == '0') {
			//printf("你已经下过这里了\n");
			md.printNote(2);
			goto b;
		}
		else if (desk[y1 - 1][x1 - 1] == '#') {
			//printf("不要这样先生!(摆手\n");
			md.printNote(3);
			goto b;
		}
		else {
			desk[y1 - 1][x1 - 1] = '0';
			ws.printStone(x1, y1);
			//printdesk(desk);
		}
		//end = ifEnd(desk,y1,x1);
		//flag = ifWin(desk,end);
		flag = ifWin(desk);
		if (flag == 0) {
			int next = md.ifexit();
			return next;
		}

	}
	//getchar();

	goto start;
}

int main() {
	menu:
	int sog = -1;
	int mode = sm.StartMenu();
	int next;
	switch (mode) {
	case 0:
		std::exit(0);
	case 1://双人,没有人机
		origin:
		//sog = sm.senteorgote();//0后手,1先手
		md.printDesk();
		next = doublegameprocess();
		switch (next) {
		case 0:
			std::exit(0);
		case 1:
			goto origin;
		default:
			break;
		}
		break;
	case 2://单人人机未开发
		sog = sm.senteorgote();
		md.printDesk();
		md.printNote(-1);
		system("pause");
		break;
	}
	if (next == 2) {
		goto menu;
	}
}

/*
int main() {
	md.printDesk();
	int x = 7;
	int y = 7;
	int sog = 0;
	if (sog == 0) {//玩家后手白棋
		ws.printStone(x, y);
	}
	else {
		bs.printStone(x, y);
	}
	system("pause");
}
*/


