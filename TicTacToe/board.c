#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

#include "Header.h"

struct COORD sequence[9] = { {1, 1}, {0, 0}, {0, 2}, {2, 0}, {2, 2}, {0, 1}, {1,0}, {1, 2}, {2, 1} };



int** board_init() {
	int** board = (int**)malloc(SIZE * sizeof(int*));
	for (int i = 0; i < SIZE; i++) {
		board[i] = (int*)malloc(SIZE * sizeof(int));
		for (int j = 0; j < SIZE; j++) board[i][j] = 0;
	}
	return board;
}


void set(int** board, COORD xy, int sign) {
	board[xy.X][xy.Y] = sign;
}

int is_win(int** board) {
	for (int i = 0; i < SIZE; i++) if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] > 0) return board[i][0];
	for (int i = 0; i < SIZE; i++) if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] > 0) return board[0][i];
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] > 0) return board[0][0];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] > 0) return board[1][1];
	return -1;
}

struct COORD find_win_step(int** board, int sign) {
	struct COORD result;
	result.x = -1;
	result.y = -1;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] > 0) continue;
			board[i][j] = sign;
			if (is_win(board) > 0) {
				result.x = i;
				result.y = j;
				board[i][j] = 0;

				return result;
			}
			board[i][j] = 0;
		}
	}
}

int is_draw(int** board) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) if (board[i][j] == 0) return 0;
	}
	return 1;
}

void comp_move(int** board, int comp_sign, int user_sign) {
	struct COORD result = { -15, -15 };
	result = find_win_step(board, comp_sign);
	printf("\n>>> [ %d %d ]\n", result.x, result.y);
	print(board);
	if (result.x >= 0 && result.x <= 2) {
		set(board, result, comp_sign); 
		return;
	}
	result = find_win_step(board, user_sign);
	if (result.x >= 0 && result.x <= 2) {
		set(board, result, comp_sign);
		return;
	}
	for (int i = 0; i < 9; i++) {
		if (board[sequence[i].x][sequence[i].y] == 0) {
			set(board, sequence[i], comp_sign); 
			break;
		}
	}
}

int is_end(int** board) {
	// 0 - не конец
	// 1 - победили крестики
	// 2 - победили нолики
	// 3 - ничья
	int win = is_win(board);
	if (win > 0) return win;
	int draw = is_draw(board);
	if (draw == 1) return 3;
	return 0;

}