#include <stdlib.h>
#include <stdio.h>

#include "Header.h"


void bubble_sort(struct FileData* files, int length) {
	for (int i = 0; i < length - 1; i++) {
		int stop_flag = 0;
		for (int j = 0; j < length - i - 1; j++) {
			if (files[j].size > files[j + 1].size) {
				swap(files, j, j + 1);
				stop_flag = 1;
			}
				
		}
		if (!stop_flag) break;
	}
}

void bubble(struct FileData* files, int length) { bubble_sort(files, length); }