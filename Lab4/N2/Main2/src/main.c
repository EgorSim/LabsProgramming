#include <stdio.h>
#include <stdlib.h>
#include "vector.h"


int main(void)
{
	struct vectorC vec = { NULL, 1, 0 };
	vec.array = (char*)malloc(1 * sizeof(char));
	if (!vec.array) {
		fprintf(stderr, "Allocation error");
		exit(1);
	}
	vec.array[vec.capacity - 1] = '\0';
	char current;
	do {
		current = getc(stdin);
		push_back(&vec, current);
	} while (current != '\n');
	vec.array[vec.size - 1] = '\0';

	printf(vec.array);


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
		printf(vec.array);
	}
	else {
		fprintf(stderr, "Brackets sequence is incorrect!");
		exit(1);
	}




	getc(stdin);
	return 0;
}