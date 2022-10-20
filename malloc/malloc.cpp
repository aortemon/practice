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
	int* arr = create_array(SIZE);
	printf("\n\nOutput: \n");
	for (int i = 0; i < SIZE; i++) printf(">>> %d\n", arr[i]);
	free(arr);


	/*unsigned int x = 234567891;
	printf("%d\n", x);
	unsigned int y = x << 8;
	printf("%d\n", y);
	unsigned int z = y >> 24;
	printf("%d\n", z);*/
}