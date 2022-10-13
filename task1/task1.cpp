#include <stdlib.h>
#include <stdio.h>

int validate(int value) {
	switch (value) {
	case 15: {return 15; break; }
	case 16: {return 16; break; }
	case 17: {return 17; break; }
	case 18: {return 18; break; }
	default: return -1;
	}
}

int main() {
	int arr[] = { 11, 12, 13, 14, 0, 47, 15, 16, 17, 18, 19 };
	int temp;
	for (int i = 0; i < 11; i++) {
		temp = validate(arr[i]);
		if (temp != -1) printf(" %d\n", temp);
	}

	return 0;
}