#include "Header.h"

void selection_sort(struct FileData* files, int length) {
	struct FileData tmp;
	for (int i = 0; i < length - 1; i++) {
		int min_index = i;
		for (int j = i + 1; j < length; j++) if (files[j].size < files[min_index].size) min_index = j;
		if (min_index != i) swap(files, i, min_index);
	}
}

void selection(struct FileData* files, int length) { selection_sort(files, length); }