#include <stdlib.h>  
#include <stdio.h>  
#include <Windows.h>

#pragma once

struct FileData {
    char* name;
    int size;
};




HANDLE set_console();

void submenu(HANDLE hStdOut, char** menu_names, int menu_size, int* choose_pos);
void choose_menu(HANDLE hStdOut, char** menu_names, int menu_size, int* choose_pos);
void files_menu(char path[256]);

void choose_sorting_method(int* mode);
void set_path(char* path);
void swap(struct FileData* files, int i, int j);

void bubble(struct FileData* files, int length);
void selection(struct FileData* files, int length);
void insertion(struct FileData* files, int length);
void merge(struct FilesData* files, int length);
void hoara(struct FileData* files, int length);
void shell(struct FileData* files, int length);
