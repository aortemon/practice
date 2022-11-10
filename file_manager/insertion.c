#include <stdlib.h>
#include <stdio.h>

#include "Header.h"


void insertion_sort(struct FileData* files, int length) {
	struct FileData tmp;
	int index;
	for (int i = 1; i < length; i++) {
		tmp = files[i];
		index = i - 1;
		while (index >= 0 && files[index].size > tmp.size) {
			swap(files, index + 1, index);
			index--;
		}
		files[index + 1] = tmp;
	}
}

void insertion(struct FileData* files, int length) { insertion_sort(files, length); }