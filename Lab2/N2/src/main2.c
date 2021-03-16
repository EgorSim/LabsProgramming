#pragma warning(disable : 4996)
#include <stdio.h>
#include <math.h>
#include "series.h"


int main(void)
{
	int correctInput;
	double x;
	do {
		printf("Enter x: ");
		correctInput = scanf("%lf", &x);
		if (!correctInput) printf("\nIncorrect input!\n");
	} while (!correctInput);

	double epsilon;
	do {
		printf("Enter epsilon: ");
		correctInput = scanf("%lf", &epsilon);
		if (!correctInput || epsilon <= 0.0) printf("\nIncorrect input!\n");
	} while (!correctInput || epsilon <= 0.0);

	double correctSin = sin(x);
	double seriesSin = 0.0;
	int n = 0;
	double temp;
	do {
		seriesSin += series(x, ++n);
		temp = fabs(correctSin - seriesSin);
	} while (temp >= epsilon);

	printf("n: %d\n", n);

	return 0;
}