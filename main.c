#include <stdio.h>

int getFahrenheit(int celsius) {
	return (celsius * 9/5) + 32;
}





int main() {
	int start = 0;
	int end = 10;

	for (int i=0; i < end; i++) {
		printf("%d", start);
		start += 1;
	}
	return 0;
}
