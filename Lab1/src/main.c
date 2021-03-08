#include <stdio.h>
#include "toBin.h"

int main(void) {
	unsigned int number = 3;
	unsigned int m;
	
	int correctInput = scanf("%u", &m);
	printf("\n%d\n%d\n", m, correctInput);
	if (correctInput == 1 && m <= 2147483647) {
		int change = 0;

		while (number <= m) {
			printf("DEC: %11lu   ", number);
			printf("BIN: ");
			toBin(number);
			printf("\n");


			if (number > 1073741824) break;

			number <<= 2;

			if (change) {
				number |= 3;
				change--;
				continue;
			}

			change++;
		}
	}

	int change = 0;

	while (number <= m) {
		printf("DEC: %11lu   ", number);
		printf("BIN: ");
		toBin(number);
		printf("\n");


		if (number > 1073741824) break;

		number <<= 2;

		if (change) {
			number |= 3;
			change--;
			continue;
		}

		change++;
	}
	scanf("%d", &m);
	return 0;
}