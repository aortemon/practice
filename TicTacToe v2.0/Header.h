#pragma once
#include <Windows.h>

// Числовые эквиваленты клавиш 
#define KEY_ENTER 13

#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80

// Обозначения в клетках поля:
// 0 - пусто
// 1 - крестик
// 2 - нолик

// Размер консоли в символах
#define CONSOLE_WIDTH 120
#define CONSOLE_HEIGHT 30

// Некоторые цвета
#define WHITE_GREEN 0x2F
#define GREEN_WHITE 0xF2
#define WHITE_RED 0x4F
#define RED_WHITE 0xF4
#define BLACK_WHITE 0xF0
#define BLUE_WHITE 0x72

// Данные игры
typedef struct {
	int user_sign;
	int comp_sign;
	int** board;
} GAME_DATA;

// Меню
GAME_DATA start_game(HANDLE hStdOut);
int choose_sign_menu(HANDLE hStdOut);
COORD choose_square(HANDLE hStdOut, int** board);
int play_again_menu(HANDLE hStdOut);

// Работа с полем 
int** init_board();
int is_free(int** board, COORD pos); 
void set(int** board, COORD pos, int sign);
void print(HANDLE hStdOut, int** board);
int is_end(int** board);
int is_win(int** board);

// Ход компьютера
void comp_move(HANDLE hStdOut, int** board, int comp_sign, int user_sign);

// Вывод сообщений в виде ASCII-Art
void title(HANDLE hStdOut);
void win_message(HANDLE hStdOut);
void failure_message(HANDLE hStdOut);
void draw_message(HANDLE hStdOut);
void bye_message(HANDLE hStdOut);