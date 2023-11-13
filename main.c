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
		printf("Buffer overflow avoided");
		return 0;
	}

	numberInput = strtol(initialInput, &endptr, 10);
	if (*endptr == numberInput) {
		printf("No digits found or extra char after number");
		return 0;
	}
	if (*endptr != '\n') {
		printf("No digits found or extra char after number");
		return 0;
	}
	if (numberInput < INT_MIN) {
		printf("Number too low");
	}
	if (numberInput > INT_MAX) {
		printf("Number too high");
	}
	return (int)numberInput;
}

int clearInputBuffer() {
	while (getchar() != '\n');
	return 0;
}

int getUserPickedNumber() {
	char input[256];

	while (true) {
		int result = scanf("%d", &input);
		if (result == 1) {
			return input;
		} else {
			clearInputBuffer();
			printf("Please enter a valid number\n");
			printf("Your number: ");
		}
	}
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
