#include <stdio.h>
#include "toBinTestVersion.h"

void toBin(unsigned int x, FILE* file) {
	if (x == 0) return;
	toBin(x / 2, file);
	fprintf(file,"%d", x % 2);
}

void basic(unsigned int m, FILE* file) {
	unsigned int number = 3;

	int change = 0;
	while (number <= m) {
		fprintf(file, "%lu ", number);
		toBin(number, file);
		fprintf(file, "\n");
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