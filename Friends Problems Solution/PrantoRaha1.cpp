#include <stdio.h>
#include <math.h>

int main() {
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);

	double x = sqrt((b * b) - (4 * a * c));
	double res1 = (-b + x) / (2 * a);
	double res2 = (-b - x) / (2 * a);

	printf("X1 = %.3lf\nX2 = %.3lf\n", res1, res2);
}