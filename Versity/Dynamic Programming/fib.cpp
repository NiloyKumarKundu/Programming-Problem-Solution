//not a dynamic programming but used memoization system

#include <bits/stdc++.h>
using namespace std;

long long F[10000];
void init_table() {
	for (int i = 0; i < 10000; i++) {
		F[i] = -1;
	}
	F[0] = 0;
	F[1] = 1;
}
long long fib(int n) {
	if (n == 0 || n == 1) {
		return F[n];
	}

	if (F[n - 1] == -1) {
		F[n - 1] = fib(n - 1);
	}
	if (F[n - 2] == -1) {
		F[n - 2] = fib(n - 2);
	}
	return F[n - 1] + F[n - 2];
}

int main() {
	init_table();
	cout << fib(50);
	return 0;
}
