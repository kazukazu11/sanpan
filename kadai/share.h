#pragma once

#include "stdafx.h"
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define width  100
#define height  50

void view(double red, double green, double blue);
void update();
extern int num;

extern int board[height][width];

struct circle {
	int x;
	int y;
	int step;
};


extern circle circle_list[100];