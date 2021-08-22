#include <stdio.h>
#include <math.h>

int main() {
	char arr[10];
	printf("Enter equation");
	gets(arr);
	puts(arr);
	int a = (int) arr[0] - '0';
	int b = arr[4] - '0';
	int c = arr[7] - '0';


	double temp = (b * b) - (4 * a * c);
	if (temp < 0) {
		printf("immaginary root found!\n");
		return 0;
	}
	double root = -b + sqrt(temp);
	root /= (2 * a);

	double root2 = -b - sqrt(temp);
	root2 /= (2 * a);

	printf("%.2lf %.2lf\n", root, root2);
}