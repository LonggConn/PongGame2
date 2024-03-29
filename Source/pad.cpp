﻿#include "pad.h"



pad::pad()
{
}


pad::~pad()
{
}

pad::pad(float cx, float cy)
{
	px = cx;
	py = cy;
	padX = cx;
	padY = cy;
}

void pad::drawPad()
{
	COORD coord;
	coord.X = int(padX) - size;
	coord.Y = int(padY);
	SetConsoleCursorPosition(hOut, coord);
	for (int i = -size; i < size; ++i)
		cout << ' ';
	coord.X = int(px) - size;
	coord.Y = int(py);
	SetConsoleCursorPosition(hOut, coord);
	SetConsoleTextAttribute(hOut, 10);
	for (int i = -size; i < size; ++i)
		cout << '=';
	SetConsoleTextAttribute(hOut, 15);
	padX = px;
	padY = py;
}   //Vẽ thanh pad

void pad::controlPad1()
{
	if (GetAsyncKeyState(VK_LEFT)) {
		px -= 3;
	}
	else if (GetAsyncKeyState(VK_RIGHT)) {
		px += 3;
	}
}   //điều khiển thanh pad bằng hai phím trái và phải

void pad::controlPad2()
{
	if (GetAsyncKeyState(65)) {
		px -= 3;
	}
	else if (GetAsyncKeyState(68)) {
		px += 3;
	}
}   //điều khiển thanh pad bằng 2 phím "a" và "d"

void pad::addPlayerBoundaries()
{
	if (px < size + 1) {
		px = float(size + 1);
	}
	else if (px > 70 - size - 2) {
		px = float(70 - size - 2);
	}
}   //giới hạn thanh pad( dừng lại nếu chạm tường)
 
void pad::resetPad()
{
	px = float(70 / 2);
}   //đưa vị trí thanh pad về vị trí ban đầu nếu có người giành chiến thắng



