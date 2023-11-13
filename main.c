#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int banner() {
	printf("------------------------\n");
	printf("------------------------\n");
	printf("----GUESS THE NUMBER----\n");
	printf("------------------------\n");
	printf("------------------------\n");
	return 0;
}

int instructions() {
	printf("Pick a number between 1 and 10. Your objective is to guess the number I am thinking of!\n");
	printf("Your number: ");
	return 0;
}

int clearInputBuffer() {
	while (getchar() != '\n');
	return 0;
}

int getUserPickedNumber() {
	int userPickedNumber;

	while (true) {
		int result = scanf("%d", &userPickedNumber);
		if (result == 1) {
			return userPickedNumber;
		} else {
			clearInputBuffer();
			printf("Please enter a valid number\n");
			printf("Your number: ");
		}
	}
}



int main() {
	srand(time(NULL));
	int userPickedNumber;
	int computerPickedNumber = (rand() % 10) + 1;

	banner();
	instructions();

	while (true) {
		userPickedNumber = getUserPickedNumber();
		if (userPickedNumber == computerPickedNumber) {
			printf("----YOU WON!----\n");
			return 0;
		}
		printf("Oops, that wasn't the number I was thinking of. Please try again\n");
		printf("Your number: ");
	}
}
