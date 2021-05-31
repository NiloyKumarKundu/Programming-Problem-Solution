#include <bits/stdc++.h>
using namespace std;
#define N_VERTICES 5
#define INF		   99999
#define NULL	   __null

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

	void add_edge(int u, int v, int weight) {
		mat[u][v] = weight;
		// mat[v][u] = weight;
	}
    void print_shortest_path_tree(int p[], int d[]) {
        // just print i and p[i]
		for (int i = 0; i < N_VERTICES; i++) {
			cout << i << "---->" << p[i] << endl;
		}
		cout << endl;
		cout << endl;
		for (int i = 0; i < N_VERTICES; i++) {
			cout << i << "---->" << d[i] << endl;
		}
		cout << endl;
	}

	void relax(int u, int v, int d[], int p[]) {
		if (d[v] > d[u] + mat[u][v]) {
			d[v] = d[u] + mat[u][v];
			p[v] = u;
			cout << "d[v] = " << d[v] << " " << v << endl;
		}
	}

	void Bellmanford(int source) {
		int d[N_VERTICES], p[N_VERTICES];
		for (int i = 0; i < N_VERTICES; i++) {
			d[i] = INF;
			p[i] = -1;
		}
		d[source] = 0;

		for (int i = 0; i < N_VERTICES - 1; i++) {
			for (int j = 0; j < N_VERTICES; j++) {
				if (mat[i][j] != 0) {
                    relax(i, j, d, p);
				}
			}
		}
        print_shortest_path_tree(p, d);

        for (int i = 0; i < N_VERTICES; i++) {
			for (int j = 0; j < N_VERTICES; j++) {
				if (mat[i][j]) {
                    if (d[j] > d[i] + mat[i][j]) {
                        cout << "NO route\n";
                        cout << "d[v] = " << d[j] << " " << j << endl;
						cout << d[i] + mat[i][j] << endl;
						return;
					}
                }
			}
		}

		print_shortest_path_tree(p, d);
	}
};

int main() {
	Graph G;
	G.init_graph();
	G.add_edge(0, 1, 10);
	G.add_edge(0, 3, 5);
	G.add_edge(1, 2, 1);
	G.add_edge(1, 3, 2);
	G.add_edge(2, 4, 4);
	G.add_edge(3, 1, 3);
	G.add_edge(3, 2, 9);
	G.add_edge(3, 4, 2);
	G.add_edge(4, 2, 6);
	G.add_edge(4, 0, 7);

	for (int i = 0; i < N_VERTICES; i++) {
		for (int j = 0; j < N_VERTICES; j++) {
			cout << G.mat[i][j] << " ";
		}
		cout << endl;
	}

	G.Bellmanford(0);
}