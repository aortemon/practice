#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <io.h>
#include <locale.h>

#include "Header.h"

#define SORTINGS_NUM 8

void add_path_suffix(char path[256]) {
	int length = strlen(path);
	char suffix[3] = "*.*";
	for (int i = 0; i < 3; i++) path[length + i] = suffix[i];
}

int is_path_correct(char path[256]) {
	struct _finddata_t c_file;
	intptr_t hFile;
	add_path_suffix(path);
	if ((hFile = _findfirst(path, &c_file)) == -1L) return 0;
	else return 1;
}


void choose_sorting_method(HANDLE hStdOut, int* mode) {
	int temp = *mode;
	char* sortings[SORTINGS_NUM] = { (char*)"  === Выберите метод сортировки: === ", (char*)"Сортировка пузырьком", (char*)"Сортировка выбором", (char*)"Сортировка вставками", (char*)"Сортировка слиянием", (char*)"Сортировка Хоала", (char*)"Сортировка Шелла", (char*)"Назад"};
	choose_menu(hStdOut, sortings, SORTINGS_NUM, mode);
	if (*mode == 7) *mode = temp;
}

void set_path(char path[256]) {
	system("cls");
	printf("  === Изменить директорию: ===\n");
	int exit_flag = 0;
	int length = 1;
	while (!exit_flag) {
		printf("  Введите путь: ");
		gets(path);
		if (is_path_correct(path)) exit_flag = 1;
		else printf("\n  Введеный путь некорректен! Каталог не существует, либо пуст!  \n");
	}
	printf("  Новый путь успешно сохранен!\n");
	system("pause");
}

