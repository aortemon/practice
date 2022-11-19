#include <stdlib.h>
#include <stdio.h>

#include "Header.h"



int print(int** board) {
	printf("\t-------------\n");
	for (int i = 0; i < SIZE; i++) {
		printf("\t");
		for (int j = 0; j < SIZE; j++) {
			char sign;
			switch (board[i][j]) {
			case 0: { sign = ' '; break; }
			case 1: { sign = 'X'; break; }
			case 2: { sign = 'O'; break; }
			}
			printf("| %c ", sign);
		}
		printf("|\n");
		printf("\t-------------\n");
	}
}

int choose_sign() {
	char sign;
	while (1) {
		system("cls");
		printf("\tЧем будете играть? ");
		scanf_s(" %c", &sign);
		switch (sign) {
		case 'X': return 1;
		case 'O': return 2;
		case 'Х': return 1;
		case 'О': return 2;
		case 'х': return 1;
		case 'о': return 2;
		case 'x': return 1;
		case 'o': return 2;
		}
		printf("\nНекорректный ввод! Х или О");
		system("pause");
		system("cls");
	}
}

struct GAMEDATA start() {
	struct GAMEDATA result = { 1, 2 };
	int user_sign = choose_sign();
	result.user_sign = user_sign;
	if (user_sign == 1) result.comp_sign = 2;
	if (user_sign == 2) result.comp_sign = 1;
	return result;
}

int is_play_again() {
	int answer;
	while (1) {
		system("cls");
		printf("\n\tХотите сыграть снова? (1 - да, 0 - нет): ");
		scanf_s("%d", &answer);
		if (answer == 1) return 1;
		if (answer == 0) return 0;
	}
}