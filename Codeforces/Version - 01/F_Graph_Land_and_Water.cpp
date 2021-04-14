#include <bits/stdc++.h>
#define Niloy
#define int int64_t
#define MAX 1000
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
#define all(x) x.begin(), x.end();

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
 
// Controling the Diagonal
int dx[] = {1, -1, 0, 0, -1, 1, -1, 1};
int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};

/* ----------------------------------------------------------------------------------- */
 
#define Cases  cout << "Case " << ++Case << ": ";
#define __test int tt; int Case=0; cin >> tt; while(tt--)
#define showTime cerr << "time = " << (clock() / CLOCKS_PER_SEC) << " sec" << '\n';
 
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

#define dbgA2(A, n, m) {cout<<"--> "<<#A<<" = \n";rep(i, 0, n){rep(j, 0, m){cout<<A[i][j]<<"";}cout<<"\n";}cout<<"\n";}
#define dbgA(A, n) {cout<<" --> "<<#A<<" = (";rep(i, 0, n)cout<<A[i]<<" ";cout<<")\n";}
#define dbg(args...) {string sss(#args);sss+=',';cout<<" --> ";debugger::call(all(sss), args);cout<<"\n";}

/* ----------------------------------------------------------------------------------- */
void input() {
#ifdef Niloy
    read("input.txt");  
    write("output.txt");
#endif
}

/* ----------------------------------------------------------------------------------- */

char Graph[100][100];
bool visited[100][100];
int COUNT = 0;

void findQuerySize(vector<string> input, int &row, int &col, int &query) {
	row = 0;
	col = input[0].size();
	// cout << "Col: " << input[0].size() << endl;
	rep(i, row, input.size()) {
		if (input[i][0] == 'L' || input[i][0] == 'W') {
			row++;
			// cout << "Row: " << row << endl;
		}
	}
	query = input.size() - row;
	return;
}


void separateIntegers(int &a, int &b, string str) {
	string temp = "";
	rep(i, 0, str.size()) {
		if (str[i] != ' ') {
			temp += str[i];
		} else {
			a = stoi(temp);
			temp = "";
		}
	}
	b = stoi(temp);
}

void makeQueries(vector<string> input, int row, vector<pairs> &queries) {
	for (int i = row; i < input.size(); i++) {
		int a, b;
		separateIntegers(a, b, input[i]);
		queries.pb({a, b});
	}
}

void makingTheGrid(vector<string> input, int row, int col) {
    rep(i, 0, row) {
        rep(j, 0, col) {
			Graph[i][j] = input[i][j];
		}
	}
}

void dfs(int row, int col, int i, int j) {
	if (i < 0 || i >= row || j < 0 || j >= col || Graph[i][j] == 'L' || visited[i][j]) {
		return;
	}
	visited[i][j] = true;
	COUNT++;

	rep(k, 0, 8) {
		dfs(row, col, i + dx[k], j + dy[k]);
	}
}

void solve() {
	int n;
	scan(n);
	getchar();
	// getchar();
	getchar();

    while (n--) {
		vector<string> input;
		string s;
		int row, col, query;

		while (getline(cin, s) && s.size()) {
			input.pb(s);
		}

		// for (string x : input) {
		// 	cout << x << endl;
		// }

		findQuerySize(input, row, col, query);
		// cout << "row: " << row << " col: " << col << " Query: " << query << endl;

		vector<pairs> queries;
		makeQueries(input, row, queries);

		memset(Graph, 0, sizeof(Graph));
		makingTheGrid(input, row, col);

		// rep(i, 0, row) {
        //     rep(j, 0, col) {
		// 		cout << Graph[i][j];
		// 	}
		// 	cout << endl;
		// }
        
        // for (auto x : queries) {
		// 	cout << x.first << " " << x.second << endl;
		// }

		for (auto x : queries) {
			COUNT = 0;
			memset(visited, 0, sizeof(visited));
			dfs(row, col, x.first - 1, x.second - 1);
			cout << COUNT << endl;
		}
		if (n) {
			cout << endl;
		}
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
