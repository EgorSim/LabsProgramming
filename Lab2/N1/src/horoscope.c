#include <stdio.h>
#include <math.h>
#include "horoscope.h"

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
		printf("Set values before using IFP\n");
		return;
	}
	if (first.element == second.element) printf("Friendship is possible\n");
	else printf("Friendship is not possible\n");
}

void isBusinessPossible(struct People first, struct People second) {
	if (first.date == 0 || second.date == 0) {
		printf("Set values before using IBP\n");
		return;
	}
	if (abs(first.sign - second.sign) <= 1 || abs(first.sign - second.sign) == 11) printf("Business is possible\n");
	else printf("Business is not possible\n");
}

void isMarriagePossible(struct People first, struct People second) {
	if (first.date == 0 || second.date == 0) {
		printf("Set values before using IMP\n");
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