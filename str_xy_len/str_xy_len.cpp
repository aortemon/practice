#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int count(char* string, char x, char y) {
	int length = strlen(string);
	int flag = 0; // 0 - didn't meet, 1 - already met
	int counter = -1;
	int max_counter = -1;
	char cur;
	for (int i = 0; i < length; i++) {
		cur = string[i];
		if (flag == 0 && (cur == x || cur == y)) {
			flag = 1;
			counter = 1;
		} else if (cur == x || cur == y) {
					if (max_counter < counter) { max_counter = counter; }
			} else if (cur == '0') { counter++; }
	}
	return max_counter;
}

int main() {
	char string1[] = "000XY00X000";
	printf("%d ", count(string1, 'X', 'Y'));
	char string2[] = "00X00Y00Y00Y";
	printf("%d", count(string2, 'X', 'Y'));

}