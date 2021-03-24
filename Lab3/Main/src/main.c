#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include "array3D.h"


int main(void)
{
	int*** array3d;
	int x, y, z;
	int correctInput;
		
	printf("Enter x: ");
	do {
		correctInput = scanf("%d", &x);
		if (!correctInput || x <= 0) {
			printf("\nIncorrect Input. Try again: ");
			while (getc(stdin) != '\n');
		}
	} while (!correctInput || x <= 0);

	printf("Enter y: ");
	do {
		correctInput = scanf("%d", &y);
		if (!correctInput || y <= 0) {
			printf("\nIncorrect Input. Try again: ");
			while (getc(stdin) != '\n');
		}
	} while (!correctInput || y <= 0);

	printf("Enter z: ");
	do {
		correctInput = scanf("%d", &z);
		if (!correctInput || z <= 0) {
			printf("\nIncorrect Input. Try again: ");
			while (getc(stdin) != '\n');
		}
	} while (!correctInput || z <= 0);

	printf("%d\n%d\n%d\n", x, y, z);


	array3d = (int***)malloc(x * sizeof(int**));
	if (!array3d) {
		printf("Allocation error.");
		return 1;
	}
	int i, j;
	for (i = 0; i < x; i++) {
		array3d[i] = (int**)malloc(y * sizeof(int*));
		if (!array3d[i]) {
			printf("Allocation error.");
			return 1;
		}
	}
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			array3d[i][j] = (int*)malloc(z * sizeof(int));
			if (!array3d[i][j]) {
				printf("Allocation error.");
				return 1;
			}
		}
	}

	setArray(array3d, x, y, z);

	projection(array3d, x, y, z);


	system("pause");
	return 0;
}