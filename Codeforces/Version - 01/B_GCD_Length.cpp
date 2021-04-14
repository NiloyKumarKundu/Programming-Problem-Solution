#include <bits/stdc++.h>
using namespace std;
 
int gcd(int n, int m) { return m ? gcd(m, n % m) : n; }
 
 
int main() {
	int t;
	cin >> t;
	for (int T = 0; T < t; T++) {
		int a, b, c;
		cin >> a >> b >> c;
		int temp1 = 1, temp2 = 1, temp3 = 1, cnt = 0;
		while (cnt < a - 1) {
			temp1 *= 10;
			cnt++;
		}
		cnt = 0;
		while (cnt < b - 1) {
			temp2 *= 10;
			cnt++;
		}
		cnt = 0;
		while (cnt < c - 1) {
			temp3 *= 10;
			cnt++;
		}
 
		int	temp4 = temp1 * 10;
		int temp5 = temp2 * 10;
		int temp6 = temp3 * 10;
 
		bool flag = false;
 
		for (int i = temp1; i < temp4; i++) {
			for (int j = temp2; j < temp5; j++) {
				int g = gcd(i, j);
				if (g >= temp3 && g < temp6) {
					cout << i << " " << j << endl;
					flag = true;
					break;
				}
			}
			if (flag) {
				break;
			}
		}
	}
	
	return 0;
}