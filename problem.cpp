#include <iostream>
#include <math.h>
#include <algorithm>
#include <climits>
#include <string.h>
#include <cstdio>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <list>
#include <unordered_map>
using namespace std;

#define dbgA2(A, n, m)  {cout<<"-->"<<#A<<"=\n";for(int i = 0; i < n; i++){for(int j = 0; j < n; j++){cout<<A[i][j]<<" ";}cout<<"\n";}cout<<"\n";}
#define dbgA(A, n)      {cout<<"-->"<<#A<<"=(";for(int i = 0; i < n; i++)cout<<A[i]<<" ";cout<<")\n";}
#define dbg(args...)    {string sss(#args);sss+=',';cout<<"-->";debugger::call(sss.begin(), sss.end(), args);cout<<"\n";}

#define fo(i, j,n) for(i=j;i<n;i++)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pis(x)	printf("%d ",x)
#define pi(x)	printf("%d",x)
#define pl(x)	printf("%lld",x)
#define ps(s)	printf("%s",s)
#define lb()   printf("\n")
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;


struct debugger {
    typedef string::iterator si;

    static void call(si it, si ed) {}

    template<typename T, typename ... aT>
    static void call(si it, si ed, T a, aT... rest) {
        string b;
        for (; *it != ','; ++it)
            if (*it != ' ')
                b += *it;
        cout << b << "=" << a << " ";
        call(++it, ed, rest...);
    }
};


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
	int t; 
	si(t);
	while (t--) {
		int n;
		si(n);
		if (n == 1) {
			cout << 1 << "\n";
		} else if (n == 2) {
			cout << -1 << "\n";
		} else {
			int state = 1, count = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					int ans;
					if (state == 1) {
						ans = (count + 1) * 2 - 1; 
					} else {
						ans = (count + 1) * 2;
					}
					count++;
					printf("%d ", ans);
					if (count == (n * n) / 2 + 1) {
						count = 0;
						state *= -1;
					}
				}
				printf("\n");
			}
		}
	}

    return 0;
}