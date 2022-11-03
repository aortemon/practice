#include <stdlib.h>
#include <stdio.h>

#define LENGTH 10

int barier_search(int* arr, int num) {
	int temp, i;
	temp = arr[LENGTH - 1];
	arr[LENGTH - 1] = num;
	for (i = 0; num != arr[i]; i++) {};
	arr[LENGTH - 1] = temp;
	return (i != (LENGTH - 1) || temp == num) ? i : -1;
}

int main() {
	int arr[LENGTH] = { 9, 4, 5, 0, 1, 8, 2, 7, 3, 6 }; // Массив, в котором ищем
	int num = 1; // Число, которое ищем
	printf("{"); for (int i = 0; i < LENGTH; i++) printf(" %d ", arr[i]) ; printf("}\n");
	printf("Result of searching for %d in array: %d", num, barier_search(arr, num));
}