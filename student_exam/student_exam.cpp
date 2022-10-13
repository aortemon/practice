#include <stdlib.h>
#include <stdio.h>

int average(int* arr, int count) {
	int sum = 0;
	for (int i = 0; i < count; i++) sum += arr[i];
	return sum / count;
}

void func(int* p, int count) {
	int level = average(p, count);
	switch (level) {
	case 5: {printf("\nOtlichnik"); }
	case 4: {printf("\nKhoroshist"); }
	case 3: {printf("\nTroechnik"); }
	case 2: {printf("\nDvoechnik"); }
	default: { printf("An error occured");
	}

	}
}


int main() {
	
	const int count = 3;
	int levels[count] = { 2, 3, 4 };

	func(levels, 3);

	system("pause");
	return 1;
}