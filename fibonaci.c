#include<stdio.h>
void main() {

	int n = 3;
	hanoi(n, 'A','B','C');
}

int hanoi(int n, char from, char temp, char to) {
	int count = 0;
	if (n == 1) {
		printf("%c -> %c : %d \n", from, to);
		count++;
	}else{
		hanoi(n - 1, from, to, temp);
		printf("%c -> %c : %d \n", n, from, to);
		count++;
		hanoi(n - 1, temp, from, to);
	}
	printf("ÃÑ ÀÌµ¿ È½¼ö : %d", count);
}