#include <bits/stdc++.h>
using namespace std;
const int mx = 10000;

int n;
vector<int> adj[mx];
vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void find_cycle() {
	
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (color[v] == 0 && dfs(v))
            break;
    }

    if (cycle_start == -1) {
        cout << "No cycle found!" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);

        cycle.push_back(cycle_start);

        reverse(cycle.begin(), cycle.end());

        cout << "Cycle found: ";
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

    color.assign(n, 0);
	parent.assign(n, -1);

	find_cycle();
}



/*

4
0 1
2 0
1 2
2 3

6
0 1
1 2
1 3
2 3
3 4
4 0

*/