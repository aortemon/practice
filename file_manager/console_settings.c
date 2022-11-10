#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <locale.h>

#include "Header.h"


HANDLE set_console() {

	setlocale(LC_CTYPE, "rus");

	system("title Application");

	// ������������� �������������� � �������� �������
	SetConsoleCP(1251);         // ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);   // ��������� ������� �������� win-cp 1251 � ����� ������

	// �������� ���������� ���� ��� �������� � �������
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// ���������� ������ ������� � ������� (� ����� ���� ������ ������)
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);

	// ����� ����� ��� �� ���� �������
	SetConsoleTextAttribute(hStdOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	// ������� �����, ����� ��������� ����� �����������
	system("cls");
	return hStdOut;
}