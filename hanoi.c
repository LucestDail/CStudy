#include<stdio.h>
int count = 0;

void main() {

	int n = 4;
	hanoi(n, 'A', 'B', 'C');
	printf("이동 횟수 : %d\n", count);
}

int hanoi(int n, char from, char temp, char to) {
	count++;
	if (n == 1) {
		printf("%d 이동 (%c -> %c) \n", n, from, to);
	}
	else {
		hanoi(n - 1, from, to, temp);
		printf("%d 이동 (%c -> %c) \n", n, from, to);
		hanoi(n - 1, temp, from, to);
	}
}