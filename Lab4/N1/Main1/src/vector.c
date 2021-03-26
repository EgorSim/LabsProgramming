#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "vector.h"

int resize(struct vectorC* vec, size_t cap) {
	char* temp = vec->array;
	vec->array = (char*)malloc(cap * sizeof(char));
	if (!vec->array) exit(1);
	vec->array = (char*)memcpy(vec->array, temp, sizeof(char) * vec->size);
	vec->capacity = cap;
	vec->array[vec->capacity - 1] = '\0';
	free(temp);
}

void push_back(struct vectorC* vec, char ch) {
	if (vec->size == vec->capacity - 1) resize(vec, (size_t)((vec->capacity + 1) * 1.5));
	vec->array[vec->size++] = ch;
}