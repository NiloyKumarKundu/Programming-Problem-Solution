#include <bits/stdc++.h>
#define max 10000 + 5
#define mod 10000 + 5
#define pb push_back
#define pairs pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pairs>
#define lb lower_bound
#define ub upper_bound
#define lli long long int
#define endl '\n'
using namespace std;

vi graph[max];
vb visited;
int dist[max];

void dfs(int n, int dis) {
    visited[n] = true;
    dist[n] = dis;

    for(int i : graph[n]) {
        if(!visited[n]) {
            dfs(i, dis + 1);
        }
    }
}


int main() {
    int n, a, b, q;
    vi girls;
    cin >> n;
    visited.assign(n + 1, false);
    memset(dist, 0, sizeof(dist));

    for (int i = 1; i <= n - 1; i++) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    cin >> q;
    while(q--) {
        cin >> a;
        girls.pb(a);
    }

    dfs(1, 0);

    sort(girls.begin(), girls.end());
    
    int min = (INT_MAX / 2);
    for(int i = 0; i < n; i++) {
        if(min > dist[girls[i]]) {
            min = girls[i];
            break;
        }
    }

    cout << min << endl;

    return 0;
}
