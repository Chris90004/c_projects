/*
 * main.c
 * main
 * Christian Evensen
 */

#include <stdio.h>
#include "picture.h"

int main(void) {
	int pic[][COLS] = {
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 0},
		{1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1}
	};

	int nrows = sizeof(pic) / sizeof(pic[0]);

	printf("Original picture:\n");
	print_picture(pic, nrows);

	printf("\nSearching for code 1:\n");
	printf("find 1 -> %d\n", find_code(pic, nrows, 1));

	printf("\nSearching for code 9:\n");
	printf("find 9 -> %d\n", find_code(pic, nrows, 9));

	printf("\nAfter set_cell(2, 2, 1):\n");
	set_cell(pic, nrows, 2, 2, 1);
	print_picture(pic, nrows);

	printf("\nAttempting invalid set_cell(9, 0, 1):\n");
	set_cell(pic, nrows, 9, 0, 1);
	printf("Invalid write ignored. Picture remains:\n");
	print_picture(pic, nrows);

	printf("\nTesting null pointer:\n");
	print_picture(nullptr, 4);
	printf("Null pointer handled safely.\n");

	return 0;
}
