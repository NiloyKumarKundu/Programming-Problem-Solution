#include <bits/stdc++.h>
using namespace std;

int Fractional_Knapsack(int W, int v[], int w[], int n) {


    while (W > 0) {
		int k = 0, j = 0;
		for (int i = 0; i < n; i++) {
			int x = (v[i] / w[i]);
			if (x > k) {
				k = x;
				j = i;
			}
		}
		int x = min(1, (W / w[j]));
		w = (w - (x * w[j]));
	}
}


int main() {

}