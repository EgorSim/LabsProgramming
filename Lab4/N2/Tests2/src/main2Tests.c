#pragma warning(disable : 4996)
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include "../../Main2/src/vector.h"


int main(void) {
	FILE* fileAnswers = fopen("N2/Tests2/src/correctResults.txt", "r");
	assert(fileAnswers != NULL);
	FILE* fileResult = fopen("N2/Tests2/src/results.txt", "w");
	assert(fileResult != NULL);
	FILE* fileInput = fopen("N2/Tests2/src/input.txt", "r");
	assert(fileInput != NULL);

	/* Begin of testing functions----------------------------------*/
	
	struct vectorC vec = { NULL, 1, 0 };
	vec.array = (char*)malloc(1 * sizeof(char));
	if (!vec.array) {
		fprintf(stderr, "Allocation error");
		exit(1);
	}
	vec.array[vec.capacity - 1] = '\0';
	char current;
	do {
		current = getc(fileInput);
		push_back(&vec, current);
	} while (!feof(fileInput));
	vec.array[vec.size - 1] = '\0';

	int i, max, currentLength;
	max = currentLength = 0;
	for (i = 0; i < vec.size; i++) {
		if (vec.array[i] == '(') {
			vec.array[i] = '{';
			currentLength++;
			if (currentLength > max) max = currentLength;
		}
		if (vec.array[i] == ')') {
			vec.array[i] = '}';
			currentLength--;
		}
	}
	if (!currentLength) {
		for (i = 0; i < vec.size; i++) {
			if (vec.array[i] == '{') {
				currentLength++;
				if (currentLength == max) vec.array[i] = '(';
				if (currentLength == max - 1) vec.array[i] = '[';
			}
			if (vec.array[i] == '}') {
				if (currentLength == max) vec.array[i] = ')';
				if (currentLength == max - 1) vec.array[i] = ']';
				currentLength--;
			}
		}
		fprintf(fileResult, vec.array);
	}
	else {
		fprintf(stderr, "Brackets sequence is incorrect!");
		exit(1);
	}


	/* End of testing functions-------------------------------------*/

	fclose(fileResult);
	fileResult = fopen("N2/Tests2/src/results.txt", "r");
	assert(fileResult != NULL);

	while (!feof(fileResult)) {
		char ch1 = getc(fileAnswers);
		char ch2 = getc(fileResult);
		assert(ch1 == ch2);
	}

	return 0;
}