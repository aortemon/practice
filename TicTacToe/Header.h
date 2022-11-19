#pragma once

#define SIZE 3


struct COORD {
	int x;
	int y;
};

struct GAMEDATA {
	int user_sign;
	int comp_sign;
};


int print(int** board);
int** board_init();
void intro();
int ask_user_sign();
void get_user_move(int** board, int user_sign);
int is_win(int** board);
struct COORD find_win_step(int** board, int sign);
void set(int** board, struct COORD xy, int sign);
void comp_move(int** board, int comp_sign, int user_sign);
void set(int** board, struct COORD xy, int sign);
struct GAMEDATA start();
int is_play_again();
int is_draw(int** board);
int is_end(int** board);