#include <bits/stdc++.h>
using namespace std;

int test(int w[], int v[], int n, int W) {
	int P[n + 1][W + 1];
	for (int w = 0; w <= W; w++) {
		P[0][w] = 0;
	}
	for (int i = 0; i <= n; i++) {
		P[i][0] = 0;
		if (i == 0) {
			continue;
		}
		int wi = w[i - 1];
		int vi = v[i - 1];
		for (int w = 1; w <= W; w++) {
			if (wi <= w) {
				if (vi + P[i - 1][w - wi] > P[i - 1][w]) {
					P[i][w] = vi + P[i - 1][w - wi];
				} else {
					P[i][w] = P[i - 1][w];
				}
			} else {
				P[i][w] = P[i - 1][w];
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int w = 0; w <= W; w++) {
			cout << P[i][w] << " ";
		}
		cout << endl;
	}
	cout << P[n][W];
}

int main() {
	int w[] = {2, 1, 3, 2};
	int v[] = {12, 10, 20, 15};
	int W = 5;
	int n = sizeof(w) / sizeof(w[0]);
	test(w, v, n, W);
}