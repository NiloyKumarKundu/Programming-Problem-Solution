#include <bits/stdc++.h>
using namespace std;
#define INF 99999
#define NIL -1

struct NODE {
	int v, value;
};

struct EDGE {
	int a, b;
	double weight;
};

struct CompareKey {
	bool operator()(NODE const &n1, NODE const &n2) {
		return n1.value > n2.value;
	}
};

int main() {
	int a, b;
	double w;
	int V = 9, E = 14;
	int edges[E][3] = {
		{0, 1, 10}, {0, 2, 12}, {1, 2, 9}, {1, 3, 8}, {2, 4, 4}, {2, 5, 1}, {3, 4, 7}, {3, 6, 8}, {3, 7, 5}, {4, 5, 3}, {5, 7, 6}, {6, 7, 9}, {6, 8, 2}, {7, 8, 11}};
	int s = 1;

	vector<EDGE> graph[V];

	for (int i = 0; i < E; i++) {
		a = edges[i][0];
		b = edges[i][1];
		w = edges[i][2];
		EDGE ab = {a, b, w};
		if (a < V && b < V && a >= 0 && b >= 0) {
			graph[a].push_back(ab);
		}
	}

	priority_queue<NODE, vector<NODE>, CompareKey> Q;
	int insideQ[V], dist[V], parent[V];

	for (int i = 0; i < V; i++) {
		dist[i] = INF;
		insideQ[i] = 1;
		parent[i] = -1;
	}
	dist[s] = 0;
	NODE r_node = {s, 0};
	Q.push(r_node);

	while (!Q.empty()) {
		NODE u_node = Q.top();
		int u = u_node.v;
		Q.pop();
		insideQ[u] = 0;
		// cout << u << " " << dist[u] << " " << parent[u] << endl;
		for (auto e : graph[u]) {
			int v = e.b;
			if (insideQ[v] == 1 && dist[v] > dist[u] + e.weight) {
				dist[v] = dist[u] + e.weight;
				parent[v] = u;
				Q.push({v, dist[v]});
				cout << v << " " << dist[v] << endl;
			}
		}
	}

	for (int i = 0; i < V; i++) {
		if (i == s) {
			cout << "sp from " << s << " to " << i << ": " << i << ", length: 0\n";
		} else if (parent[i] != -1) {
			cout << "sp from " << s << " to " << i << ": ";
			vector<int> p;
			int j = p[i];
			while (j != NIL) {
				p.push_back(j);
				j = p[j];
			}
			reverse(p.begin(), p.end());
			for (int i = 0; i < p.size(); i++) {
				cout << p[i] << " --> ";
			}
			cout << i << ", length: " << dist[i] << endl;
		} else {
			cout << "no path from " << s << " to " << i << endl;
		}
	}
}
