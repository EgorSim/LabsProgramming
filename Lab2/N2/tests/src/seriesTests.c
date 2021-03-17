#include <stdio.h>
#include <math.h>
#include "seriesTests.h"

double series(double x, int n) {
	double minus = (n - 1) % 2 ? -1.0 : 1.0;
	double result = pow(x, (double)(2 * n - 1));
	double i;

	for (i = 1; i <= (2 * n - 1); i++) {
		result /= i;
	}
	return minus * result;
}

void mainTest(FILE* fileI, FILE* fileO) {
	int correctInput;
	double x;
	do {
		fprintf(fileO, "Enter x: ");
		correctInput = fscanf(fileI, "%lf", &x);
		fprintf(fileO, "\n");
		if (!correctInput) while(getc(fileI) != '\n');
		if (!correctInput) fprintf(fileO, "\nIncorrect input!\n");
	} while (!correctInput);

	double epsilon;
	do {
		fprintf(fileO, "Enter epsilon: ");
		correctInput = fscanf(fileI, "%lf", &epsilon);
		if (!correctInput) while(getc(fileI) != '\n');
		fprintf(fileO, "\n");
		if (!correctInput || epsilon <= 0.0) fprintf(fileO, "\nIncorrect input!\n");
	} while (!correctInput || epsilon <= 0.0);

	double correctSin = sin(x);
	double seriesSin = 0.0;
	int n = 0;
	do {
		seriesSin += series(x, ++n);
	} while (fabs(correctSin - seriesSin) >= epsilon);

	fprintf(fileO, "n: %d\n", n);
}