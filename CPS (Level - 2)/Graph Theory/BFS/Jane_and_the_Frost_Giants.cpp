#include <bits/stdc++.h>
#define Niloy
#define int int64_t
#define mx (int) 212
#define inf (int) 2000000000
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

char grid[mx][mx];
int levelOfFire[mx][mx], levelOfJane[mx][mx];
vector<pairs> s;
int n, m;

void bfsFire() {
	mem(levelOfFire, -1);
	queue<pairs> q;
	for (auto u : s) {
		q.push({u});
		levelOfFire[u.first][u.second] = 0;
	}
    while (!q.empty()) {
		int x = q.front().first;
        int y = q.front().second;
		q.pop();

        rep(i, 0, 4) {
			int x1 = x + dx[i];
			int y1 = y + dy[i];
            if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && grid[x1][y1] != '#' && levelOfFire[x1][y1] == -1) {
				levelOfFire[x1][y1] = levelOfFire[x][y] + 1;
				q.push({x1, y1});
			}
		}
	}
}

void bfsJaneVai(int xs, int ys) {
	mem(levelOfJane, -1);
	queue<pairs> q;
	q.push({xs, ys});
	levelOfJane[xs][ys] = 0;

	while (!q.empty()) {
		int x = q.front().first;
        int y = q.front().second;
		q.pop();

        rep(i, 0, 4) {
			int x1 = x + dx[i];
			int y1 = y + dy[i];

            if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && grid[x1][y1] != '#' && levelOfJane[x1][y1] == -1 && levelOfJane[x][y] + 1 < levelOfFire[x1][y1]) {
				levelOfJane[x1][y1] = levelOfJane[x][y] + 1;
				q.push({x1, y1});
			}
		}
	}
}



void solve() {
	scan2(n, m);
	int x, y;
	s.clear();
	REP(i, 1, n) {
		REP(j, 1, m) {
			cin >> grid[i][j];
            if (grid[i][j] == 'J') {
				x = i;
				y = j;
			} else if (grid[i][j] == 'F') {
				s.pb({i, j});
			}
		}
	}

    // REP(i, 1, n) {
    //     REP(j, 1, m) {
	// 		cout << grid[i][j];
	// 	}
	// 	cout << endl;
	// }

	bfsFire();
	bfsJaneVai(x, y);
	int ans = inf;

    REP(i, 1, n) {
        if (levelOfJane[i][1] != -1) {
			ans = min(ans, levelOfJane[i][1]);
		}
	}

    REP(i, 1, n) {
        if (levelOfJane[i][m] != -1) {
			ans = min(ans, levelOfJane[i][m]);
		}
	}

    REP(i, 1, m) {
        if (levelOfJane[1][i] != -1) {
			ans = min(ans, levelOfJane[1][i]);
		}
	}
    REP(i, 1, m) {
        if (levelOfJane[n][i] != -1) {
			ans = min(ans, levelOfJane[n][i]);
		}
	}

    if (ans == inf) {
		cout << "IMPOSSIBLE\n";
	} else {
		cout << ans + 1 << endl;
	}
}

int32_t main() {
    // input();
    // fastInput;
    // solve();

    __test {
		Cases;
		solve();
	}

    // showTime;
    return 0;
}
