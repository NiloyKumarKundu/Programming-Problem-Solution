#include <stdio.h>

int * func() {
	char ch[10];
	char *q;
	q = ch;
	for (int i = 0; i < 10; i++) {
		ch[i] = i + 'a';
	}

	return (int *) q;
}

int main() {
	int *p;
	p = func();

	for (int i = 0; i < 10; i++) {
		printf("%c ", p[i]);
	}
	printf("\n");
}