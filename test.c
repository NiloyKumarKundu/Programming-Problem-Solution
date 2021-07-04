#include <stdio.h>

int main() {
	int numOne, numTwo;
	printf("Enter two number\n");
	scanf("%d %d", &numOne, &numTwo);

	printf("Addition: %d\n", numOne + numTwo);
	printf("Subtraction: %d\n", numOne - numTwo);
	printf("Multiplication: %d\n", numOne * numTwo);
    if (numTwo == 0) {
		printf("Divide by zero is not possible!!\n");
	} else {
		printf("Division: %.2lf\n", (numOne * 1.0) / numTwo);
	}
}