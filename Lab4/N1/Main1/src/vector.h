#ifndef VECTOR_H
#define VECTOR_H
#include <stddef.h>

struct vectorC
{
	char* array;
	size_t capacity;
	size_t size;
};

int resize(struct vectorC* vec, size_t cap);

void push_back(struct vectorC* vec, char ch);

#endif
