#include <stdlib.h>
#include <stdio.h>

#define SIZE 5

int* create_array(int length) {
	int* arr = (int*)malloc(length * sizeof(int));
	printf("Input: \n");
	for (int i = 0; i < length; i++) {
		printf("a[%d] = ", i);
		scanf_s("%d", &arr[i]);
	}
	return arr;
}


int main() {
	/*
	int* arr = create_array(SIZE);
	printf("\n\nOutput: \n");
	for (int i = 0; i < SIZE; i++) printf(">>> %d\n", arr[i]);
	free(arr);*/
	/*
	unsigned int x = 234567891;             // 0000 1101    1111 1011    0011 1000    1101 0011
	printf("%d\n", x);
	unsigned int y = x << 8;                // 1111 1011    0011 1000    1101 0011    0000 0000 
	printf("%d\n", y);
	unsigned int z = y >> 24;               // 0000 0000    0000 0000    0000 0000    1111 1011
	printf("%d\n", z);*/

	unsigned int x = 3012569;               // 0000 0000    0010 1101    1111 0111    1101 1001
	printf("\n%d", x);
	unsigned int y = x << 16;               // 1111 0111    1101 1001    0000 0000    0000 0000
	printf("\n%d", y);
	unsigned int z = y >> 24;               // 0000 0000    0000 0000    0000 0000    1111 0111
	printf("\n%d", z);

	

}