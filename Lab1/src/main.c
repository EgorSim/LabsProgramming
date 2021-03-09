#include <stdio.h>
#include "toBin.h"

int main(void) {
	unsigned int number = 3;
	unsigned int m;
	
	int correctInput = scanf("%u", &m);
	if (correctInput == 1 && m <= 2147483647) {
		int change = 0;
		while (number <= m) {
			printf("DEC: %11u   ", number);
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
	system("pause");
	return 0;
}