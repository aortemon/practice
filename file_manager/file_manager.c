#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>  
#include <stdio.h>  
#include <Windows.h>
#include <io.h>  
#include <time.h>  

#include "Header.h"

#define MAIN_MENU_SIZE 3
#define SETTINGS_MENU_SIZE 3

int main() {
    HANDLE hStdOut = set_console();

    char* main[MAIN_MENU_SIZE] = { (char*)"Файловый менеджер", (char*)"Настройки", (char*)"Выход"};
    char* settings[SETTINGS_MENU_SIZE] = { (char*)"Изменить метод сортировки", (char*)"Задать директорию", (char*)"Назад"};

    int choose_pos = 0;
    int exit_flag = 0;
    int mode = 1;
    int exit_main_flag = 0;
    char path[256] = "c:\\users\\артем\\desktop\\practice\\file_manager\\*.c";


    while (!exit_flag) {
        submenu(hStdOut, main, MAIN_MENU_SIZE, &choose_pos);
        switch (choose_pos) {
            case 2: { exit_flag = 1; break;}
            case 0: { files_menu(path, mode); break; }
            case 1: { 
                exit_main_flag = 0;
                while (!exit_main_flag) {
                    submenu(hStdOut, settings, SETTINGS_MENU_SIZE, &choose_pos);
                    switch (choose_pos) {
                        case 2: {exit_main_flag = 1; break; }
                        case 0: { choose_sorting_method(hStdOut, &mode);  break; }
                        case 1: { set_path(path); printf(">>> %s", path); system("pause"); break; }
                    }
                }
            }
        }
    }
    system("cls");
}
