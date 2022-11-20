#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

#include "Header.h"

void draw_square(HANDLE hStdOut, int** board, COORD pos) {

	print(hStdOut, board);
	
	COORD cursor_pos;
	cursor_pos.X = CONSOLE_WIDTH / 2 - 7 + pos.X * 4;
	cursor_pos.Y = CONSOLE_HEIGHT / 2 - 4 + pos.Y * 2;

	if (board[pos.Y][pos.X] > 0) SetConsoleTextAttribute(hStdOut, WHITE_RED); // Подсветка красным, если ход невозможен
	else SetConsoleTextAttribute(hStdOut, WHITE_GREEN); // Подсветка зеленым, если ход возможен

	 // Отрисовываем текущую выбранную клетку
	SetConsoleCursorPosition(hStdOut, cursor_pos);
	printf("-----");
	cursor_pos.Y++;
	SetConsoleCursorPosition(hStdOut, cursor_pos);
	printf("| %s |", board[pos.Y][pos.X] == 0 ? " " : board[pos.Y][pos.X] == 1 ? "X" : "O");
	cursor_pos.Y++;
	SetConsoleCursorPosition(hStdOut, cursor_pos);
	printf("-----");
	SetConsoleTextAttribute(hStdOut, BLACK_WHITE);
}

COORD choose_square(HANDLE hStdOut, int** board) {

	int iKey = 0;
	COORD pos;
	pos.X = 1;
	pos.Y = 1;

	while (iKey != KEY_ENTER) { // Выбираем клетку, пока не надан Enter
		if (iKey == KEY_ARROW_DOWN) pos.Y++;
		if (iKey == KEY_ARROW_UP) pos.Y--;
		if (iKey == KEY_ARROW_RIGHT) pos.X++;
		if (iKey == KEY_ARROW_LEFT) pos.X--;
		if (pos.X < 0) pos.X = 2;
		if (pos.X > 2) pos.X = 0;
		if (pos.Y < 0) pos.Y = 2;
		if (pos.Y > 2) pos.Y = 0;
		draw_square(hStdOut, board, pos); // Отрисовка текущего поля и выбора
		iKey = _getch();
	}
	// Меняем X и Y местами
	int temp = pos.X;
	pos.X = pos.Y;
	pos.Y = temp;

	return pos;

}