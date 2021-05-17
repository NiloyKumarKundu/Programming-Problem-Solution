#include<bits/stdc++.h>
#define mem(a, b) memset(a, b, sizeof(a))
#define mx 10000
using namespace std;

int vis[mx];
vector<int> adj[mx];
set<pair<int,int>> edge;

bool detectCycle(int u, int p) {
	vis[u] = 1;
    for (auto v : adj[u]) {
        if (!vis[v]) {
			if (detectCycle(v, u)) {
				edge.insert({u, v});
				return true;
			}
		} else if (v != p) {
			edge.insert({u, v});
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
	}

	bool flag = true;
	for (int i = 1; i <= n; i++) {
		mem(vis, 0);
		if (!vis[i]) {
			bool res = detectCycle(i, i);
			if (res) {
				flag = false;
			}
		}
	}

	if (flag) {
		cout << "No cycle found\n";
	} else {
		cout << "Cycle found\n";
		cout << "Back edges are: \n";
		for (auto i : edge) {
			cout << i.first << " " << i.second << endl;
		}
	}
}

/*
Input:
4 4
1 2
3 1
2 3
3 4


4 5
1 2
3 1
2 3
4 3
1 4

4 3
0 1
1 2
2 3

5 6
1 2
2 3
2 4
3 4
4 5
5 1
*/