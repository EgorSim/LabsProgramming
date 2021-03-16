#include <math.h>
#include "series.h"

double series(double x, int n) {
	double minus = (n - 1) % 2 ? -1.0 : 1.0;
	double result = pow(x, (double)(2 * n - 1));
	double i;

	for (i = 1; i <= (2 * n - 1); i++) {
		result /= i;
	}
	return minus * result;
}