/*
 * picture.c
 * print_picture, find_code, set_cell
 * Christian Evensen
 */

#include <stdio.h>
#include "picture.h"

void print_picture(const int pic[][COLS], int nrows) {
	if (pic == nullptr || nrows <= 0) {
		return;
	}

	for (int r = 0; r < nrows; r++) {
		for (int c = 0; c < COLS; c++) {
			if (pic[r][c] == 0) {
				putchar('.');
			}
			else if (pic[r][c] == 1) {
				putchar('#');
			}
			else {
				putchar('?');
			}
		}

		putchar('\n');
	}
}

int find_code(const int pic[][COLS], int nrows, int target) {
	if (pic == nullptr || nrows <= 0) {
		return -1;
	}

	for (int r = 0; r < nrows; r++) {
		for (int c = 0; c < COLS; c++) {
			if (pic[r][c] == target) {
				return r * COLS + c;
			}
		}
	}

	return -1;
}

void set_cell(int pic[][COLS], int nrows, int row, int col, int value) {
	if (pic == nullptr || nrows <= 0) {
		return;
	}

	if (row < 0 || row >= nrows || col < 0 || col >= COLS) {
		return;
	}

	pic[row][col] = value;
}
