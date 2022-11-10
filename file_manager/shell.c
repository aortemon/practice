#include <stdlib.h>  
#include <stdio.h>   

#include "Header.h"

void shell_sort(struct FileData* files, int length) {
    for (int s = length / 2; s > 0; s /= 2) {
        for (int i = s; i < length; ++i) {
            for (int j = i - s; j >= 0 && files[j].size > files[j + s].size; j -= s) {
                swap(files, j, j + s);
            }
        }
    }
}

void shell(struct FileData* files, int length) { shell_sort(files, length); }