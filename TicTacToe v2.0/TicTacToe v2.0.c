#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "Header.h"

int main() {

	// Получаем дескриптор потока вывода
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); 

	// Устанавливаем белый фон, черный текст
	SetConsoleTextAttribute(hStdOut, BLACK_WHITE); //0x{BG}{FG}

	// Отключаем моргание курсора
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);

	system("cls");


	GAME_DATA data = start_game(hStdOut); // переменная-структура доя хранения данных текущей игры

	// Бесконечный цикл
	while (1) {
		// Ход игры, если пользователь играет крестиками
		if (data.user_sign == 1) {
			while (is_end(data.board) == 0) {
				print(hStdOut, data.board); // Вывод поля
				while (1) {
					COORD pos = choose_square(hStdOut, data.board); // Выбор пользователем хода
					if (is_free(data.board, pos)) {
						set(data.board, pos, data.user_sign);// Ход, если он возможен
						break;
					}
				}
				if (is_end(data.board) != 0) break; // Проверка на конец игры
				comp_move(hStdOut, data.board, data.comp_sign, data.user_sign);  // Ход компьютера
			}
		}
		else { // Ход игры, если пользователь играет ноликами
			while (is_end(data.board) == 0) {
				print(hStdOut, data.board);  // Вывод поля
				comp_move(hStdOut, data.board, data.comp_sign, data.user_sign); // Ход компьютера
				if (is_end(data.board) != 0) break; // Проверка на конец игры
				while (1) {
					COORD pos = choose_square(hStdOut, data.board); // Выбор пользователем хода
					if (is_free(data.board, pos)) {
						set(data.board, pos, data.user_sign);// Ход, если он возможен
						break;
					}
				}
			}
		}
		int end_type = is_end(data.board); // Выбор конца
		if (end_type == data.user_sign) { // Если победа
			win_message(hStdOut);
		}
		else if (end_type == data.comp_sign) { // Если проигрыш
			failure_message(hStdOut);
		}
		else {
			draw_message(hStdOut); // Если ничья
		}
		printf("\n\n\n\t\t\t\t\t");
		system("pause");
		
		int is_play_again = play_again_menu(hStdOut);  // Предложение сыграть снова
		if (is_play_again == 1) { // Если играем снова, реинициализация данных игры
			system("cls");
			data = start_game(hStdOut);
		}
		else break;  // Если нет, выйти из цикла игры
	}

	bye_message(hStdOut);  // Прощание
	printf("\n\n\n\t\t\t\t\t");
	system("pause");
}