#include <bits/stdc++.h>
using namespace std;
#define N_VERTICES 10

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
		// p[b] = a; // use any one
	}

    bool same_set(int x, int y) {
        if (find_set(x) == find_set(y)) {
			return true;
		}
		return false;
	}
};

int main() {
	DisjointSet ds;
	for (int i = 0; i < N_VERTICES; i++) {
		ds.make_set(i);
	}

	// int a = 0, b = 5;
	// if (ds.same_set(a, b)) {
	// 	cout << a << " & " << b << " are in the same set\n";
	// } else {
	// 	cout << a << " & " << b << " are in different set\n";
	// }
	// a = 4, 5;
	// if (ds.same_set(a, b)) {
	// 	cout << a << " & " << b << " are in the same set\n";
	// } else {
	// 	cout << a << " & " << b << " are in different set\n";
	// }
	// cout << endl;

	// a = 0, b = 5;
	// ds.union_set(a, b);
	// a = 4, b = 5;
	// ds.union_set(a, b);

    // a = 0, b = 5;
	// if (ds.same_set(a, b)) {
	// 	cout << a << " & " << b << " are in the same set\n";
	// } else {
	// 	cout << a << " & " << b << " are in different set\n";
	// }

	// a = 4, 5;
	// if (ds.same_set(a, b)) {
	// 	cout << a << " & " << b << " are in the same set\n";
	// } else {
	// 	cout << a << " & " << b << " are in different set\n";
	// }

    // a = 0, 5;
	// if (ds.same_set(a, b)) {
	// 	cout << a << " & " << b << " are in the same set\n";
	// } else {
	// 	cout << a << " & " << b << " are in different set\n";
	// }

	ds.union_set(0, 5);
	ds.union_set(1, 0);
	ds.union_set(3, 7);
	ds.union_set(7, 2);
	int a = 1, b = 2;
	if (ds.same_set(a, b)) {
		cout << a << " & " << b << " are in the same set\n";
	} else {
		cout << a << " & " << b << " are in different set\n";
	}
	ds.union_set(7, 0);
	a = 1, b = 2;
    if (ds.same_set(a, b)) {
		cout << a << " & " << b << " are in the same set\n";
	} else {
		cout << a << " & " << b << " are in different set\n";
	}
}