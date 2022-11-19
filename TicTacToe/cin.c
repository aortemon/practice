#include "stdlib.h"
#include "stdio.h"

#include "Header.h"

int ask_user_sign() {
	char sign;
	while (1) {
		printf("\tПожалуйста, выберете, чем будете играть: (О или Х)\n\t");
		scanf_s(" %c", &sign);
		if (sign == 'X') return 1;
		if (sign == 'O') return 2;
		printf("\n\tНекорректный ввод! Попробуйте снова!\n");
		system("pause");
		system("cls");
	}
}

void get_user_move(int** board, int user_sign) {
	system("cls");
	print(board);
	int row, col;
	while (1) {
		printf("\tВаш ход: ");
		scanf_s(" %d", &row);
		scanf_s(" %d", &col);
		row--; 
		col--;
		if (0 <= row && row <= 2 && 0 <= col && col <= 2) break;
		printf("\n\tНекорректный ход!");
		system("pause");
		system("cls");
	}
	struct COORD xy = { row, col };
	set(board, xy, user_sign);
}

/*
Выбор крестика или нолика
Игра
Сыграем еще раз? Если да, то сначала, иначе продолжить
Конец
*/