// kadai.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B

#include <ShlObj.h>
#include "targetver.h"
#include "stdafx.h"
#include "share.h"
#include <stdio.h>
#include <Windows.h>

#define CHARBUFF 124

int num = 0;

int  x, y, w, h;
int board[height][width];
circle circle_list[100];

void getCurrentDirectory(char *currentDirectory) {
	GetCurrentDirectory(CHARBUFF, currentDirectory);
}

int main(int argc, char* argv[])


{
	double red = 0;
	double blue = 0;
	double green = 0;

	char currentDirectory[CHARBUFF];
	getCurrentDirectory(currentDirectory);

	char section[CHARBUFF];
	sprintf_s(section, "color");
	char keyWord[CHARBUFF];
	
	char settingFile[CHARBUFF];
	sprintf_s(settingFile, "%s\\setting.ini", currentDirectory);

	sprintf_s(keyWord, "red");
	red = GetPrivateProfileInt(section, keyWord, -1, settingFile);

	sprintf_s(keyWord, "green");
	green = GetPrivateProfileInt(section, keyWord, -1, settingFile);

	sprintf_s(keyWord, "blue");
	blue = GetPrivateProfileInt(section, keyWord, -1, settingFile);

	if (initscr() == NULL) {
		return 1;
	}
	int count = 0;
	int  key;
	keypad(stdscr, TRUE);
	getmaxyx(stdscr, h, w);
	y = h / 2;
	x = w / 2;
	timeout(0);
	curs_set(0);

	while (1) {
		erase();
		view(red,green,blue);
		move(y, x);
		addstr("_");
		update();

		refresh();
		key = getch();
		if (key == 'x') {
			struct circle tmp = { x, y, 0 };
			circle_list[num] = tmp;
			num++;
			count++;
		}
		else if (key == 'c') {
			struct circle tmp = { 80, 35, 0 };
			circle_list[num] = tmp;
			num++;
			count++;
		}
		else if (key == 'z') {
			struct circle tmp = { 20, 15, 0 };
			circle_list[num] = tmp;
			num++;
			count++;
		}

		switch (key) {
		case KEY_UP:	y--; break;
		case KEY_DOWN:	y++; break;
		case KEY_LEFT:	x--; break;
		case KEY_RIGHT:	x++; break;
		}

		FILE* fp2;

		errno_t error;

		error = fopen_s(&fp2, "result.txt", "w");
		if (error != 0) {
			fprintf_s(stderr, "failed to open\n");
		}
		else {
			char s[CHARBUFF];
			sprintf_s(s, "�ŏI���ʁF���݂̃J�[�\���ʒu�́i%d�A%d�j�A�g�������������񐔂́@%d�@��", x, y, count);
			fputs(s, fp2);
		}fclose(fp2);

	}
	return 0;
}