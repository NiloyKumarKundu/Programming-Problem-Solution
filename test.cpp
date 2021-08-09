#include <iostream>
using namespace std;

void merge_sorted_halfs(int arr[], int startind, int midind, int endind) {
	///copying the left half to leftarr
	int leftarrsz = (midind - startind + 1);
	int leftarr[100];
	for (int ind = 0; ind < leftarrsz; ind++) {
		leftarr[ind] = arr[startind + ind];
	}

	///copying the right half to rightarr
	int rightarrsz = (endind - (midind + 1) + 1);
	int rightarr[100];
	for (int ind = 0; ind < rightarrsz; ind++) {
		rightarr[ind] = arr[midind + 1 + ind];	 ///midind+1, midind+1+1, ... ..., endind
	}

	///merging the left and right halves and placing into the main array, arr
	int leftind = 0;
	int rightind = 0;
	for (int ind = startind; ind <= endind; ind++) {
		if (leftind == leftarrsz) {
			///when all the left array elements are already copied

			///we only need to copy the right array elements
			arr[ind] = rightarr[rightind];
			rightind++;
		} else if (rightind == rightarrsz) {
			///when all the right array elements are already copied

			///we only need to copy the left array elements
			arr[ind] = leftarr[leftind];
			leftind++;
		} else if (leftarr[leftind] >= rightarr[rightind]) {
			arr[ind] = leftarr[leftind];
			leftind++;
		} else {
			arr[ind] = rightarr[rightind];
			rightind++;
		}
	}
}

void merge_sort(int arr[], int startind, int endind) {
	///startind > endind: array is empty. This case won't happen

	if (startind == endind) {
		///only 1 elements in the array
		return;
	} else if (startind < endind) {
		///array contains more than 1 elements

		int midind = (startind + endind) / 2;

		merge_sort(arr, startind, midind);
		merge_sort(arr, midind + 1, endind);

		merge_sorted_halfs(arr, startind, midind, endind);
	}
}

int gen_random(int s, int e){
    srand(time(NULL));

    int random_number=s+   rand()%(e-s+1);
    return random_number;
}

int bin_search(int arr[], int startind, int endind, int searchval) {
	if (startind > endind) {
		return -1;
	} else {
		int midind=gen_random(startind,endind);

		if (arr[midind] == searchval) {
			return midind;
		} else if (searchval > arr[midind]) {
			int friendresult = bin_search(arr, startind, midind - 1, searchval);

			return friendresult;
		} else {
			int friendresult = bin_search(arr, midind + 1, endind, searchval);

			return friendresult;
		}
	}
}

int main() {
	int arr[] = {14, 7, 3, 12, 9, 11, 6, 2};
	int sz = sizeof(arr) / sizeof(int);

	merge_sort(arr, 0, sz - 1);

	for (int ind = 0; ind < sz; ind++)
		cout << arr[ind] << " ";
	cout << endl;

	int res = bin_search(arr, 0, sz - 1, 8);
	cout << res << endl;

	return 0;
}