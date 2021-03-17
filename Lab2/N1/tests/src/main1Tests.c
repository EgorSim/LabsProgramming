#pragma warning(disable : 4996)
#include <stdio.h>
#include <assert.h>
#include "horoscopeTests.h"



int main(void) {
	FILE* fileAnswers = fopen("correctResults1.txt", "r");
	FILE* fileResult = fopen("results1.txt", "w");
	FILE* fileInput = fopen("input1.txt", "r");

	/* Begin of testing functions----------------------------------*/
	assert(fileAnswers != NULL);
	assert(fileResult != NULL);
	assert(fileInput != NULL);



	struct People firstPeople = { 0, 0, 0 };
	struct People secondtPeople = { 0, 0, 0 };

	int date, month, sex;



	showMenuText(fileResult);
	setVars(&date, &month, &sex, fileInput, fileResult);
	setPeople(&firstPeople, date, month, sex);
	showSign(firstPeople, fileResult);
	showSign(secondtPeople, fileResult);
	isBusinessPossible(firstPeople, secondtPeople, fileResult);
	isFriendshipPossible(firstPeople, secondtPeople, fileResult);
	isMarriagePossible(firstPeople, secondtPeople, fileResult);
	setVars(&date, &month, &sex, fileInput, fileResult);
	setPeople(&secondtPeople, date, month, sex);
	showSign(firstPeople, fileResult);
	showSign(secondtPeople, fileResult);
	isBusinessPossible(firstPeople, secondtPeople, fileResult);
	isFriendshipPossible(firstPeople, secondtPeople, fileResult);
	isMarriagePossible(firstPeople, secondtPeople, fileResult);
	setVars(&date, &month, &sex, fileInput, fileResult);







	/* End of testing functions-------------------------------------*/

	fclose(fileResult);
	fileResult = fopen("results1.txt", "r");


	while (!feof(fileResult)) {
		char ch1 = getc(fileAnswers);
		char ch2 = getc(fileResult);
		assert(ch1 == ch2);
	}

	return 0;
}