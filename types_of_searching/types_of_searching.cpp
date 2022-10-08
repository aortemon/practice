#include <stdlib.h>
#include <stdio.h>
#include "Header.h"

int main() {
	int values[15] = { 9, 1, 4, 6, 2, 8, 7, 3, 5, 15, 13, 11, 14, 12, 10 };
	int bin_values[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	int target = 16, length = sizeof(values)/sizeof(values[0]);
	printf("Looking for 13 in array {9, 1, 4, 6, 2, 8, 7, 3, 5, 15, 13, 11, 14, 12, 10}. It's 10th in it.\n");

	printf("Linear Search Algorithm: %d", linear_search(values, target, length));

	printf("\n\nAccording to requirements put forward by the Binary Search Algorithm, we'll use sorted array for its work.");
	printf("Binary Search Algorithm: %d", binary_search(values, target, length));
}