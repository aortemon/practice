#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#include "Header.h"

// 0 - пусто
// 1 - крестик 
// 2 - нолик

int main() {
	setlocale(LC_ALL, "rus");
	struct GAMEDATA data = start();
	int** board = board_init();
	while (1) {
		if (data.user_sign == 1) {
			while (is_end(board) == 0) {
				print(board);
				get_user_move(board, data.user_sign);
				if (is_end(board) != 0) break;
				comp_move(board, data.comp_sign, data.user_sign);
				system("cls");
			}
		}
		if (data.user_sign == 2 && is_draw(board) == 0) {
			while (is_end(board) == 0) {
				comp_move(board, data.comp_sign, data.user_sign);
				system("cls");
				print(board);
				if (is_end(board) != 0) break;
				get_user_move(board, data.user_sign);
			}
		}
		int end = is_end(board);
		if (end == 3) {
			printf("\n\tНичья!");
			system("pause");
			if (is_play_again()) {
				data = start();
				board = board_init();
			}
			else break;
		}
		else if (end == data.comp_sign) {
			printf("\n\tВы проиграли!");
			system("pause");
			if (is_play_again()) {
				data = start();
				board = board_init();
			}
			else break;
		}
		else if (end == data.user_sign) {
			printf("\n\tВы победили!");
			system("pause");
			if (is_play_again()) {
				data = start();
				board = board_init();
			}
			else break;
		}
		else printf("%d", end);


	}
	printf("\tПока!\n");
	system("pause");
}