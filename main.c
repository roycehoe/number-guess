#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
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

int getNumberInput(int inputSize) {
	char initialInput[inputSize];
	long numberInput;
	char *endptr;

	if (fgets(initialInput, sizeof(initialInput), stdin) == NULL) {
		printf("Buffer overflow avoided\n");
		return 0;
	}

	numberInput = strtol(initialInput, &endptr, 10);

	if (*endptr != '\0' && *endptr != '\n') {
		printf("No digits found or extra char after number\n");
		return 0;
	}
	if (numberInput < INT_MIN) {
		printf("Number too low\n");
		return 0;
	}
	if (numberInput > INT_MAX) {
		printf("Number too high\n");
		return 0;
	}
	if (numberInput == 0) {
		printf("0 is an invalid number!\n");
		return 0;
	}
	return (int)numberInput;
}

void clearBuffer() {
	while (getchar() != '\n');
}

int main() {
	srand(time(NULL));
	int userPickedNumber;
	int computerPickedNumber = (rand() % 10) + 1;

	banner();
	instructions();

	while (true) {
		userPickedNumber = getNumberInput(128);
		if (userPickedNumber == 0) {
			printf("Please press enter to continue\n");
			clearBuffer();
			printf("Your number: ");
			continue;
		}
		if (userPickedNumber != computerPickedNumber) {
			printf("Oops, that wasn't the number I was thinking of. Please try again\n");
			printf("Your number: ");
			continue;
		}
		printf("----YOU WON!----\n");
		return 0;
	}
}
