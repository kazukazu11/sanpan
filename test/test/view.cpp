//#include "stdafx.h"

#include "share.h"

void view() {
	int a = 15;
	start_color();	//�F��ݒ肷�郂�[�h�ɂȂ�
	for (int i = 1; i < a; i++) {
		init_color(i, (int)(i * 1000 / a), (int)(i * 1000 / a), (int)(i * 1000 / a));
		init_pair(i, i, i);
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {

			attrset(COLOR_PAIR(board[i][j]));			// �F1 ���g��
			mvaddstr(i, j, " ");
			if (board[i][j] > 0) {
				board[i][j] -= 1;
			}

		}
	}
}