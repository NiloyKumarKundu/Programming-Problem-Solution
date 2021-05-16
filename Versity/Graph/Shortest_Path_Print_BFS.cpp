#include <bits/stdc++.h>
#define mx (int) 10000
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;

vector<int> adj[mx];
int level[mx];
vector<int> parent(mx, -1);

void bfs(int s) {
	level[s] = 0;
	queue<int> q;
	q.push(s);
    while (!q.empty()) {
		int u = q.front();
		q.pop();
        for (auto v : adj[u]) {
            if (level[v] == -1) {
				level[v] = level[u] + 1;
				q.push(v);
				parent[v] = u;
			}
		}
	}
}

int main() {
	mem(level, -1);

	int n, e;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
	}
	int source, dest;
	cin >> source >> dest;
	
	bfs(source);

	if (level[dest] == 0) {
        cout << "No route\n";
		return 0;
	}

	vector<int> ans;
	ans.push_back(dest);
	while (parent[dest] != -1) {
        ans.push_back(parent[dest]);
        dest = parent[dest];
    }

	reverse(ans.begin(), ans.end());

	for (auto u : ans) {
        cout << u << " ";
    }
	cout << endl;
}


/*
Input: 

8 10
0 1
0 3
1 2
3 7
3 4
4 5
4 6
4 7
5 6
6 7
0 7


8 10
0 1
0 3
1 2
3 7
3 4
4 5
4 6
4 7
5 6
6 7
2 6

*/

