#include <bits/stdc++.h>
#define Niloy
#define int int64_t
#define MAX (int) 1e6 + 123
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

// Input/Output
#define fastInput ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) x.begin(), x.end()
#define square(a) (a * a)
#define mem(a, b) memset(a, b, sizeof(a))

// Fractional Number
#define fraction()        cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed, ios::floatfield);

#define scan(a)			  scanf("%lld", &a);
#define scan2(a, b)		  scanf("%lld %lld", &a, &b);
#define scan3(a, b, c)	  scanf("%lld %lld %lld", &a, &b, &c);
#define scan4(a, b, c, d) scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
 
#define scanD(a)		  scanf("%lf", &a);
#define scanD2(a, b)	  scanf("%lf %lf", &a, &b);
#define scanD3(a, b, c)	  scanf("%lf %lf %lf", &a, &b, &c);
#define scanD4(a, b, c, d)scanf("%lf %lf %lf %lf", &a, &b, &c, &d);


#define print(a)		   printf("%lld\n", a);
#define print2(a, b)	   printf("%lld %lld\n", a, b);
#define print3(a, b, c)	   printf("%lld %lld %lld\n", a, b, c);
#define print4(a, b, c, d) printf("%lld %lld %lld %lld\n", a, b, c, d);
 
#define printD(a)		   printf("%lf\n", a);
#define printD2(a, b)	   printf("%lf %lf\n", a, b);
#define printD3(a, b, c)   printf("%lf %lf %lf\n", a, b, c);
#define printD4(a, b, c, d)printf("%lf %lf %lf %lf\n", a, b, c, d);
#define printTwoD(a)	   printf("%.2lf\n", a);

// File I/O
#define read(x)	 freopen(x, "r", stdin);
#define write(x) freopen(x, "w", stdout);
 
// Loops
#define rep(i, a, n) for (int i = a; i < n; i++)
#define REP(i, a, n) for (int i = a; i <= n; i++)
#define rev(i, n, a) for (int i = n - 1; i >= a; i--)
#define REV(i, n, a) for (int i = n; i >= a; i--)
#define inputArray(a,n) rep(i, 0, n) cin >> a[i];
#define copyArray(a,temp,n) rep(i, 0, n) temp[i]=a[i];
#define printArray(a,n) rep(i, 0, n) cout << a[i] << " "; cout << endl;
 
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


bitset<MAX> isPrime;
vi Prime;

void primeGen(int n) {      // O(N)
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

int NOD(int n) {
	int ans = 1;
    
    for (auto p : Prime) {
        if (p * p > n) {
			break;
		}
        if (n % p == 0) {
			int cnt = 1;
			while (n % p == 0) {
				cnt++;
				n /= p;
			}
			ans *= cnt;
		}
	}
    if (n > 1) {
		ans *= 2;
	}

	return ans;
}

void solve() {
	int arr[] = {1, 2, 3, 4, 5, 6, 8, 10, 12, 15, 20, 24, 30, 40, 60, 120};
	int sum = 0;
    rep(i, 0, 16) {
		sum += NOD(arr[i]);
	}
	cout << sum << endl;
}

int32_t main() {
    // input();
    // fastInput;
    int lim = 1e6;
	primeGen(lim);
    solve();

    // __test {
    // 	solve();
    // }

    // showTime;
    return 0;
}
