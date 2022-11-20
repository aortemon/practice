#include <Windows.h>

#include "Header.h"

GAME_DATA start_game(HANDLE hStdOut) {  // начало игры

	GAME_DATA data;

	data.user_sign = choose_sign_menu(hStdOut); // Выбор символа пользователя

	 // Установка символа компьютера
	if (data.user_sign == 1) data.comp_sign = 2;
	if (data.user_sign == 2) data.comp_sign = 1;

	data.board = init_board();  // Создание игрового поля

	return data;
}