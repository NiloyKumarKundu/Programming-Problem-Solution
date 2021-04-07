#include<bits/stdc++.h>
using namespace std;
#define NEG_INF -999999
#define int int64_t
#define fastInput ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);


int32_t main() {
	fastInput;
	int n;
	int t;
	cin >> t;
	int cases = 1;
	for (int i = 0; i < t; i++) {
		cin >> n;
        int arr[n];
        int firstPlus = 0, lastPlus = n;

        bool firstFlag = true;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] < 0 && firstFlag) {
                firstPlus++;
            } else {
                firstFlag = false;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] <= 0) {
                lastPlus--;
            } else {
                break;
            }
        }

        int moves = 0, sum = 0;
        // cout << firstPlus << " " << lastPlus << endl;
        for (int i = firstPlus; i < lastPlus; i++) {
            if (arr[i] < 0) {
                int j = i + 1;
                moves++;
                while (arr[j] < 0) {
                    j++;
                }
                i = j - 1;
            } else {
                sum += arr[i];
                // cout << arr[i] << endl;
            }
        }

		// cout << cases << "Last: " << lastPlus << endl;
		if (lastPlus == 0) {
			sort(arr, arr + n);
            cout << "Case " << cases++ << ": " << arr[n - 1] << " " << 0 << endl;
		} else {
			cout << "Case " << cases++ << ": " << sum << " " << moves << endl;
		}
		// cout << sum << " " << moves << endl;
	}

	// Result ans = find_Max_Subarray(arr, 0, n - 1);
	// cout << "[" << ans.li << " : " << ans.ri << "] = " << ans.sum << endl;
}