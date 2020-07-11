#include<stdio.h>

void main() {
	int a = 3;
	int n = 10;
	power(a, n);
}


int power(int a, int n) {
	printf("계산 대상 : %d ^ %d", a, n);
	int i = 0;
	int temp = 1;
	for (i = 0; i < n; i++) {
		temp *= a;
		printf("현재 temp 값 : %d\n", temp);
	}
	printf("최종 결과 - %d ^ %d = %d", a, n, temp);
}