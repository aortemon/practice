#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


// разбить строку на слова
// найти слово
// \/ перевернуть строку

void reverse(char* string) { for (int i = 0; i < strlen(string); i++) printf("%c", string[strlen(string) - i - 1]); }

void split(char* string) { 
	char prev = 'a', cur = 'a';
	int counter = 0;
	for (int i = 0; i < strlen(string); i++) {
		prev = cur; cur = string[i];
		if (isalpha(prev) && isspace(cur)) counter ++;
	}
	if (isalpha(cur)) counter++;
	printf("\n%d\n", counter);
}

void find(char* string, char* arg) {
	for (int i = 0; i < strlen(string); i++) {
		if (arg[0] == string[i]) {
			int flag = 1;
			int res = i;
			for (int j = 0; j < strlen(arg); j++) if (string[i + j] != arg[j]) flag = 0;
			printf("%d", res);
		}
	}
}

int main() {
	char string[] = "hello world";
	void (*msg)(char*);
	void (*msg_find)(char*, char*);
	msg = reverse;
	msg(string);
	msg = split;
	msg(string);
	msg_find = find;
	char arg[] = "world";
	msg_find(string, arg);
	return 0;
}