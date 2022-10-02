#include <stdio.h>
#include <stdlib.h>

int mode1(int mode) {
	int num = rand() % 1000 + 1;
	int bool_temp = 0;
	int tries = 1;
	int temp = -1;
	bool is_end = false;
	printf("I've made a number from 1 to 1000. You have to guess it!\n");
	while (not is_end) {
		printf("Guess the number: ");
		scanf_s("%d", &temp);
		if (num == temp) {
			printf("\nYou're right) You've done it in %d attempts!\nDo you want to play again? (1 - replay, 0 - exit)\n", tries);
			is_end = true;
			scanf_s("%d", &bool_temp);
			if (bool_temp == 1) {
				num = rand() % 1000 + 1;
				bool_temp = 0;
				tries = 0;
				temp = -1;
				is_end = false;
				printf("\n\n\nI've made a number from 1 to 1000. You have to guess it!\n");
			}
			else if (bool_temp == 0) { is_end = true; }
		}
		else if (temp < num) { printf("It's less than the guessed num, try again!\n"); }
		else if (temp > num) { printf("It's more than the guessed num, try again!\n"); }
		tries++;
	}
	system("cls");
	return 1;
}

int mode2(int mode) {
	int start = 1, end = 1001, current, tries = 1;
	char temp = 'a';
	printf("You should make the number from 1 to 1000. Please, tell me if my number less or more than needed");
	while (temp != '=') {
		current = (start + end) / 2;
		printf("\nI think it's %d\n", current);
		scanf_s(" %c", &temp);
		if (temp == '>') { end = current; }
		else if (temp == '<') { start = current; }
		else if (temp == '=') {
			printf("I've done it in %i attempts! Do you want to play again? (1 - replay, 0 - exit)\n", tries);
			int ans = 0;
			scanf_s("%d", &ans);
			if (ans == 1) {
				temp = 'a';
				start = 1;
				end = 1001;
				current = (start + end) / 2;
				tries = 1;
			}
			if (ans == 0) { temp = '='; }
		}
		else { printf("Something went wrong... I think your answer isn't correct, input it again..\n"); }
		if (temp == '=' || temp == '>' || temp == '<') { tries++; }
	}
	system("cls");
	return 1;

}

int main() {
	int mode = 0;
	while (mode != -1) {
		printf("Let's play \"Guess the number\"! There's two modes of the game:\n1) You guess the number\n2) I guess the number\n3) Quit the game\n\nWhich one do you prefer?\n");
		scanf_s("%d", &mode);
		printf("\n\n\n");
		if (mode == 1) { mode1(mode); }
		else if (mode == 2) { mode2(mode); }
		else if (mode == 3) { return 1; }
	}
}