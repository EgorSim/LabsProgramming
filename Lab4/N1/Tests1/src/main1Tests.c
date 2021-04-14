#pragma warning(disable : 4996)
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include "../../Main1/src/vector.h"


int main(void) {
	FILE* fileAnswers = fopen("N1/Tests1/src/correctResults.txt", "r");
	assert(fileAnswers != NULL);
	FILE* fileResult = fopen("N1/Tests1/src/results.txt", "w");
	assert(fileResult != NULL);
	FILE* fileInput = fopen("N1/Tests1/src/input.txt", "r");
	assert(fileInput != NULL);

	/* Begin of testing functions----------------------------------*/
	
	struct vectorC vec = { NULL, 1, 0 };
	vec.array = (char*)malloc(1 * sizeof(char));
	if (!vec.array) {
		fprintf(stderr, "Allocation error");
		exit(1);
	}
	vec.array[vec.capacity - 1] = '\0';
	char current = '\0';
	char prev;
	do {
		prev = current;
		current = getc(fileInput);
		if (current == '.' || current == '!' || current == '?') {
			push_back(&vec, current);
			push_back(&vec, ' ');
			while ((current = getc(fileInput)) == ' ');
			push_back(&vec, toupper(current));
			current = toupper(current);
			continue;
		}
		if (current == ',' || current == ':' || current == ';') {
			push_back(&vec, current);
			current = ' ';
			push_back(&vec, current);
			continue;
		}
		if (current == ' ' && prev == ' ') continue;
		push_back(&vec, current);
	} while (!feof(fileInput));
	vec.array[vec.size - 1] = '\0';
	fprintf(fileResult, vec.array);

	/* End of testing functions-------------------------------------*/

	fclose(fileResult);
	fileResult = fopen("N1/Tests1/src/results.txt", "r");
	assert(fileResult != NULL);

	while (!feof(fileResult)) {
		char ch1 = getc(fileAnswers);
		char ch2 = getc(fileResult);
		assert(ch1 == ch2);
	}

	return 0;
}