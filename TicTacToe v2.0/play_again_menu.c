#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

#include "Header.h"

void draw_play_again(HANDLE hStdOut, char* str, int choose_pos) { // ����� � ������������ ������� �����

	title(hStdOut); // ���������

	COORD cursorPos;
	cursorPos.X = (CONSOLE_WIDTH - strlen(str)) / 2;
	cursorPos.Y = CONSOLE_HEIGHT / 2 - 2;

	SetConsoleCursorPosition(hStdOut, cursorPos); // �������� ��������� ������
	SetConsoleTextAttribute(hStdOut, BLACK_WHITE); // ��� - �����, ����� - ������

	printf("%s", str); // ����� �����������

	 // ���� ���������� ��������
	int yes_color = BLACK_WHITE, no_color = BLACK_WHITE; 
	switch (choose_pos) {
	case 1: { yes_color = WHITE_GREEN; break; }
	case 2: { no_color = WHITE_GREEN; break; }
	}

	// ���������
	cursorPos.Y += 3;
	cursorPos.X = CONSOLE_WIDTH / 3 - 4;
	SetConsoleCursorPosition(hStdOut, cursorPos);
	SetConsoleTextAttribute(hStdOut, no_color);
	printf(" == NO == ");

	cursorPos.X = CONSOLE_WIDTH / 3 * 2 - 5;
	SetConsoleCursorPosition(hStdOut, cursorPos);
	SetConsoleTextAttribute(hStdOut, yes_color);
	printf(" == YES == ");

	SetConsoleTextAttribute(hStdOut, BLACK_WHITE);
}

int play_again_menu(HANDLE hStdOut) { // ����� � ������������ ������� �����

	int choose_pos = 1;
	int iKey = 0;

	while (iKey != KEY_ENTER) { // ���� �� ����� Enter

		system("cls");
		draw_play_again(hStdOut, (char*)"Do you wanna play again?:", choose_pos);  // ������ �����

		 // ������������ ������� �������
		iKey = _getch();
		if (iKey == KEY_ARROW_RIGHT) choose_pos++;
		if (iKey == KEY_ARROW_LEFT) choose_pos--;
		if (choose_pos < 1) choose_pos = 2;
		if (choose_pos > 2) choose_pos = 1;
	}

	return choose_pos;
}