#include <bits/stdc++.h>
using namespace std;
#define N_VERTICES 1000000

class DisjointSet {
	int p[N_VERTICES], rank[N_VERTICES];

  public:
	void make_set(int x) {
		p[x] = x;
		rank[x] = 0;
	}

	int find_set(int x) {
		if (x != p[x]) {
			p[x] = find_set(p[x]);
		}
		return p[x];
	}

	void union_set(int x, int y) {
		if (rank[x] > rank[y]) {
			p[y] = x;
		} else {
			p[x] = y;
			if (rank[x] == rank[y]) {
				rank[y]++;
			}
		}
	}

	bool same_set(int x, int y) {
		if (find_set(x) == find_set(y)) {
			return true;
		}
		return false;
	}
};

class Edge {
  public:
	int u, v, weight;
};

bool cmp(Edge a, Edge b) {
	return a.weight < b.weight;
}

int MST_Kruskal(int V, Edge edgeList[], int n) {
	DisjointSet ds;
	for (int i = 0; i < V; i++) {
		ds.make_set(i);
	}
	sort(edgeList, edgeList + n, cmp);
	int sum = 0;

	for (int i = 0; i < n; i++) {
		int u = edgeList[i].u;
		int v = edgeList[i].v;
		int weight = edgeList[i].weight;
		if (ds.find_set(u) != ds.find_set(v)) {
			sum += weight;
			ds.union_set(ds.find_set(u), ds.find_set(v));
			cout << u << "---" << v << endl;
		}
	}
	return sum;
}

int main() {
	// int V = 4, E = 5;
	// int edges[E][3] = {
	// 	{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
	// };

	int V = 9, E = 14;
	int edges[E][3] = {
		{0, 1, 10}, {0, 2, 12}, {1, 2, 9}, {1, 3, 8}, {2, 4, 4}, {2, 5, 1}, {3, 4, 7}, {3, 6, 8}, {3, 7, 5}, {4, 5, 3}, {5, 7, 6}, {6, 7, 9}, {6, 8, 2}, {7, 8, 11}
	};
	
	Edge edgeList[E];
	int cnt = 0;
	for (int i = 0; i < E; i++) {
		Edge e;
		e.u = edges[i][0];
		e.v = edges[i][1];
		e.weight = edges[i][2];
		edgeList[cnt] = e;
		cnt++;
	}

	cout << "MST\n";
	int sumOfWeight = MST_Kruskal(V, edgeList, cnt);
	cout << "Sum of edge weights " << sumOfWeight << endl;
}