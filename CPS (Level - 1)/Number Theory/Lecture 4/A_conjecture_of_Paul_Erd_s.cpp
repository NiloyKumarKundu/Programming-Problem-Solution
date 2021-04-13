#include <bits/stdc++.h>
#define Niloy
#define int int64_t
#define MAX (int) 1e7 + 123
#define MOD 1e9
#define pb push_back
#define pairs pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pairs>
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
#define llu unsigned long long
using namespace std;
/* ----------------------------------------------------------------------------------- */
#define scan(a)			  scanf("%lld", &a);
#define rep(i, a, n) for (int i = a; i < n; i++)
#define REP(i, a, n) for (int i = a; i <= n; i++)

/* ----------------------------------------------------------------------------------- */

bitset<MAX> isPrime;
vi Prime;
int ans[MAX];

void primeGen(int n) { 
	for (int i = 3; i <= n; i += 2) {
		isPrime[i] = 1;
	}
	isPrime[2] = 1;
	int sq = sqrt(n);

	for (int i = 3; i <= sq; i += 2) { 
		if (isPrime[i]) {
            for (int j = i * i; j <= n; j += (i * 2)) {
                isPrime[j] = 0;
            }
        }
	}

	Prime.pb(2);
	for (int i = 3; i <= n; i += 2) {
		if (isPrime[i]) {
			Prime.pb(i);
		}
	}
}

void solve() {
	int lim = 1e7;
	primeGen(lim);
    REP(x, 1, 3200) {
        REP(y, 1, 60) {
			int d = (x * x) + (y * y * y * y);
            if (d > lim) {
				continue;
			}
            if (isPrime[d]) {
				ans[d] = 1;
			}
		}
	}
    REP(i, 1, lim) {
		ans[i] += ans[i - 1];
	}
	int t;
	scan(t);
    while (t--) {
		int a;
		scan(a);
		cout << ans[a] << endl;
	}
}

int32_t main() {
    // input();
    // fastInput;
    solve();

    // __test {
    // 	solve();
    // }

    // showTime;
    return 0;
}
