#include <stdlib.h>
#include <stdio.h>

#include "Header.h"



void hoara_sorting(struct FileData* files, int start, int end)
{
    int i = start, j = end;
    double tmp, x = files[(start + end) / 2].size;
    do {
        while (files[i].size < x) i++;
        while (files[j].size > x) j--;
        if (i <= j) {
            if (i < j) {
                swap(files, i, j);
            }
            i++;
            j--;
        }
    } while (i <= j);
    if (i < end)
        hoara_sorting(files, i, end);
    if (start < j)
        hoara_sorting(files, start, j);
}


void hoara(struct FileData* nums, int length) { hoara_sorting(nums, 0, length - 1); }