#include<bits/stdc++.h>
#define mem(a, b) memset(a, b, sizeof(a))
#define mx 100000
#define INF 99999
#define NIL -1
using namespace std;

struct Edge {
	int a, b;
	double w;
};

struct Node {
	int v, key;
};

struct CompareKey {
    bool operator() (Node const &n1, Node const &n2) {
		return n1.key > n2.key;
	}
};

int main() {
    int a, b;
	double w;
	int V = 9, E = 14;
	int edges[E][3] = {
        {0, 1, 10},
        {0, 2, 12},
        {1, 2, 9},
        {1, 3, 8},
        {2, 4, 3},
        {2, 5, 1},
        {3, 4, 7},
        {3, 6, 8},
        {3, 7, 5},
        {4, 5, 3},
		{5, 7, 6},
		{6, 7, 9},
		{6, 8, 2},
		{7, 8, 11}
    };
	vector<Edge> graph[V];

	for (int i = 0; i < E; i++) {
		a = edges[i][0];
		b = edges[i][1];
		w = edges[i][2];
		Edge ab = {a, b, w};
		Edge ba = {b, a, w};

        if (a < V && b < V && a >= 0 && b >= 0) {
			graph[a].push_back(ab);
			graph[b].push_back(ba);
		}
	}

	for (int i = 0; i < V; i++) {
		cout << i << ": ";
        for (auto e : graph[i]) {
			cout << "(" << e.b << ", " << e.w << ")";
		}
		cout << endl;
	}

    // Prim's Algorithm
	priority_queue<Node, vector<Node>, CompareKey> Q;
	int insideQ[V];
	int p[V];
	int key[V];

	for (int i = 0; i < V; i++) {
		key[i] = INF;
		insideQ[i] = 1;
		p[i] = NIL;
	}
	int r = 0;
	key[r] = 0;
	p[r] = NIL;

	Node r_node = {r, 0};
	Q.push(r_node);

    while (!Q.empty()) {
		Node u_node = Q.top();
		int u = u_node.v;
		Q.pop();
		insideQ[u] = 0;

		for (auto e : graph[u]) {
			int v = e.b;
            if (insideQ[v] == 1 && e.w < key[v]) {
				p[v] = u;
				key[v] = e.w;
				cout << "\tv: " << v << " " << e.w << endl;
				Q.push({v, key[v]});
			}
		}
	}

	cout << "MST\n";
	for (int i = 0; i < V; i++) {
        if (p[i] != NIL) {
		    cout << p[i] << " " << i << endl;
        }
	}
}
