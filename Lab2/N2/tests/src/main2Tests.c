#pragma warning(disable : 4996)
#include <stdio.h>
#include <assert.h>
#include "seriesTests.h"


int main(void) {
	FILE* fileAnswers = fopen("correctResults2.txt", "r");
	FILE* fileResult = fopen("results2.txt", "w");
	FILE* fileInput = fopen("input2.txt", "r");

	/* Begin of testing functions----------------------------------*/
	mainTest(fileInput, fileResult);




	/* End of testing functions-------------------------------------*/

	fclose(fileResult);
	fileResult = fopen("results2.txt", "r");


	while (!feof(fileResult)) {
		char ch1 = getc(fileAnswers);
		char ch2 = getc(fileResult);
		assert(ch1 == ch2);
	}

	return 0;
}