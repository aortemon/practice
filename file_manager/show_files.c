#define _CRT_SECURE_NO_WARNINGS
#define SORTINGS_NUM 6

#include <stdlib.h>  
#include <stdio.h>  
#include <Windows.h>
#include <io.h>  
#include <conio.h>
#include <time.h>  

#include "Header.h"

void swap(struct FileData* files, int i, int j) {
    struct FileData tmp;
    tmp = files[i];
    files[i] = files[j];
    files[j] = tmp;
}

struct FileData* get_files(char path[256], int* length) {
    wchar_t* w_Path = (wchar_t*)malloc(strlen(path) * sizeof(wchar_t));
    mbstowcs(w_Path, path, strlen(path) + 1);
    WIN32_FIND_DATA FindFileData;
    HANDLE hFind = FindFirstFile(w_Path, &FindFileData);

    struct FileData* files_list = (struct FileData*)malloc(*length * sizeof(struct FileData));

    if (hFind != INVALID_HANDLE_VALUE)
    {
        do if (FindFileData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY) {
                char* name = (char*)malloc(260 * sizeof(char));
                int size = (FindFileData.nFileSizeHigh * (MAXDWORD + 1)) + FindFileData.nFileSizeLow;
                wcstombs(name, FindFileData.cFileName, 260);
                files_list[*length - 1].name = name;
                files_list[*length - 1].size = size;
                (*length)++;
                files_list = (struct FileData*)realloc(files_list, *length * sizeof(struct FileData));
            }
        while (FindNextFile(hFind, &FindFileData));
        FindClose(hFind);
    }
    else printf("  Something went wrong...\n  ");
    (*length)--;
    return files_list;
}


void files_menu(char path[256], int mode) {
    char* sortings[SORTINGS_NUM] = { (char*)"Сортировка пузырьком", (char*)"Сортировка выбором", (char*)"Сортировка вставками", (char*)"Сортировка слиянием", (char*)"Сортировка Хоала", (char*)"Сортировка Шелла"};
    void (*sort_funcs[6]) (struct FileData*, int) = { bubble, selection, insertion, merge, hoara, shell };
    system("cls");
    printf("   Директория: %s\n", path);
    printf("   Метод: %s\n\n", sortings[mode - 1]);
    int length = 1;
    struct FileData* files_list = get_files(path, &length);
    sort_funcs[mode - 1](files_list, length);
    printf("  Название файла\t\tРазмер (байт)\n");
    printf("  ==============\t\t=============\n");
    for (int i = 0; i < length; i++) printf("  %.13s\t\t\t%d\n", files_list[i].name, files_list[i].size);
    printf("\n");
    system("pause");

}