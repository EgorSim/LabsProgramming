#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <climits>

int toBin(int a);

int main(void) {

	unsigned int number = 3;
	unsigned int m;

	scanf("%d", &m);

	int change = 0;

	while (number <= m) {
		printf("DEC: %11lu   ", number);
		printf("BIN: ");    toBin(number);
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
	return 0;
}

int toBin(unsigned int a) {
	int i = sizeof(int) * 8 - 1;
	int arr[sizeof(int) * 8] = { 0 };
	while (a != 0) {
		arr[i--] = a % 2;
		a >>= 1;
	}
	i = 0;
	while (i != sizeof(int) * 8) {
		printf("%d", arr[i++]);
		if (i % 4 == 0) printf(" ");
	}
}