#include <stdio.h>
#include <assert.h>
#include "toBinTestVersion.h"


int main(void) {
	FILE* fileAnswers = fopen("correctResults.txt", "r");
	FILE* fileResult = fopen("results.txt", "w");

	basic(10, fileResult);
	basic(56213, fileResult);
	basic(9846513, fileResult);
	basic(1659595667, fileResult);
	basic(2147483647, fileResult);

	fclose(fileResult);
	fileResult = fopen("results.txt", "r");


	while (!feof(fileResult)) {
		char ch1 = getc(fileAnswers);
		char ch2 = getc(fileResult);
		assert(ch1 == ch2);
	}


	printf("Tests complited successful\n");
	return 0;
}