#include <stdio.h>
#include <stdarg.h>

void applyTax(double price) {
	double tax = price * 0.07;
	double taxApplied = price + tax;

	printf("After Tax: %.2f\n", taxApplied);
}

void applyDiscount(double *price, double discount) {
	double discountTaken = *price * (discount / 100);
	*price = *price - discountTaken;
}

double calculateTotal(int count, ...) {
	va_list arguments;

	va_start(arguments, count);

	double total = 0.00;

	va_start(arguments, count);

	for (int i = 0; i < count; i++) {
		double current = va_arg(arguments, double);
		total += current;
	}

	va_end(arguments);

	return total;
}

int main (void) {
	double price = 100.00;
	printf("Before Tax: $%.2f\n", price);
	applyTax(price);
	printf("Price didn't change in main funciton: $%.2f\n", price);

	applyDiscount(&price, 20);

	printf("After 20 percent discount: $%.2f\n", price);

	double total = calculateTotal(3, 40.35, 3.23, 32.1);

	printf("Total from $40.35, $3.23, $32.1: $%.2f\n", total);
}
