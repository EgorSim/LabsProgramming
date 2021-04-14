#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "vector.h"

int resize(struct vectorC* vec, size_t cap) {
	char* temp = realloc(vec->array, cap * sizeof(char));
	if (temp) return 1;
	free(vec->array);
	vec->array = temp;
	vec->capacity = cap;
	vec->array[vec->capacity - 1] = '\0';
	return 0;
}

void push_back(struct vectorC* vec, char ch) {
	if (vec->size == vec->capacity - 1) {
		if (resize(vec, (size_t)((vec->capacity + 1) * 1.5)) == 1) return;
	}
	vec->array[vec->size++] = ch;
}