#include <stdio.h>
#include <math.h>

const double eps = 1e-16;

double sinTailor(double x) {
	size_t n = 1;
	int sign = 1;
	double fact = 1;
	double y = x;
	x *= x;

	double sum = 0, sum2;

	do {
		sum2 = sum;
		sum += sign * y / fact;

		sign = -sign;
		fact *= (2 * n + 1) * (2 * n);
		n++;
		y *= x;
	} while (fabs(sum2 - sum) > eps);

	return sum;
}

double cosTailor(double x) {
	size_t n = 1;
	int sign = 1;
	double fact = 1;
	double y = 1;
	x *= x;

	double sum = 0, sum2;

	do {
		sum2 = sum;
		sum += sign * y / fact;

		sign = -sign;
		fact *= (2 * n) * (2 * n - 1);
		n++;
		y *= x;
	} while (fabs(sum2 - sum) > eps);

	return sum;
}

double expTailor(double x) {
	double y = x;
	double n = 1;
	double fact = 1;

	double sum = 1, sum2;

	do {
		sum2 = sum;
		sum += y / fact;

		fact *= ++n;
		y *= x;
	} while (fabs(sum2 - sum) > eps);

	return sum;
}

double shTailor(double x) {
	size_t n = 1;
	double fact = 1;
	double y = x;
	x *= x;

	double sum = 0, sum2;

	do {
		sum2 = sum;
		sum += y / fact;

		fact *= (2 * n + 1) * (2 * n);
		n++;
		y *= x;
	} while (fabs(sum2 - sum) > eps);

	return sum;
}

double chTailor(double x) {
	size_t n = 1;
	double fact = 1;
	double y = 1;
	x *= x;

	double sum = 0, sum2;

	do {
		sum2 = sum;
		sum += y / fact;

		fact *= (2 * n) * (2 * n - 1);
		n++;
		y *= x;
	} while (fabs(sum2 - sum) > eps);

	return sum;
}

double atanTailor(double x) {
	size_t n = 1;
	double y = x;
	int sign = 1;
	x *= x;

	double sum = 0, sum2;

	do {
		sum2 = sum;
		sum += sign * y / (2 * n - 1);

		sign = -sign;
		n++;
		y *= x;
	} while (fabs(sum2 - sum) > eps);

	return sum;
}

int main() {
	double x;
	printf("Enter x: ");
	scanf("%lf", &x);

	printf("sin(x): %.10lf, sinTailor(x): %.10lf\n", sin(x), sinTailor(x));
	printf("sinh(x): %.10lf, shTailor(x): %.10lf\n", sinh(x), shTailor(x));
	printf("cos(x): %.10lf, cosTailor(x): %.10lf\n", cos(x), cosTailor(x));
	printf("cosh(x): %.10lf, chTailor(x): %.10lf\n", cosh(x), chTailor(x));
	printf("atan(x): %.10lf, atanTailor(x): %.10lf\n", atan(x), atanTailor(x));
	printf("exp(x): %.10lf, expTailor(x): %.10lf\n", exp(x), expTailor(x));
}