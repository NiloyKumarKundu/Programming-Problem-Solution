#include <bits/stdc++.h>
using namespace std;


int findPeakElement(int arr[], int size) {
	int low = 0, high = size - 1;

    while (low <= high) {
		int mid = low + (high - low) / 2;

		if ((mid > 0) && (mid < size - 1)) {
			if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
				return mid;
			} else if (arr[mid - 1] > arr[mid]) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		} else if (mid == 0) {
			if (arr[mid] > arr[mid + 1]) {
				return 0;
			} else {
				return 1;
			}
		} else if (mid == size - 1) {
			if (arr[size - 1] > arr[size - 2]) {
				return size - 1;
			} else {
				return size - 2;
			}
		}
	}
	return -1;
}

int BS(int arr[], int size, int low, int high, int target) {
    while (low <= high) {
		int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
			return mid;
		} else if (target < arr[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return -1;
}


int BSforDesc(int arr[], int size, int low, int high, int target) {
    while (low <= high) {
		int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
			return mid;
		} else if (target < arr[mid]) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return -1;
}




int main() {
	int size;
	cin >> size;
	int arr[size];
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	int target;
	cin >> target;

	if (size == 1) {
		return 0;
	}

	int index = findPeakElement(arr, size);
	int ans1 = BS(arr, size, 0, index - 1, target);
	int ans2 = BSforDesc(arr, size, index, size - 1, target);

	if (ans1 != -1) {
		cout << ans1 << endl;
	} else if (ans2 != -1) {
		cout << ans2 << endl;
	} else {
		cout << -1 << endl;
	}

	return 0;
}