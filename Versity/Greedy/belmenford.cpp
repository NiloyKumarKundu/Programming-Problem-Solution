#include<bits/stdc++.h>
#define mem(a, b) memset(a, b, sizeof(a))
#define mx 100000
#define INF 2147483647
#define NIL -1
using namespace std;

struct Edge {
	int u, v;
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
			cout << "(" << e.v << ", " << e.w << ")";
		}
		cout << endl;
	}

    // Bellman Ford
	int d[V], p[V];
	for (int v = 0; v < V; v++) {
		d[v] = INF;
		p[v] = -1;
	}
	int s = 0;
	d[s] = 0;

	for (int i = 1; i <= V - 1; i++) {
        for (int v = 0; v < V; v++) {
            vector<Edge> out_edges = graph[v];
            for (Edge e : out_edges) {
                if (d[e.v] < INF && d[e.v] > d[e.u] + e.w) {
					d[e.v] = d[e.u] + e.w;
					p[e.v] = e.u;
				}
			}
        }
    }

    for (int i = 1; i <= V - 1; i++) {
        for (int v = 0; v < V; v++) {
            vector<Edge> out_edges = graph[v];
            for (Edge e : out_edges) {
                if (d[e.v] > d[e.u] + e.w) {
                    cout << "NO Solution\n";
                    return 0;
                }
            }
		}
    }

	cout << "Sp\n";
	for (int v = 0; v < V; v++) {
		cout << v << " : d= " << d[v] << " , p = " << p[v] << endl;
	}
}
