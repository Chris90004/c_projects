#include "cafe.h"
#include <stdio.h>

int main(void) {
	int price = 400;

	printf("startingprice: %d cents\n", price);

	preview_discount(price, 10);

	printf("price after preview: %d cents\n", price);

	apply_discount(&price, 10);

	printf("after apply_discount: %d cents\n", price);

	int balance = 1000;
	int new_balance = 0;

	int charge_result = charge(balance, price, &new_balance);

	if (charge_result == CAFE_OK) {
		printf("charge ok: balance %d - %d -> %d\n", balance, price, new_balance);
	} else {
		printf("charge fail: code %d\n", charge_result);
	}

	int failed_balance = 0;

	charge_result = charge(100, 360, &failed_balance);

	printf("charge fail: code %d\n", charge_result);

	int change = 0;

	if (make_change(500, 360, &change)) {
		printf("change for 500 on 360: %d cents\n", change);
	} else {
		printf("make_change failed\n");
	}

	if (make_change(300, 360, &change)) {
		printf("change: %d cents\n", change);
	} else {
		printf("make_change failed as expected\n");
	}

	int prices[] = {360, 250, 450, 300};

	int min_price = 0;
	int max_price = 0;

	if (price_span(prices, 4, &min_price, &max_price)) {
		printf("price span: min=%d max=%d\n", min_price, max_price);
	}

	if( !price_span(prices, 0, &min_price, &max_price)) {
		printf("price span failed as expected\n");
	}

	print_line_item("latte", price);

	return 0;
}
