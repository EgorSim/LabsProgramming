#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "array3DTests.h"


int main(void) {
	FILE* fileAnswers = fopen("correctResults.txt", "r");
	FILE* fileResult = fopen("results.txt", "w");
	FILE* fileInput = fopen("input.txt", "r");
	assert(fileAnswers != NULL);
	assert(fileResult != NULL);
	assert(fileInput != NULL);

	/* Begin of testing functions----------------------------------*/
	int*** array3d;
	int x, y, z;
	int correctInput;

	fprintf(fileResult, "Enter x: ");
	do {
		correctInput = fscanf(fileInput, "%d", &x);
		if (!correctInput || x <= 0) {
			fprintf(fileResult, "\nIncorrect Input. Try again: ");
			while (getc(fileInput) != '\n');
		}
	} while (!correctInput || x <= 0);

	fprintf(fileResult, "Enter y: ");
	do {
		correctInput = fscanf(fileInput, "%d", &y);
		if (!correctInput || y <= 0) {
			fprintf(fileResult, "\nIncorrect Input. Try again: ");
			while (getc(stdin) != '\n');
		}
	} while (!correctInput || y <= 0);

	fprintf(fileResult, "Enter z: ");
	do {
		correctInput = fscanf(fileInput, "%d", &z);
		if (!correctInput || z <= 0) {
			fprintf(fileResult, "\nIncorrect Input. Try again: ");
			while (getc(stdin) != '\n');
		}
	} while (!correctInput || z <= 0);

	fprintf(fileResult, "%d\n%d\n%d\n", x, y, z);


	array3d = (int***)malloc(x * sizeof(int**));
	if (!array3d) {
		fprintf(fileResult, "Allocation error.");
		return 1;
	}
	int i, j;
	for (i = 0; i < x; i++) {
		array3d[i] = (int**)malloc(y * sizeof(int*));
		if (!array3d[i]) {
			fprintf(fileResult, "Allocation error.");
			return 1;
		}
	}
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			array3d[i][j] = (int*)malloc(z * sizeof(int));
			if (!array3d[i][j]) {
				fprintf(fileResult, "Allocation error.");
				return 1;
			}
		}
	}

	setArray(array3d, x, y, z, fileInput, fileResult);

	projection(array3d, x, y, z, fileResult);



	/* End of testing functions-------------------------------------*/

	fclose(fileResult);
	fileResult = fopen("results.txt", "r");
	assert(fileResult != NULL);



	while (!feof(fileResult)) {
		char ch1 = getc(fileAnswers);
		char ch2 = getc(fileResult);
		assert(ch1 == ch2);
	}

	return 0;
}