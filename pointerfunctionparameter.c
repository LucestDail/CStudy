#include <stdio.h>

void swap(int *xp, int *yp) {
	int temp;
	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int main() {
	int a = 1;
	int b = 2;
	printf("before swap : a - %d / b - %d", a, b);
	swap(&a, &b);
	printf("after swap : a - %d / b - %d", a, b);
	return 0;
}