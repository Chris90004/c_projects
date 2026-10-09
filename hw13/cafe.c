#include "cafe.h"

#include <stdio.h>

void preview_discount(int price_cents, int percent_off) {
	int discounted_price = price_cents - (price_cents * percent_off) / 100;

	printf("preview %d cents @%d%%: shows %d (caller still %d)\n", price_cents, percent_off, discounted_price, price_cents);
}

void apply_discount(int *price_cents, int percent_off) {
	if (price_cents == NULL) {
		return;
	}

	if (percent_off < 0 || percent_off > 100) {
		return;
	}

	*price_cents = *price_cents - (*price_cents * percent_off) / 100;
}

int charge(int balance_cents, int cost_cents, int *new_balance) {
	if (new_balance == NULL) {
		return CAFE_ERR_NULL;
	}

	if (balance_cents < 0 || cost_cents < 0) {
		return CAFE_ERR_BAD_AMOUNT;
	}

	if (cost_cents > balance_cents) {
		return CAFE_ERR_INSUFFICIENT;
	}

	*new_balance = balance_cents - cost_cents;

	return CAFE_OK;
}

bool make_change(int paid_cents, int cost_cents, int *change_out) {
	if (change_out == NULL) {
		return false;
	}

	if (paid_cents < 0 || cost_cents < 0) {
		return false;
	}

	if (paid_cents < cost_cents) {
		return false;
	}

	*change_out = paid_cents - cost_cents;

	return true;
}

bool price_span(const int prices[], int n, int *min_out, int *max_out) {
	if (n <= 0 || prices == NULL || min_out == NULL || max_out == NULL) {
		return false;
	}

	int min = prices[0];
	int max = prices[0];

	for (int i = 1; i < n; i++) {
		if (prices[i] < min) {
			min = prices[i];
		}

		if (prices[i] > max) {
			max = prices[i];
		}
	}

	*min_out = min;
	*max_out = max;

	return true;
}

void print_line_item(const char *name, int price_cents) {
	printf("%s: %d cents\n", name, price_cents);
}
