#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

#include "Header.h"

void draw(HANDLE hStdOut, char* str, int choose_pos) { // Отрисовка

	title(hStdOut);  // Заголовок

	COORD cursorPos;
	cursorPos.X = (CONSOLE_WIDTH - strlen(str)) / 2;
	cursorPos.Y = CONSOLE_HEIGHT / 2 - 2;

	SetConsoleCursorPosition(hStdOut, cursorPos); // Положение текста
	SetConsoleTextAttribute(hStdOut, BLACK_WHITE); // фон - белый, текст - черный

	printf("%s", str); // Вывод предложения

	 // Задаем цвета элементам
	int x_color = BLACK_WHITE, o_color = BLACK_WHITE;
	switch (choose_pos) {
	case 1: { x_color = WHITE_GREEN; break; }
	case 2: { o_color = WHITE_GREEN; break; }
	}

	// Отрисовка
	cursorPos.Y += 3;
	cursorPos.X = CONSOLE_WIDTH / 3 - 3;
	SetConsoleCursorPosition(hStdOut, cursorPos);
	SetConsoleTextAttribute(hStdOut, x_color);
	printf(" == X == ");

	cursorPos.X = CONSOLE_WIDTH / 3 * 2 - 3;
	SetConsoleCursorPosition(hStdOut, cursorPos);
	SetConsoleTextAttribute(hStdOut, o_color);
	printf(" == O == ");

	SetConsoleTextAttribute(hStdOut, BLACK_WHITE);
}

int choose_sign_menu(HANDLE hStdOut) { // Меню выбора знака

	int choose_pos = 1;
	int iKey = 0;

	while (iKey != KEY_ENTER) { // Пока не нажат Enter

		system("cls");
		draw(hStdOut, (char*)"Please, choose your sign:", choose_pos); // Отрисовка меню

		 // Обработка нажатия клавиш
		iKey = _getch();
		if (iKey == KEY_ARROW_RIGHT) choose_pos++;
		if (iKey == KEY_ARROW_LEFT) choose_pos--;
		if (choose_pos < 1) choose_pos = 2;
		if (choose_pos > 2) choose_pos = 1;
	}

	return choose_pos;
}