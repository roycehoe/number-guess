#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

enum errorCodes {
	NO_ERROR,
	BUFFER_OVERFLOW_ERROR,
	NO_DIGITS_FOUND_ERROR,
	NUMBER_TOO_LARGE_ERROR,
	NUMBER_TOO_SMALL_ERROR
}

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
		return BUFFER_OVERFLOW_ERROR;
	}

	numberInput = strtol(initialInput, &endptr, 10);
	if (*endptr == numberInput) {
		return NO_DIGITS_FOUND_ERROR;
	}
	if (*endptr != '\n') {
		return NO_DIGITS_FOUND_ERROR;
	}
	if (numberInput < INT_MIN) {
		return NUMBER_TOO_SMALL_ERROR
	}
	if (numberInput > INT_MAX) {
		return NUMBER_TOO_LARGE_ERROR
	}
	return (int)numberInput;
}

int main() {
	int numberInput = getNumberInput(128);
	return 0;
}



// int main() {
// 	srand(time(NULL));
// 	int userPickedNumber;
// 	int computerPickedNumber = (rand() % 10) + 1;
// 
// 	banner();
// 	instructions();
// 
// 	while (true) {
// 		userPickedNumber = getUserPickedNumber();
// 		if (userPickedNumber == computerPickedNumber) {
// 			printf("----YOU WON!----\n");
// 			return 0;
// 		}
// 		printf("Oops, that wasn't the number I was thinking of. Please try again\n");
// 		printf("Your number: ");
// 	}
// }
