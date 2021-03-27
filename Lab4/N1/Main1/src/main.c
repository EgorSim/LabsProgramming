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
	char current = '\0';
	char prev;
	do {
		prev = current;
		current = getc(stdin);
		if (current == '.' || current == '!' || current == '?') {
			push_back(&vec, current);
			push_back(&vec, ' ');
			while ((current = getc(stdin)) == ' ');
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
	} while (current != '\n');
	vec.array[vec.size - 1] = '\0';
	printf(vec.array);

	return 0;
}