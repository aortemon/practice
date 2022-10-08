#include "Header.h"

int barier_search(int* values, int target, int length) {
	int temp = values[length - 1];
	values[length - 1] = target;
	int i = 0;
	for (i; values[i] != target; i++) {}
	values[length - 1] = temp;
	return i < length - 1 || values[length - 1] == target ? i : -1;
}