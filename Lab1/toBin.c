#include <stdio.h>
#include "toBin.h"

void toBin(unsigned int x) {
	if (x == 0) return;
	toBin(x / 2);
	printf("%d", x % 2);
}