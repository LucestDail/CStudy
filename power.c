#include<stdio.h>

void main() {
	int a = 3;
	int n = 10;
	power(a, n);
}


int power(int a, int n) {
	printf("��� ��� : %d ^ %d", a, n);
	int i = 0;
	int temp = 1;
	for (i = 0; i < n; i++) {
		temp *= a;
		printf("���� temp �� : %d\n", temp);
	}
	printf("���� ��� - %d ^ %d = %d", a, n, temp);
}