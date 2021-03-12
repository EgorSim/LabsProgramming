#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <math.h>

#define VERSION "1.0"

#define MAN 1
#define WOMEN 0

#define ARIES 1
#define TAURUS 2
#define GEMINI 3
#define CANCER 4
#define LEO 5
#define VIRGO 6
#define LIBRA 7
#define SCORPIO 8
#define SAGITTARIUS 9
#define CAPRICORN 10
#define AQUARIUS 11
#define PISCES 12

#define WATER 1 
#define FIRE 2
#define EARTH 3 
#define AIR 4 

struct People
{
	int date;
	int month;
	int sex;
	int sign;
	int element;
};

void showMenuText();
void setVars(int* date, int* month, int* sex);
void setPeople(struct People* people, int date, int month, int sex);
void showSign(struct People people);
void isFriendshipPossible(struct People first, struct People second);
void isBusinessPossible(struct People first, struct People second);
void isMarriagePossible(struct People first, struct People second);
void showInfo();

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



	system("pause");
	return 0;
}




void showMenuText() {
	printf("Actions:\n");
	printf("\t%-25s%5s\n", "Enter first people:", "EF");
	printf("\t%-25s%5s\n", "Enter second people:", "ES");
	printf("\t%-25s%5s\n", "Show moon sign:", "ShMS");
	printf("\t%-25s%5s\n", "Is friendship possible:", "IFP");
	printf("\t%-25s%5s\n", "Is business possible:", "IBP");
	printf("\t%-25s%5s\n", "Is marriage possible:", "IMP");
	printf("\t%-25s%5s\n", "Programm info", "info");
	printf("\tPress Enter to exit.\n");
}

void setVars(int* date, int* month, int* sex) {
	printf("Enter month(1 - 12): \n");
	int x;
	do {
		x = scanf("%d", month);
		fseek(stdin, 0, SEEK_END);
		if (!x || *month < 1 || *month > 12) printf("Incorrect input!\n");
	} while (!x || *month < 1 || *month > 12);
	printf("Enter date: \n");
	do {
		x = scanf("%d", date);
		fseek(stdin, 0, SEEK_END);
		if (!x || (*month == 2 && *date > 29) || *date < 1 || *date > 31) printf("Incorrect input!\n");
	} while (!x || (*month == 2 && *date > 29) || *date < 1 || *date > 31);
	printf("Enter sex(1 - man, 0 - women): \n");
	do {
		x = scanf("%d", sex);
		fseek(stdin, 0, SEEK_END);
		if (!x || !((*sex == 0 && *sex != 1) || (*sex != 0 && *sex == 1))) printf("Incorrect input!\n");
	} while (!((*sex == 0 && *sex != 1) || (*sex != 0 && *sex == 1)));
}

void setPeople(struct People* people, int date, int month, int sex) {
	(*people).date = date;
	(*people).month = month;
	(*people).sex = sex;
	if ((date >= 21 && month == 3) || (date <= 20 && month == 4)) {
		(*people).sign = ARIES;
		(*people).element = FIRE;
	}
	else if ((date >= 21 && month == 4) || (date <= 21 && month == 5)) {
		(*people).sign = TAURUS;
		(*people).element = EARTH;
	}
	else if ((date >= 22 && month == 5) || (date <= 21 && month == 6)) {
		(*people).sign = GEMINI;
		(*people).element = AIR;
	}
	else if ((date >= 22 && month == 6) || (date <= 22 && month == 7)) {
		(*people).sign = CANCER;
		(*people).element = WATER;
	}
	else if ((date >= 23 && month == 7) || (date <= 21 && month == 8)) {
		(*people).sign = LEO;
		(*people).element = FIRE;
	}
	else if ((date >= 22 && month == 8) || (date <= 23 && month == 9)) {
		(*people).sign = VIRGO;
		(*people).element = EARTH;
	}
	else if ((date >= 24 && month == 9) || (date <= 23 && month == 10)) {
		(*people).sign = LIBRA;
		(*people).element = AIR;
	}
	else if ((date >= 24 && month == 10) || (date <= 22 && month == 11)) {
		(*people).sign = SCORPIO;
		(*people).element = WATER;
	}
	else if ((date >= 23 && month == 11) || (date <= 22 && month == 12)) {
		(*people).sign = SAGITTARIUS;
		(*people).element = FIRE;
	}
	else if ((date >= 23 && month == 12) || (date <= 20 && month == 1)) {
		(*people).sign = CAPRICORN;
		(*people).element = EARTH;
	}
	else if ((date >= 21 && month == 1) || (date <= 19 && month == 2)) {
	(*people).sign = AQUARIUS;
	(*people).element = AIR;
	}
	else {
		(*people).sign = PISCES;
		(*people).element = WATER;
	}
}

void showSign(struct People people) {
	if (people.date == 0) {
		printf("Set value before using ShMS\n");
		return;
	}
	if (people.sign == ARIES) printf("ARIES\n");
	else if (people.sign == TAURUS) printf("TAURUS\n");
	else if (people.sign == GEMINI) printf("GEMINI\n");
	else if (people.sign == CANCER) printf("CANCER\n");
	else if (people.sign == LEO) printf("LEO\n");
	else if (people.sign == VIRGO) printf("VIRGO\n");
	else if (people.sign == LIBRA) printf("LIBRA\n");
	else if (people.sign == SCORPIO) printf("SCORPIO\n");
	else if (people.sign == SAGITTARIUS) printf("SAGITTARIUS\n");
	else if (people.sign == CAPRICORN) printf("CAPRICORN\n");
	else if (people.sign == AQUARIUS) printf("AQUARIUS\n");
	else printf("PISCES\n");
}

void isFriendshipPossible(struct People first, struct People second) {
	if (first.date == 0 || second.date == 0) {
		printf("Set values before using ShMS\n");
		return;
	}
	if (first.element == second.element) printf("Friendship is possible\n");
	else printf("Friendship is not possible\n");
}

void isBusinessPossible(struct People first, struct People second) {
	if (first.date == 0 || second.date == 0) {
		printf("Set values before using ShMS\n");
		return;
	}
	if (abs(first.sign - second.sign) <= 1 || abs(first.sign - second.sign) == 11) printf("Business is possible\n");
	else printf("Business is not possible\n");
}

void isMarriagePossible(struct People first, struct People second) {
	if (first.date == 0 || second.date == 0) {
		printf("Set values before using ShMS\n");
		return;
	}
	if (first.sex != second.sex) {
		if ((first.element == AIR && second.element == WATER) || (first.element == WATER && second.element == AIR)) printf("Marriage is possible\n");
		else if ((first.element == FIRE && second.element == EARTH) || (first.element == EARTH && second.element == FIRE)) printf("Marriage is possible\n");
		else printf("Marriage is not possible\n");
	}
	else printf("Marriage is not possible\n");
}

void showInfo() {
	printf("\n\nCreated by Egor Simakov\n");
	printf("Version: %s\n\n", VERSION);
}