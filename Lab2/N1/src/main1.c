#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "horoscope.h"

int main(void)
{
	struct People firstPeople = { 0, 0, 0 };
	struct People secondtPeople = { 0, 0, 0 };

	char menu[10];
	do {
		showMenuText();
		fgets(menu, 10, stdin);
		fseek(stdin, 0, SEEK_END);
		if (!strcmp(menu, "EF\n")) {
			int date, month, sex;
			setVars(&date, &month, &sex);
			setPeople(&firstPeople, date, month, sex);
		}
		else if (!strcmp(menu, "ES\n")) {
			int date, month, sex;
			setVars(&date, &month, &sex);
			setPeople(&secondtPeople, date, month, sex);
		}
		else if (!strcmp(menu, "ShMS\n")) {
			printf("Moon sign of the first people: ");
			showSign(firstPeople);
			printf("Moon sign of the second people: ");
			showSign(secondtPeople);
		}
		else if (!strcmp(menu, "IFP\n")) {
			isFriendshipPossible(firstPeople, secondtPeople);
		}
		else if (!strcmp(menu, "IBP\n")) {
			isBusinessPossible(firstPeople, secondtPeople);
		}
		else if (!strcmp(menu, "IMP\n")) {
			isMarriagePossible(firstPeople, secondtPeople);
		}
		else if (!strcmp(menu, "info\n")) {
			showInfo();
		}
		else if (strcmp(menu, "\n")) printf("Unknown command!\n");

	} while (strcmp(menu, "\n"));

	return 0;
}