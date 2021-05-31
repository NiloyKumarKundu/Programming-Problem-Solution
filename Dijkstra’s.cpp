#include <bits/stdc++.h>
#define mx		  100000
#define INF		  99999
#define NIL		  -1
using namespace std;

struct Edge {
	int a, b;
	double w;
};

struct Node {
	int v, key;
};

struct CompareKey {
	bool operator()(Node const &n1, Node const &n2) {
		return n1.key > n2.key;
	}
};

int main() {
	int a, b;
	double w;
	int V = 4, E = 5;
	int edges[E][3] = {
		{0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
	int s = 1;

	vector<Edge> graph[V];

	for (int i = 0; i < E; i++) {
		a = edges[i][0];
		b = edges[i][1];
		w = edges[i][2];
		Edge ab = {a, b, w};
		Edge ba = {b, a, w};

		if (a < V && b < V && a >= 0 && b >= 0) {
			graph[a].push_back(ab);
		}
	}

	priority_queue<Node, vector<Node>, CompareKey> Q;
	int insideQ[V];

	int d[V], p[V];

	for (int i = 0; i < V; i++) {
		d[i] = INF;
		insideQ[i] = 1;
		p[i] = -1;
	}
	d[s] = 0;
	Node r_node = {s, 0};
	Q.push(r_node);

	while (!Q.empty()) {
		Node u_node = Q.top();
		int u = u_node.v;
		Q.pop();
		insideQ[u] = 0;

		for (auto e : graph[u]) {
			int v = e.b;
			if (insideQ[v] == 1 && d[v] > d[u] + e.w) {
				p[v] = u;
				d[v] = d[u] + e.w;
				Q.push({v, d[v]});
			}
		}
	}

	for (int i = 0; i < V; i++) {
		if (i == s) {
			cout << "sp from " << s << " to " << i << ": " << i << ", length: 0\n";
		} else if (p[i] != -1) {
			cout << "sp from " << s << " to " << i << ": ";
			vector<int> ans;
			int j = p[i];
			while (j != NIL) {
				ans.push_back(j);
				j = p[j];
			}
			reverse(ans.begin(), ans.end());
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i] << " --> ";
			}
			cout << i << ", length: " << d[i] << endl;
		} else {
			cout << "no path from " << s << " to " << i << endl;
		}
	}
}
