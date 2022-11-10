#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <locale.h>

#include "Header.h"


HANDLE set_console() {

	setlocale(LC_CTYPE, "rus");

	system("title Application");

	// устанавливаем взаимодействие с русскими буквами
	SetConsoleCP(1251);         // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);   // установка кодовой страницы win-cp 1251 в поток вывода

	// получаем дескриптор окна для обращени¤ к консоли
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// отключение мигани¤ курсора в консоли (в нашем меню курсор лишний)
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);

	// задаЄм серый фон дл¤ окна консоли
	SetConsoleTextAttribute(hStdOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	// очищаем экран, чтобы настройка цвета применилась
	system("cls");
	return hStdOut;
}