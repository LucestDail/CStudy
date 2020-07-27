#include <stdio.h>

int main() {
	int a = 0;
	int b = 10;
	int * ap = NULL;
	int * bp = NULL;
	ap = &a;
	bp = &b;
	printf("%d : %d\n",a, ap);
	printf("%d : %d\n", b, bp);
	bp = &a;
	*bp = 100;
	printf("%d : %d\n", a, ap);
	printf("%d : %d\n", b, bp);

	return 0;
}