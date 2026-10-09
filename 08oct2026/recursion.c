#include <stdio.h>

typedef int (*op_fn)(int, int);

int power(int base, int exp) {
	//int answer = base;
	if (exp <= 0) return 1;
	return base * power(base, exp - 1);
}

void print_range(int n) {
	if (n <= 1) {
		printf("%d", n);
		return;
	}
	print_range(n-1);
	printf("%d", n);
	// Fix this shit lol
}

int add(int a, int b) {return a + b;}
int multiply(int a, int b) {return a * b;}

int apply(int a, int b, op_fn op) {
	return op(a, b);
}

int main(void) {
	int choice;
	int number1;
	int number2;

	print_range(5);
	printf("\n");
	printf("%d", power(2, 5));
	printf("\n");

	printf("Choose an operation:\n\n1. Add\n2. Multiply\n\nChoice: ");
	scanf("%d", &choice);

	printf("Enter first number: ");
	scanf("%d", &number1);

	printf("Enter second number: ");
	scanf("%d", &number2);

	if (choice == 1) {
		printf("%d\n", apply(number1, number2, add));
	} else if (choice == 2) {
		printf("%d\n", apply(number1, number2, multiply));
	} else {
		printf("Invalid operation was choosen");
	}
}
