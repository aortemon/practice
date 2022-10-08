#include "Header.h"
#include <stdio.h>

int binary_search(int* values, int target, int length) {
	int start = 0, end = length - 1;
	int mid = (start + end) / 2;
	while (start < end && start != mid && end != mid) {
		//printf("\n%d %d %d", start, mid, end);
		if (values[mid] == target) return mid;
		else if (values[mid] > target) end = mid;
		else start = mid;
		mid = (start + end) / 2;
	}
	return -1;
}