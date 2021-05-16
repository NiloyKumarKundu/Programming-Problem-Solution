#include<bits/stdc++.h>
#define mem(a, b) memset(a, b, sizeof(a))
#define mx 10000
using namespace std;

bool vis[mx];
vector<int> adj[mx];

bool dfs(int u, int p) {
	vis[u] = 1;

    for (auto v : adj[u]) {
        if (!vis[v]) {
			if (dfs(v, u)) {
				return true;
			}
		} else if (v != p) {
			return true;
		}
	}
	return false;
}

int main() {
	int n, e;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bool res = dfs(0, 0);
    if (res) {
		cout << "Cycle found\n";
	} else {
		cout << "Cycle not found\n";
	}
}


/*
Input:
4 4
0 1
0 2
1 2
2 3


4 3
0 1
1 2
2 3
*/