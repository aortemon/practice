#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "Header.h"

#define KEY_EXIT 27
#define KEY_ENTER 13
#define ARROW_KEY 224
#define KEY_SPACE 0
#define KEY_BACKSPACE 8

#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80


void submenu(HANDLE hStdOut, char** menu_names, int menu_size, int* choose_pos) {
    system("cls");
    // ���������� ����������
    int iKey; // ���������� ��� �������� ������� �������
    COORD cursorPos; // ���������� ���������� �������, ����� ������ ��������� �����
    // ������������� (���������� ����������) ����������
    *choose_pos = 0;
    /* 1. ����� ���� � ������������� */
    // ����� ������� � ��������� ���������
    system("cls");
    iKey = 67;
    cursorPos.X = 0;
    cursorPos.Y = 0;
    SetConsoleCursorPosition(hStdOut, cursorPos);
    // �������� ������� ������
    while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
        system("cls");
        switch (iKey) {
        case KEY_ARROW_UP:
            (*choose_pos)--;
            break;
        case KEY_ARROW_DOWN:
            (*choose_pos)++;
            break;
        }
        // ������������ �������������� ����
        if (*choose_pos < 0) { *choose_pos = menu_size - 1; }
        if (*choose_pos > menu_size - 1) { *choose_pos = 0; }
        for (int i = 0; i < menu_size; i++) {
            cursorPos.X = 3; //(COORD) { 3, i };
            cursorPos.Y = i;
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf("%s \n", menu_names[i]);
        }
        // ����������� ��������� �������
        cursorPos.X = 0;// = (COORD){ 0, *choose_pos };
        cursorPos.Y = *choose_pos;
        SetConsoleCursorPosition(hStdOut, cursorPos);
        printf("<<");
        cursorPos.X = strlen(menu_names[*choose_pos]) + 3 + 1; // *choose_pos
        cursorPos.Y = *choose_pos;
        SetConsoleCursorPosition(hStdOut, cursorPos);
        printf(">>");
        // �������� ������ ������� �������
        iKey = _getch();
    };
}

void choose_menu(HANDLE hStdOut, char** menu_names, int menu_size, int* choose_pos) {
    // ���������� ����������
    int iKey; // ���������� ��� �������� ������� �������
    COORD cursorPos; // ���������� ���������� �������, ����� ������ ��������� �����
    // ������������� (���������� ����������) ����������
    *choose_pos = 0;
    /* 1. ����� ���� � ������������� */
    // ����� ������� � ��������� ���������
    system("cls");
    iKey = 67;
    cursorPos.X = 0;
    cursorPos.Y = 0;
    *choose_pos = 1;
    SetConsoleCursorPosition(hStdOut, cursorPos);
    // �������� ������� ������
    while (iKey != KEY_EXIT && iKey != KEY_ENTER) {
        system("cls");
        switch (iKey) {
        case KEY_ARROW_UP:
            (*choose_pos)--;
            break;
        case KEY_ARROW_DOWN:
            (*choose_pos)++;
            break;
        }
        // ������������ �������������� ����
        if (*choose_pos < 1) { *choose_pos = menu_size - 1; }
        if (*choose_pos >= menu_size) { *choose_pos = 1; }
        for (int i = 0; i < menu_size; i++) {
            cursorPos.X = 3; //(COORD) { 3, i };
            cursorPos.Y = i;
            SetConsoleCursorPosition(hStdOut, cursorPos);
            printf("%s \n", menu_names[i]);
        }
        // ����������� ��������� �������
        cursorPos.X = 0;// = (COORD){ 0, *choose_pos };
        cursorPos.Y = *choose_pos;
        SetConsoleCursorPosition(hStdOut, cursorPos);
        printf("<<");
        cursorPos.X = strlen(menu_names[*choose_pos]) + 3 + 1; // *choose_pos
        cursorPos.Y = *choose_pos;
        SetConsoleCursorPosition(hStdOut, cursorPos);
        printf(">>");
        // �������� ������ ������� �������
        iKey = _getch();
    };
}

