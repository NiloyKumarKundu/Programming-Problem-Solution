#include <bits/stdc++.h>
using namespace std;

int partition(int A[], int low, int high) {
    int i = low + 1;
    int j = high;
    int temp;

    while(1) {
        while((i <= high) && (A[i] < A[low])) {
            i++;
        }
        while((j >= (low + 1)) && (A[j] >= A[low])) {
            j--;
        }
        if(i < j)
            swap(A[i], A[j]);
        else
            break;
    }

    swap(A[low], A[j]);
    return j;
}

// void quickSort(int A[], int low, int high) {
//     if(low < high) {
//         int p = partition(A, low, high);
//         quickSort(A, low, p - 1);
//         quickSort(A, p + 1, high);
//     }
// }

int kth_largest(int K[], int low, int high, int k) {
	int q = partition(K, low, high);

	if (q == k) {
		return K[k];
	} else if (q > k) {
		return kth_largest(K, low, q - 1, k);
	}
	else {
		return kth_largest(K, q + 1, high, k);
	}
	return -1;
}

int main() {
	int i, n;
	printf("\n Input the size");
	scanf("%d", &n);
	int A[n];
	printf("\n Input the elements");
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	// quickSort(A, 0, n);
	printf("\n after sorting the element is:\n");
	for (i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");

	int pos = 3;
	int y = kth_largest(A, 0, n, pos);
	printf("The largest element is %d.\n", y);

	return 0;
}

/*
    1 4 6 7 10 19 22 23 30 35 39 46 49 50 52 55 61 67 70 71
*/
