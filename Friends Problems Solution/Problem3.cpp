#include <stdio.h>

int main() {
	int d;
	double n;
	scanf("%lf %d", &n, &d);
	printf("%.*f\n", (int) d, (double) n);
}