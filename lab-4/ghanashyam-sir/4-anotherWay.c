#include<stdio.h>


int product(int x, int y) {
	if (x == 1)
		return y;

	if (y == 1)
		return x;

	else
		return x + product(x, y-1);
}


int main() {
	printf("Product: %d", product(5, 4));

	return 0;
}
