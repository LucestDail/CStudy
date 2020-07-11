#include<stdio.h>
int main() {
	int n = 10;
	fac_recursion(n);
	printf("fac_recursion : %d", fac_recursion(n));
	return 0;
}

int fac_recursion(int n) {
	if (n == 1)
		return 1;
	else
		return n * fac_recursion(n - 1);
}
