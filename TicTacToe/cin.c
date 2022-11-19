#include "stdlib.h"
#include "stdio.h"

#include "Header.h"

int ask_user_sign() {
	char sign;
	while (1) {
		printf("\t����������, ��������, ��� ������ ������: (� ��� �)\n\t");
		scanf_s(" %c", &sign);
		if (sign == 'X') return 1;
		if (sign == 'O') return 2;
		printf("\n\t������������ ����! ���������� �����!\n");
		system("pause");
		system("cls");
	}
}

void get_user_move(int** board, int user_sign) {
	system("cls");
	print(board);
	int row, col;
	while (1) {
		printf("\t��� ���: ");
		scanf_s(" %d", &row);
		scanf_s(" %d", &col);
		row--; 
		col--;
		if (0 <= row && row <= 2 && 0 <= col && col <= 2) break;
		printf("\n\t������������ ���!");
		system("pause");
		system("cls");
	}
	struct COORD xy = { row, col };
	set(board, xy, user_sign);
}

/*
����� �������� ��� ������
����
������� ��� ���? ���� ��, �� �������, ����� ����������
�����
*/