#include "Header.h"

int binary(int* values, int target, int length) {
	int start = 0, end = length - 1;
	int mid;
	while (true) {
		mid = (start + end) / 2;
		if (values[mid] == target) return mid;
		else if (values[mid] > target) end = mid - 1;
		else start = mid + 1;
	}
	return -1;
}