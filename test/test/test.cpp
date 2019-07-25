//#include "stdafx.h"

#include "share.h"
#include <stdio.h>
#include <Windows.h>
#define CHARBUFF 124
int num = 0;

int  x, y, w, h;
int board[height][width];
circle circle_list[100];
int main(int argc, char* argv[])


{
	char currentDirectory[CHARBUFF];
	getGurrentDirectory(currentDirectory);
	char section[CHARBUFF];
	sprintf_s(section, "section1");
	char keyWord[CHARBUFF];
	sprintf_s(keyWord, "keyword1");
	char settingFile[CHARBUFF];
	sprintf_s(settingFile, "%s\\setting.ini", currentDirectory);
	fprint(stdout, "ss , sd\n", setngFile, GetPrivateProfleInt(secton, keyWord, -1, settingFile));

	if (initscr() == NULL) {
		return 1;
	}
	int  key;
	keypad(stdscr, TRUE);
	getmaxyx(stdscr, h, w);
	y = h / 2;
	x = w / 2;
	timeout(0);
	curs_set(0);

	while (1) {
		erase();
		view();
		move(y, x);
		addstr("_");
		update();
		//
		refresh();
		key = getch();
		if (key == 'x') {
			struct circle tmp = { x, y, 0 };
			circle_list[num] = tmp;
			num++;
		}
		else if (key == 'c') {
			struct circle tmp = { 80, 35, 0 };
			circle_list[num] = tmp;
			num++;
		}
		else if (key == 'z') {
			struct circle tmp = { 20, 15, 0 };
			circle_list[num] = tmp;
			num++;
		}

		switch (key) {
		case KEY_UP:	y--; break;
		case KEY_DOWN:	y++; break;
		case KEY_LEFT:	x--; break;
		case KEY_RIGHT:	x++; break;
		}


	}
	return 0;
}

