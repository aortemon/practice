#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>

#include "Header.h"


void title(HANDLE hStdOut) {  // Заголовок игры 
	COORD cursor_pos;
	char* strs[6];
	strs[0] = (char*)"  ___________.__     ___________           ___________";
	strs[1] = (char*)"  \\__    ___/|__| ___\\__    ___/____    ___\\__    ___/___   ____";
	strs[2] = (char*)"    |    |   |  |/ ___\\|    |  \\__  \\ _/ ___\\|    | /  _ \\_/ __ \\";
	strs[3] = (char*)"    |    |   |  \\  \\___|    |   / __ \\\\  \\___|    |(  <_> )  ___/";
	strs[4] = (char*)"    |____|   |__|\\___  >____|  (____  /\\___  >____| \\____/ \\___  >";
	strs[5] = (char*)"                     \\/             \\/     \\/                  \\/";

	cursor_pos.Y = -1;
	cursor_pos.X = (CONSOLE_WIDTH - strlen(strs[2])) / 2;
	for (int i = 0; i < 6; i++) {
		cursor_pos.Y++;
		SetConsoleCursorPosition(hStdOut, cursor_pos);
		printf(strs[i]);
	}
}


void win_message(HANDLE hStdOut) { // Победа
	system("cls");
	title(hStdOut);
	char* strs[6];
	strs[0] = "__          __  _____   _   _";
	strs[1] = "\\ \\        / / |_   _| | \\ | |";
	strs[2] = " \\ \\  /\\  / /    | |   |  \\| |";
	strs[3] = "  \\ \\/  \\/ /     | |   | . ` |";
	strs[4] = "   \\  /\\  /     _| |_  | |\\  |";
	strs[5] = "    \\/  \\/     |_____| |_| \\_|";
	COORD pos;
	pos.X = (CONSOLE_WIDTH - strlen(strs[2])) / 2;
	pos.Y = CONSOLE_HEIGHT / 2 - 3;
	for (int i = 0; i < 6; i++) {
		pos.Y++;
		SetConsoleCursorPosition(hStdOut, pos);
		printf("%s", strs[i]);
	}
}

 void failure_message(HANDLE hStdOut) { // Поражение
	 system("cls");
	 title(hStdOut);
	 char* strs[6];
	 strs[0] = " ______              _____   _        _    _   _____    ______ ";
	 strs[1] = "|  ____|     /\\     |_   _| | |      | |  | | |  __ \\  |  ____|";
	 strs[2] = "| |__       /  \\      | |   | |      | |  | | | |__) | | |__   ";
	 strs[3] = "|  __|     / /\\ \\     | |   | |      | |  | | |  _  /  |  __|";
	 strs[4] = "| |       / ____ \\   _| |_  | |____  | |__| | | | \\ \\  | |____ ";
	 strs[5] = "|_|      /_/    \\_\\ |_____| |______|  \\____/  |_|  \\_\\ |______|";
	 COORD pos;
	 pos.X = (CONSOLE_WIDTH - strlen(strs[2])) / 2;
	 pos.Y = CONSOLE_HEIGHT / 2 - 3;
	 for (int i = 0; i < 6; i++) {
		 pos.Y++;
		 SetConsoleCursorPosition(hStdOut, pos);
		 printf("%s", strs[i]);
	 }
}


 void draw_message(HANDLE hStdOut) { // Ничья
	 system("cls");
	 title(hStdOut);
	 char* strs[6];
	 strs[0] = " _____    _____              __          __";
	 strs[1] = "|  __ \\  |  __ \\      /\\     \\ \\        / /";
	 strs[2] = "| |  | | | |__) |    /  \\     \\ \\  /\\  / /";
	 strs[3] = "| |  | | |  _  /    / /\\ \\     \\ \\/  \\/ /";
	 strs[4] = "| |__| | | | \\ \\   / ____ \\     \\  /\\  /  ";
	 strs[5] = "|_____/  |_|  \\_\\ /_/    \\_\\     \\/  \\/  ";
	 COORD pos;
	 pos.X = (CONSOLE_WIDTH - strlen(strs[2])) / 2;
	 pos.Y = CONSOLE_HEIGHT / 2 - 3;
	 for (int i = 0; i < 6; i++) {
		 pos.Y++;
		 SetConsoleCursorPosition(hStdOut, pos);
		 printf("%s", strs[i]);
	 }
 }

 void bye_message(hStdOut) { // Прощание
	 title(hStdOut);
	 system("cls");
	 char* strs[8];
	 strs[0] = " ____                            _";
	 strs[1] = "|  _ \\                          | |";
	 strs[2] = "| |_) |  _   _    ___   ______  | |__    _   _    ___";
	 strs[3] = "|  _ <  | | | |  / _ \\ |______| | '_ \\  | | | |  / _ \\";
	 strs[4] = "| |_) | | |_| | |  __/          | |_) | | |_| | |  __/";
	 strs[5] = "|____/   \\__, |  \\___|          |_.__/   \\__, |  \\___|";
	 strs[6] = "          __/ |                           __/ |";
	 strs[7] = "         |___/                           |___/";
	 COORD pos;
	 pos.X = (CONSOLE_WIDTH - strlen(strs[2])) / 2;
	 pos.Y = CONSOLE_HEIGHT / 2 - 6;
	 for (int i = 0; i < 8; i++) {
		 pos.Y++;
		 SetConsoleCursorPosition(hStdOut, pos);
		 printf("%s", strs[i]);
	 }


 }