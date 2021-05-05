#include <bits/stdc++.h>
using namespace std;
#define INFINITY 999999;

int DPChange(int M, int c[], int d) {
	int best_Num_Coins[M + 1], chosen_coin[M + 1];
	best_Num_Coins[0] = 0;

	for (int m = 1; m <= M; m++) {
		best_Num_Coins[m] = INFINITY;
		for (int i = 0; i < d; i++) {
		       if (m >= c[i]) {
				if (best_Num_Coins[m - c[i]] + 1 < best_Num_Coins[m]) {
					best_Num_Coins[m] = best_Num_Coins[m - c[i]] + 1;
					chosen_coin[m] = c[i];
				}
			}
		}
	}
	int m = M;
	cout << "Chosen coins are: ";
	while (m > 0) {
		cout << chosen_coin[m] << ",";
		m = m - chosen_coin[m];
	}
	cout << endl;
	return best_Num_Coins[M];
}
int main() {
	int c[] = {1, 3, 5};
	int d = sizeof(c) / sizeof(c[0]);
	int M = 10;
	int count = DPChange(M, c, d);
	cout << "Number of coins: " << count << endl;
	return 0;
}
