#include <stdio.h>

int main() {
	int c = 3, s = 8;
	int list[3][8];
	list[0][0] = 1;
	list[0][1] = 0;
	list[0][2] = 1;
	list[0][3] = 0;
    list[0][4] = 1;
    list[0][5] = 1;
    list[0][6] = 1;
    list[0][7] = 0;
    list[1][0] = 1;
    list[1][1] = 0;
    list[1][2] = 0;
    list[1][3] = 1;
    list[1][4] = 1;
    list[1][5] = 0;
    list[1][6] = 1;
    list[1][7] = 0;
    list[2][0] = 1;
    list[2][1] = 1;
    list[2][2] = 1;
    list[2][3] = 1;
    list[2][4] = 0;
    list[2][5] = 1;
    list[2][6] = 1;
    list[2][7] = 0;
    

	printf("Student who have the most number in the class is: ");
	int ans = 0, index = 0;
    for (int i = 0; i < c; i++) {
		int sum = 0;
		for (int j = 0; j < s; j++) {
			sum += list[i][j];
		}
        if (ans < sum) {
			ans = sum;
			index = i;
		}
	}
	printf("%d\n", index);

    printf("Student who have enrolled in all the classes are:\n");
	for (int i = 0; i < s; i++) {
		int sum = 0;
		for (int j = 0; j < c; j++) {
			sum += list[j][i];
		}
        if (sum == c) {
			printf("%d ", i);
		}
	}
	printf("\n");
}


/*
3 8
1 0 1 0 1 1 1 0
1 0 0 1 1 0 1 0
1 1 1 1 0 1 1 0
*/