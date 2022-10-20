#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

int find_nearest(int* arr, int num, int length) {
	int min_dif = abs(num - arr[0]), res = arr[0]; 
	for (int i = 0; i < length; i++) {
		if (abs(arr[i] - num) < min_dif) {
			res = arr[i];
			min_dif = abs(arr[i] - num);
		}
	}
	return res; 
}

int main() {
	setlocale(LC_CTYPE, "ru");
	int arr[] = { 10, 1, 15, 3, 55, 16, 50, 49 };
	int num = 70;
	printf("Ближайшее значение: %d", find_nearest(arr, num, sizeof(arr) / sizeof(arr[0])));

}