#include <stdio.h>

int main() {
    int C = 73;
	int Z = 73 + 5;
	int A = 73 + 30;

    if (C > A) {
		printf("Greater number is: %d\n", C);
	} else if (A > C) {
        printf("Greater number is: %d\n", A);
    } else {
        printf("Both numbers are same!\n");
    }
}