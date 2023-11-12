#include <stdio.h>
#include <stdbool.h>

int banner() {
	printf("------------------------\n");
	printf("------------------------\n");
	printf("----GUESS THE NUMBER----\n");
	printf("------------------------\n");
	printf("------------------------\n");
	return 0;
}

int instructions() {
	printf("Pick a number between 1 and 10. Your objective is to guess the number I am thinking of!");
	printf("Your number: ");
	return 0;
}


int main() {
	int pickedNumber;
	bool isPlaying = true;

	banner();
	instructions();

	while (isPlaying) {
		scanf("%d", &pickedNumber);
		if (pickedNumber != 5) {
			printf("Oops, that wasn't the number I was thinking of. Please try again");
		}
		else {
			printf("----YOU WON!----\n");
			isPlaying = false;
		}
	}
	return 0;
}
