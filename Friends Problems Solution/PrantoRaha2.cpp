#include <stdio.h>

int main() {
	int amount, price, totalAmount = 0, totalPrice = 0;
	while (true) {
		printf("Enter amount (in kg): ");
		scanf("%d", &amount);
        if (amount == 0) {
			break;
		} else if (amount < 0) {
			printf("Invalid input, enter a positive number\n");
			continue;
		} else {
			totalAmount += amount;
		}
		printf("Enter Price: ");
		scanf("%d", &price);
        if (price < 0) {
			printf("Invalid input, enter a positive number\n");
			totalAmount -= amount;
			continue;
		} else {
			totalPrice += price;
		}
	}
	double avgPrice = ((totalPrice * 1.0) / totalAmount);
	printf("Total amount (in kg): %d, Total Price: %d, Average price per kg: %.2lf\n", totalAmount, totalPrice, avgPrice);
}