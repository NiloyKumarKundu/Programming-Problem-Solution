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
	int key;
	cin >> key;
	
	while (key > arr[high]) {
	    low = high;
	    high *= 2;
	}
	
	while (low <= high) {
	    int mid = low + (high - low) / 2;
	    if (key == arr[mid]) {
	        cout << mid << endl;
			return 0;
		} else if (key > arr[mid]) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	
	cout << -1 << endl;
	
	return 0;
}