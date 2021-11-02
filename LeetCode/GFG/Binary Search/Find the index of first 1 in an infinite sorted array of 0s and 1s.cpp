#include <bits/stdc++.h>
using namespace std;

int main() {
    int size;
    cin >> size;
    int arr[size];
    for (int i =0 ; i < size; i++) {
        cin >> arr[i];
    }
    
	int low = 0, high = 1;
	int key = 1;
	
	while (key > arr[high]) {
	    low = high;
	    high *= 2;
	}
	int res = -1;
	while (low <= high) {
	    int mid = low + (high - low) / 2;
	    if (key == arr[mid]) {
	        res = mid;
			high = mid - 1;
		} else if (key > arr[mid]) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	
	cout << res << endl;
	
	return 0;
}