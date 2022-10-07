#include <stdlib.h>
#include <stdio.h>

int factorial(int n) {
	return n > 1 ? n * factorial(n - 1) : 1;
}

int fibonacci(int n) {
	return n == 0 ? 0 : n == 1 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
	for (int i = 1; i <= 10; i++) {
		printf("%d! = %d\n", i, factorial(i));
	}
	printf("\n\n");
	for (int i = 0; i <= 10; i++) {
		printf("Fibonacci(%d) = %d\n", i, fibonacci(i));
	}
}
