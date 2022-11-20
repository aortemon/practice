#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

#include "Header.h"

COORD* moves() { // Приоритет ходов компьютера
	COORD* seq = (COORD*)malloc(9 * sizeof(COORD));
	seq[0] = (COORD){ 2, 0 };
	seq[1] = (COORD){ 0, 0 };
	seq[2] = (COORD){ 0, 2 };
	seq[3] = (COORD){ 1, 1 };
	seq[4] = (COORD){ 2, 2 };
	seq[5] = (COORD){ 0, 1 };
	seq[6] = (COORD){ 1, 0 };
	seq[7] = (COORD){ 1, 2 };
	seq[8] = (COORD){ 2, 1 };
	return seq;
}

COORD find_win_step(int** board, int sign) { // Поиск победного хода для знака sign
	COORD result;
	result.X = -1;
	result.Y = -1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] > 0) continue;
			board[i][j] = sign;
			if (is_win(board) > 0) {
				result.X = i;
				result.Y = j;
				board[i][j] = 0;

				return result;
			}
			board[i][j] = 0;
		}
	}
}

void comp_move(HANDLE hStdOut, int** board, int comp_sign, int user_sign) {  // Ход компьютера
	COORD* sequence = moves();
	COORD result;
	result.X = -15;
	result.Y = -15;

	result = find_win_step(board, comp_sign); // Ищем победный ход
	print(hStdOut, board);

	if (result.X >= 0 && result.X <= 2) { //  Победный ход, ечли есть
		set(board, result, comp_sign);
		return;
	}

	result = find_win_step(board, user_sign);  // Предупреждение победы пользователя
	if (result.X >= 0 && result.X <= 2) {
		set(board, result, comp_sign); // Предупреждаем, если можем
		return;
	}
	for (int i = 0; i < 9; i++) { // Делаем максимально приоритетный ход из возможных
		if (board[sequence[i].X][sequence[i].Y] == 0) {
			set(board, sequence[i], comp_sign);
			break;
		}
	}
}