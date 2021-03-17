#pragma warning(disable : 4996)
#include <stdio.h>
#include <math.h>
#include "horoscopeTests.h"

void showMenuText(FILE* file) {
	fprintf(file, "Actions:\n");
	fprintf(file, "\t%-25s%5s\n", "Enter first people:", "EF");
	fprintf(file, "\t%-25s%5s\n", "Enter second people:", "ES");
	fprintf(file, "\t%-25s%5s\n", "Show moon sign:", "ShMS");
	fprintf(file, "\t%-25s%5s\n", "Is friendship possible:", "IFP");
	fprintf(file, "\t%-25s%5s\n", "Is business possible:", "IBP");
	fprintf(file, "\t%-25s%5s\n", "Is marriage possible:", "IMP");
	fprintf(file, "\t%-25s%5s\n", "Programm info", "info");
	fprintf(file, "\tPress Enter to exit.\n");
}

void setVars(int* date, int* month, int* sex, FILE* fileI, FILE* fileO) {
	fprintf(fileO, "Enter month(1 - 12): \n");
	int x;
	do {
		x = fscanf(fileI, "%d", month);
		if (!x || *month < 1 || *month > 12) fprintf(fileO, "Incorrect input!\n");
	} while (!x || *month < 1 || *month > 12);
	fprintf(fileO, "Enter date: \n");
	do {
		x = fscanf(fileI, "%d", date);
		if (!x || (*month == 2 && *date > 29) || *date < 1 || *date > 31) fprintf(fileO, "Incorrect input!\n");
	} while (!x || (*month == 2 && *date > 29) || *date < 1 || *date > 31);
	fprintf(fileO, "Enter sex(1 - man, 0 - women): \n");
	do {
		x = fscanf(fileI, "%d", sex);
		if (!x || !((*sex == 0 && *sex != 1) || (*sex != 0 && *sex == 1))) fprintf(fileO, "Incorrect input!\n");
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

void showSign(struct People people, FILE* file) {
	if (people.date == 0) {
		fprintf(file, "Set value before using ShMS\n");
		return;
	}
	if (people.sign == ARIES) fprintf(file, "ARIES\n");
	else if (people.sign == TAURUS) fprintf(file, "TAURUS\n");
	else if (people.sign == GEMINI) fprintf(file, "GEMINI\n");
	else if (people.sign == CANCER) fprintf(file, "CANCER\n");
	else if (people.sign == LEO) fprintf(file, "LEO\n");
	else if (people.sign == VIRGO) fprintf(file, "VIRGO\n");
	else if (people.sign == LIBRA) fprintf(file, "LIBRA\n");
	else if (people.sign == SCORPIO) fprintf(file, "SCORPIO\n");
	else if (people.sign == SAGITTARIUS) fprintf(file, "SAGITTARIUS\n");
	else if (people.sign == CAPRICORN) fprintf(file, "CAPRICORN\n");
	else if (people.sign == AQUARIUS) fprintf(file, "AQUARIUS\n");
	else fprintf(file, "PISCES\n");
}

void isFriendshipPossible(struct People first, struct People second, FILE* file) {
	if (first.date == 0 || second.date == 0) {
		fprintf(file, "Set values before using IFP\n");
		return;
	}
	if (first.element == second.element) fprintf(file, "Friendship is possible\n");
	else fprintf(file, "Friendship is not possible\n");
}

void isBusinessPossible(struct People first, struct People second, FILE* file) {
	if (first.date == 0 || second.date == 0) {
		fprintf(file, "Set values before using IBP\n");
		return;
	}
	if (abs(first.sign - second.sign) <= 1 || abs(first.sign - second.sign) == 11) fprintf(file, "Business is possible\n");
	else fprintf(file, "Business is not possible\n");
}

void isMarriagePossible(struct People first, struct People second, FILE* file) {
	if (first.date == 0 || second.date == 0) {
		fprintf(file, "Set values before using IMP\n");
		return;
	}
	if (first.sex != second.sex) {
		if ((first.element == AIR && second.element == WATER) || (first.element == WATER && second.element == AIR)) fprintf(file, "Marriage is possible\n");
		else if ((first.element == FIRE && second.element == EARTH) || (first.element == EARTH && second.element == FIRE)) fprintf(file, "Marriage is possible\n");
		else fprintf(file, "Marriage is not possible\n");
	}
	else fprintf(file, "Marriage is not possible\n");
}

void showInfo(FILE* file) {
	fprintf(file, "\n\nCreated by Egor Simakov\n");
	fprintf(file, "Version: %s\n\n", VERSION);
}