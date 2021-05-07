#include <bits/stdc++.h>
using namespace std;
#define N_VERTICES 1000

class DisjointSet {
	int p[N_VERTICES];

  public:
	void make_set(int x) {
		p[x] = x;
	}

	int find_set(int x) {
        while (x != p[x]) {
			x = p[x];
		}
		return x;
	}

	void union_set(int x, int y) {
		int a = find_set(x);
		int b = find_set(y);
		p[a] = b;
	}

    bool same_set(int x, int y) {
        if (find_set(x) == find_set(y)) {
			return true;
		}
		return false;
	}
};


class Graph {
  public:
	int mat[N_VERTICES][N_VERTICES];

    void init_graph() {
		for (int i = 0; i < N_VERTICES; i++) {
			for (int j = 0; j < N_VERTICES; j++) {
				mat[i][j] = 0;
			}
		}
	}

    void add_edge(int u, int v) {
		mat[u][v] = 1;
		mat[v][u] = 1;
	}

    DisjointSet connected_component(int n) {
        DisjointSet S;
		for (int i = 0; i < n; i++) {
			S.make_set(i);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (mat[i][j]) {
					if (S.find_set(i) != S.find_set(j)) {
						S.union_set(i, j);
					}
				}
			}
		}
		return S;
	}
};


int main() {
	Graph G;
	G.init_graph();

	int v, e;
	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		G.add_edge(u, v);
	}

	DisjointSet ds = G.connected_component(v);

	set<int> st;
	for (int i = 0; i < v; i++) {
		st.insert(ds.find_set(i));
	}
	cout << st.size() << endl;
}


/*
Input:

4
3
0 1
2 3
3 2

3
3
0 1
1 2
2 0

*/

