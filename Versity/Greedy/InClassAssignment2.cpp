#include <bits/stdc++.h>
using namespace std;

int main () {
	double arrival[] = {2.00, 2.10, 3.00, 3.20, 3.50, 5.00};
	double departure[] = {2.30, 3.20, 3.40, 4.00, 4.30, 5.20};

	// double arrival[] = {9.00, 9.40, 9.50, 11.00, 15.00, 18.00};
	// double departure[] = {9.10, 12.00, 11.20, 11.30, 19.00, 20.00};

	int a = sizeof(arrival) / sizeof(arrival[0]);
	int d = sizeof(departure) / sizeof(departure[0]);

	sort(arrival, arrival + a);
	sort(departure, departure + d);

	vector<pair<double, char>> merged;
	int j = 0, k = 0;
	
	for (int i = 0; i < a + d; i++) {
		if (arrival[j] <= departure[k] && j < a) {
			merged.push_back({arrival[j], 'a'});
			j++;
		} else if (k < d) {
			merged.push_back({departure[k], 'd'});
			k++;
		}
	}

    // for (auto i : merged) {
	// 	cout << setprecision(2) << fixed << i.first << " " << i.second << endl;
	// }
	// cout << endl;

	pair<double, int> cnt;
	cnt.second = 0;
	int ans = -1;
	for (auto i : merged) {
		if (i.second == 'a') {
			cnt.first = i.first;
			cnt.second++;
		} else if (i.second == 'd') {
			cnt.second--;
		}
		ans = max(cnt.second, ans);
		if (cnt.first == i.first && i.second == 'd') {
			ans = cnt.second;
		}
	}
	cout << ans << endl;
}

