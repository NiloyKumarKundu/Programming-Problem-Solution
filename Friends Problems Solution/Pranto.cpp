#include<stdio.h>

int main() {
	int a, b;
	printf("Input the first number: ");
	scanf("%d", &a);
	printf("Input the second number: ");
    scanf("%d", &b);
	if (a >= 0) {
		if (a % 2 == 0) {
			printf("First number is positive and even\n");
		} else {
            printf("First number is positive and odd\n");
		}
	} else if (a < 0) {
		if (a % 2 == 0) {
			printf("First number is negative and even\n");
		} else {
            printf("First number is negative and odd\n");
		}
	}
	if (b >= 0) {
        if (b % 2 == 0) {
			printf("Second number is positive and even\n");
		} else {
            printf("Second number is positive and odd\n");
		}
    } else {
        if (b % 2 == 0) {
			printf("Second number is negative and even\n");
		} else {
            printf("Second number is negative and odd\n");
		}
    }
}