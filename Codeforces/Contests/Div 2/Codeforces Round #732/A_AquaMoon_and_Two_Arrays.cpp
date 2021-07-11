#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, n) for (int i = a; i < n; i++)
#define REP(i, a, n) for (int i = a; i <= n; i++)
#define rev(i, n, a) for (int i = n - 1; i >= a; i--)
#define REV(i, n, a) for (int i = n; i >= a; i--)

void solve() {
	int n;
	cin >> n;
	int a[n], b[n];
	int sum1 = 0, sum2 = 0;
	rep(i, 0, n) {
		cin >> a[i];
		sum1 += a[i];
	}


	rep(i, 0, n) {
		cin >> b[i];
		sum2 += b[i];
	}

	vector<pair<int, int> > x; 
	if (sum1 == sum2) {
		rep(i, 0, n) {
			if (a[i] > b[i]) {
				rep(j, 0, n) {
					if (i == j)
						continue;
					if (a[j] < b[j]) {
						int k = min(a[i] - b[i], b[j] - a[j]);
						a[i] -= k;
						a[j] += k;
						rep(g, 0, k)
							x.push_back(make_pair(i + 1, j + 1));
						if (a[i] == b[i]) {
							break;
						}
					} 
				}
			}
			// dbg(a[i], b[i]);
		}

		cout << x.size() << "\n";
		for (auto i : x) {
			cout << i.first << " " << i.second << "\n";
		}
	} else {
		cout << -1 << "\n";
	}
}

int32_t main() {
    // input();
    // solve();

    int t;
    cin >> t;
    while (t--) {
		solve();
	}

	// showTime;
    return 0;
}
