#include <ShlObj.h>
#include "stdafx.h"
#include "share.h"


void view(double red, double green, double blue) {

	int a = 15;
	start_color();	//色を設定するモードになる
	for (int i = 1; i < a; i++) {
		init_color(i, red*(int)(i * 1000 / a), green*(int)(i * 1000 / a), blue*(int)(i * 1000 / a));
		init_pair(i, i, i);
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {

			attrset(COLOR_PAIR(board[i][j]));			// 色1 を使う
			mvaddstr(i, j, " ");
			if (board[i][j] > 0) {
				board[i][j] -= 1;
			}

		}
	}
}