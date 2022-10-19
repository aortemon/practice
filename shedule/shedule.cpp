#include <stdio.h>


int main() {
	for (int i = 1; i <= 5; i++) {
		for (int j = 0; j <= i; j++) {
			printf("i - j = %d\ti xor j = %d\n", i - j, i ^ j);
		} 
		printf("\n");
	}
	return 0;
}