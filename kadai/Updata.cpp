#include <ShlObj.h>
#include "stdafx.h"

#include "share.h"

void update() {
	for (int k = 0; k < num; k++) {

		struct circle tmp = circle_list[k];

		for (int i = 0; i < height; i++) {

			for (int j = 0; j < width; j++) {
				if (tmp.step == (int)(sqrt((tmp.x - j) * (tmp.x - j) + (tmp.y - i) * (tmp.y - i)))) {
					board[i][j] += 8;
					if (board[i][j] > 15) {
						board[i][j] = 15;
					}
				}
			}
		}
		tmp.step = tmp.step + 1;
		circle_list[k] = tmp;
	}
}