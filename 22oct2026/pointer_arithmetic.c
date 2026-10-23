#include <stdio.h>

int sum_array(int *arr, int size) {
	int total = 0;
	int temp = 0;
	for (int *p = arr; p < arr + size; p++) {
		temp = *p;
		total += temp;
	}
	return total;
}

int find_max(int *arr, int size) {
	int max = *arr;
	for (int *p = arr; p < arr + size; p++) {
		if (*p > max) max = *p;
	}
	return max;
}

int main(void) {
	int arr[] = {10, 25, 5, 40, 15};
	int n = 5;

	int *p = arr;

	for (int *p = arr; p < arr + n; p++) {
		// Print value and memory address
		printf("Value: %d | Address: %p\n", *p, p + 1);
	}

	printf("Array: 10 25 5 40 15\n");
	printf("Maximum value: %d\n", find_max(arr, n));


	printf("\nIndex | arr[i] | *(arr + i)");
	printf("\n----------------------------\n");
	for (int i = 0; i < n; i++) {
		printf("i | %d | %d\n", i, arr[i], *(arr + i));
	}

	printf("\nTotal: %d\n", sum_array(arr, n));
}
