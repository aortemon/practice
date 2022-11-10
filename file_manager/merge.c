#include <stdlib.h>
#include <stdio.h>

#include "Header.h"

void merge_sorting(struct FileData* files, struct FileData* buffer, int start, int end) {
	if (start == end) return;
	int midpoint = (start + end) / 2;

	merge_sorting(files, buffer, start, midpoint);
	merge_sorting(files, buffer, midpoint + 1, end);
	int left_index = start;
	int right_index = midpoint + 1;
	int buffer_index = left_index;
	while (left_index <= midpoint && right_index <= end) {
		if (files[left_index].size <= files[right_index].size) {
			buffer[buffer_index] = files[left_index];
			left_index++;
		}
		else {
			buffer[buffer_index] = files[right_index];
			right_index++;
		}
		buffer_index++;
	}
	for (int i = left_index; i <= midpoint; i++) {
		buffer[buffer_index] = files[i];
		buffer_index++;
	}
	for (int i = right_index; i <= end; i++) {
		buffer[buffer_index] = files[i];
		buffer_index++;
	}
	for (int i = start; i <= end; i++) files[i] = buffer[i];
}

void merge(struct FileData* files, int length) {
	struct FileData* buffer = (struct FileData*)malloc(length * sizeof(struct FileData));
	merge_sorting(files, buffer, 0, length - 1);
}
