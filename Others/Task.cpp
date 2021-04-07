#include<bits/stdc++.h>
using namespace std;

struct Task {
	int start, finish;
};

bool comparison(Task t1, Task t2) {
	return t1.finish < t2.finish;
}

vector<Task> GREEDY_ACTIVITY_SELECTOR(Task arr[], int n) {
    int i = 0;
	vector<Task> A;
	A.push_back(arr[0]);
	for (int m = 1; m < n; m++) {
		if (arr[m].start >= arr[i].finish) {
			A.push_back(arr[m]);
			i = m;
		}
	}
	return A;
}

int main() {
	Task arr[] = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}};
	int n = sizeof(arr) / sizeof(arr[0]);

	sort(arr, arr + n, comparison);

	vector<Task> A = GREEDY_ACTIVITY_SELECTOR(arr, n);

	cout << A.size() << endl;
    
	// for (auto x : A) {
	// 	cout << x.start << " " << x.finish << endl;
	// }
}