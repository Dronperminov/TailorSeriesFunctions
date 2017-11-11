#include <iostream>
#include <cmath>

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
	std::cout << "Enter x: ";
	std::cin >> x;

	std::cout << "sin(x): " << sin(x) << ", sinTailor(x): " << sinTailor(x) << std::endl;
	std::cout << "sinh(x): " << sinh(x) << ", shTailor(x): " << shTailor(x) << std::endl;
	std::cout << "cos(x): " << cos(x) << ", cosTailor(x): " << cosTailor(x) << std::endl;
	std::cout << "cosh(x): " << cosh(x) << ", chTailor(x): " << chTailor(x) << std::endl;
	std::cout << "atan(x): " << atan(x) << ", atanTailor(x): " << atanTailor(x) << std::endl;
	std::cout << "exp(x): " << exp(x) << ", expTailor(x): " << expTailor(x) << std::endl;
}