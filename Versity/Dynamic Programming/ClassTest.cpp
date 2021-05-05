#include <bits/stdc++.h>
using namespace std;
char name[1000];
int w[1000], v[1000];

void Knapsack(int w[], int v[], int n, int W) {
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
	
	cout << P[n][W] << endl;
	int res = P[n][W];
	int a = W;
    for (int i = n; i > 0 && res > 0; i--) {
        if (res == P[i - 1][a])
            continue;       
        else {
			cout << name[i - 1] << endl;
			res = res - v[i - 1];
			a = a - w[i - 1];
		}
	}
}

int main() {
	int c, n;
	cin >> c >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> name[i] >> w[i] >> v[i];
	}
	Knapsack(w, v, n, c);
}