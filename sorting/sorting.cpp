#include <iostream>
#include "sorting_h.h"

int main(int argc, char* argv[]) {
	int size;
	cout << "Enter the size of the array: ";
	cin >> size;
	int* a = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}

	cout << "\nResult: ";

	//InsertionSort(a, size);
	SelectionSort(a, size);
	//QuickSort(a, 0, size - 1);
	//BubbleSort(a, size);


	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	cout << "\n\n";
	free(a);
	system("pause");
	return 0;
}
