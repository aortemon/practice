#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include "Header.h"


int** init_board() {  // Инициализация нового поля для игры
	int** board = (int**)malloc(3 * sizeof(int*));
	for (int i = 0; i < 3; i++) {
		board[i] = (int*)malloc(3 * sizeof(int));
		for (int j = 0; j < 3; j++) {
			board[i][j] = 0;
		}
	}
	return board;
}

void print(HANDLE hStdOut, int** board) { // Вывод текущего поля

	system("cls"); // Очистка консоли

	title(hStdOut);  // Заголовок

	COORD cursor_pos;
	cursor_pos.X = CONSOLE_WIDTH / 2 - 7;
	cursor_pos.Y = CONSOLE_HEIGHT / 2 - 4;

	SetConsoleTextAttribute(hStdOut, BLACK_WHITE);  // Установка черного текста и белого фона

	for (int i = 0; i < 3; i++) { // отрисовка
		SetConsoleCursorPosition(hStdOut, cursor_pos);
		printf("-------------");
		cursor_pos.Y++;
		SetConsoleCursorPosition(hStdOut, cursor_pos);
		printf("|");
		for (int j = 0; j < 3; j++) printf(" %c |", board[i][j] == 0 ? ' ' : board[i][j] == 1 ? 'X' : 'O');
		cursor_pos.Y++;
	}
	SetConsoleCursorPosition(hStdOut, cursor_pos);
	printf("-------------");
}

void set(int** board, COORD pos, int sign) {  // установка в клетку pos знака sign
	board[pos.X][pos.Y] = sign;
}

int is_free(int** board, COORD pos) {  // 1 - если клетка pos свободна, 0 - если занята
	if (board[pos.X][pos.Y] == 0) return 1;
	return 0;
}


int is_win(int** board) { // -1 - если победных комбинаций нет, знак победившего - если они есть
	for (int i = 0; i < 3; i++) if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] > 0) return board[i][0];
	for (int i = 0; i < 3; i++) if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] > 0) return board[0][i];
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] > 0) return board[0][0];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] > 0) return board[1][1];
	return -1;
}

int is_draw(int** board) { // 0 - если не ничья (есть свободные клетки), 1 - если ничья
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == 0) return 0;
		}
	}
	return 1;
}

int is_end(int** board) { // совокупная проверка на конец игры
	// 0 - не конец
	// 1 - победили крестики
	// 2 - победили ноликии
	// 3 - ничья
	int temp = is_win(board);
	if (temp != -1) return temp;
	temp = is_draw(board);
	if (temp) return 3;
	return 0;
}