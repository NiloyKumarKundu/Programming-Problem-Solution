#include <bits/stdc++.h>
using namespace std;

int main() {
	int l, k;
	cin >> l >> k;
	int arr[k];
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
	}
	int count = 0;
	bool flag = false;
    

	for (int i = 0; i < k; i++) {
		int j;
		for (j = i + 1; j < k; j++) {
            if (arr[j] - arr[i] > l && i == j - 1) {
				flag = true;
				break;
			}
			if (arr[j] - arr[i] > l) {
				break;
			}
		}
		--j;
		i = j++;
		// cout << i << endl;
		count++;
	}
    if (flag) {
		cout << -1 << endl;
	} else 
	    cout << count + 1 << endl;
}