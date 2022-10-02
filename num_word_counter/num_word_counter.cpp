#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char* str = NULL, c; // определяю указатель на начало массиваЮ, где в будущем будет храниться введенный поток символов
	int len = 1; // переменная для сохранения длины введенной последовательности
	str = (char*)malloc(sizeof(char)); // резервируем место в памяти для одного символа, в последсвтии будем расширять
	printf("Please, input the string: \n");
	while ((c = getchar()) != '\n') { // вводим поток
		str[len - 1] = c;
		len++;
		str = (char*)realloc(str, len); //берем еще sizeof(char) памяти для следующего символа, сохраняем
	}
	str[len - 1] = '\0'; // формальные издержки

	int words = 0, nums = 0;
	char temp, prev;
	temp = 'a';

	for (int i = 0; i < len; i++) { //непосредственно считаем кол-ва слов и чисел
		prev = temp;
		temp = str[i];
		if (isalpha(prev) && (isspace(temp) || ispunct(temp))) { words++; }
		if (isdigit(prev) && (isspace(temp) || ispunct(temp))) { nums++; }
	}
	printf("\n\nI've counted %d words and %d nums in the your string.\n\n\n\n", words, nums);
	return 1;
}