#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <string.h>

const int PLAYER_NAME_MAX_CHAR = 128;
const int DEFAULT_CREDITS = 1000;

enum guessResult {
	TOO_HIGH,
	TOO_LOW,
	EQUAL
};

struct Player {
	char name[128];
	int credits;
};


struct Player initPlayer(char *name) {
	struct Player player;

    strncpy(player.name, name, 128 - 1);
    player.name[128 - 1] = '\0';
	player.credits = DEFAULT_CREDITS;
	return player;
}

int main() {
	char name[128];
	struct Player player 

	fgets(name, 128, stdin);
	name[strcspn(name, "\n")] = '\0';
	player = initPlayer(name);

	printf("%s", player.name);
	printf("%d", player.credits);
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

int getGuessResult(int userPickedNumber, int computerPickedNumber) {
	enum guessResult result;
	if (userPickedNumber > computerPickedNumber) {
		return TOO_HIGH;
	}
	if (userPickedNumber < computerPickedNumber) {
		return TOO_LOW;
	}
	return EQUAL;
}

char * getGuessResultMessage(enum guessResult result) {
	switch (result) {
		case TOO_HIGH:
			return "Your guess is too high!\n";
		case TOO_LOW:
			return "Your guess is too low!\n";
		default:
			return "You guessed it right!\n";
	}
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


// int main() {
// 	srand(time(NULL));
// 	int userPickedNumber;
// 	int computerPickedNumber = (rand() % 10) + 1;
// 
// 	banner();
// 	instructions();
// 
// 	while (true) {
// 		userPickedNumber = getNumberInput(128);
// 		if (userPickedNumber == 0) {
// 			printf("Please press enter to continue\n");
// 			clearBuffer();
// 			printf("Your number: ");
// 			continue;
// 		}
// 
// 		int guessResult = getGuessResult(userPickedNumber, computerPickedNumber);
// 		char *guessResultMessage = getGuessResultMessage(guessResult);
// 		printf("%s", guessResultMessage);
// 		if (guessResult != EQUAL) {
// 			continue;
// 		}
// 		printf("----YOU WON!----\n");
// 		return 0;
// 	}
// }
