#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

char* input(int* length) {
	char* string = (char*)malloc(sizeof(char)), c;
	int len = *length;
	while ((c = getchar()) != '\n') { // вводим поток
		string[len - 1] = c;
		len++;
		string = (char*)realloc(string, len); //берем еще sizeof(char) памяти для следующего символа, сохраняем
	}
	string[len - 1] = '\0';
	*length = len;
	return string;
}

char* rewrite(char* string, int length, int pos) {
	for (int i = pos; i < length; i++) string[i] = string[i + 1];
	return length - 1;
}

int modify(char* string, int length) {
	int* nums = (int*)malloc(length * sizeof(int));
	int len = 0;

	for (int i = 0; i < length; i++) {
		if (string[i] == ' ' && (i + 1) % 2 == 0) {
			nums[len] = i;
			len++;
		}
	}
	
	for (int i = 0; i < len; i++) {
		length = rewrite(string, length, nums[i]);
		for (int j = i; j < len; j++) nums[j]--;
	}
	return length;
}

int main() {
	setlocale(LC_CTYPE, "RUS");
	int length = 1;
	char* string;
	printf("Введите строку: ");
	string = input(&length);
	length = modify(string, length);
	printf("\nРезультат: ");
	for (int i = 0; i < length; i++) printf("%c", string[i]);
	printf("\n\n%d", length);
}
// удалить из строки s все пробелы имеющие в исходной строке четные порядковые наомера