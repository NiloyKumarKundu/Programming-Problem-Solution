#include <stdio.h>

void calArea(double *radius) {
	double x = (*radius);
	double area = (3.1416 * x * x);
	double perimeter = (2 * 3.1416 * x);
	printf("Area = %.2lf\n", area);
	printf("Perimeter = %.2lf\n", perimeter);
}

int main() {
	double radius;
	printf("Enter the radius of the circle\n");
	scanf("%lf", &radius);
	calArea(&radius);
}

