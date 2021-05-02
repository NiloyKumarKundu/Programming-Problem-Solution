#include <stdio.h>

int main() {
	int arr[100], choise;
	printf("Enter the number of items: ");
	scanf("%d", &choise);

	int ans = 0;
	for (int i = 1; i <= choise; i++) {
		printf("Item-%d:\n", i);
		int quantity, rate;
		printf("Quantity = ");
		scanf("%d", &quantity);
		printf("Rate (in TK) = ");
		scanf("%d", &rate);
		ans += (quantity * rate);
	}
	printf("Your Total Bill is %d Tk\n", ans);
}