#include <bits/stdc++.h>
#define Niloy
#define int int64_t
#define mx (int) 1e7 + 123
#define MOD (int) 1e7 + 7
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

// Input/Output
#define fastInput ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) x.begin(), x.end()
#define square(a) (a * a)
#define mem(a, b) memset(a, b, sizeof(a))

// Fractional Number
#define fraction()        cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed, ios::floatfield);

// Direction Array
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

// File I/O
#define read(x)	 freopen(x, "r", stdin);
#define write(x) freopen(x, "w", stdout);
 
// Loops
#define rep(i, a, n) for (int i = a; i < n; i++)
#define REP(i, a, n) for (int i = a; i <= n; i++)
#define rev(i, n, a) for (int i = n - 1; i >= a; i--)
#define REV(i, n, a) for (int i = n; i >= a; i--)
 
/* ----------------------------------------------------------------------------------- */
 
#define Cases  cout << "Case " << ++Case << ": ";
#define __test int tt; int Case=0; cin >> tt; while(tt--)
#define showTime cerr << "time = " << (clock() / CLOCKS_PER_SEC) << " sec" << '\n';
 
#define dbgA2(A, n, m) {cout<<"--> "<<#A<<" = \n";rep(i, 0, n){rep(j, 0, m){cout<<A[i][j]<<"";}cout<<"\n";}cout<<"\n";}
#define dbgA(A, n) {cout<<" --> "<<#A<<" = (";rep(i, 0, n)cout<<A[i]<<" ";cout<<")\n";}
#define dbg(args...) {string sss(#args);sss+=',';cout<<" --> ";debugger::call(all(sss), args);cout<<"\n";}
 
/* ----------------------------------------------------------------------------------- */
 
int gcd(int n, int m) { return m ? gcd(m, n % m) : n; }
int lcm(int n, int m) { return n / gcd(n, m) * m; }
 
struct debugger {
    typedef string::iterator si;
    static void call(si it, si ed) {}
    template<typename T, typename ... aT>
    static void call(si it, si ed, T a, aT... rest) {
        string b;
        for(; *it!=','; ++it)
            if(*it!=' ')
                b+=*it;
        cout << b << "=" << a << " ";
        call(++it, ed, rest...);
    }
};

/* ----------------------------------------------------------------------------------- */
void input() {
#ifdef Niloy
    read("input.txt");  
    write("output.txt");
#endif
}

/* ----------------------------------------------------------------------------------- */

bitset<mx> isPrime;
vi Prime;

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
    int n;
	int lim = 1e6;
	primeGen(lim);

	while (cin >> n && n) {
		int ans = 1;
		for (auto p : Prime) {
			if (p > n) {
				break;
			}
			int cnt = 1;
			int tmp = n;
			while (tmp > 0) {
				cnt += (tmp / p);
				tmp /= p;
			}
            int sum = ((cnt * (cnt + 1)) / 2);
			sum %= MOD;
			ans *= sum;
			ans %= MOD;
		}
		cout << ans << endl;
	}
}

int32_t main() {
    // input();
    fastInput;
    solve();

    // __test {
    // 	solve();
    // }

    // showTime;
    return 0;
}
