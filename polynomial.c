#include<stdio.h>
#define MAX(a,b) (((a)>(b)) ? a : b)
#define MAX_DEGREE 101

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
} polynomial;

polynomial poly_add1(polynomial A, polynomial B) {
	polynomial C;
	int Apos = 0;
	int Bpos = 0;
	int Cpos = 0;
	int i = 0;
	int degree_a = A.degree; //degree_a = 5
	int degree_b = B.degree; //degree_b = 4
	C.degree = MAX(A.degree, B.degree); //C,degree = 5

	while (Apos <= A.degree && Bpos <= B.degree) {
		/*
		* while 루프, 0 <= 5 ... 0 && 0 <= 4 ... 0 -> break
		* a 차수가 클 경우 c 차수 = a 차수
		* a 항 감소
		*
		* b 차수가 클 경우 c 차수 = b 차수
		* b 항 감소
		*
		* a=b 일 경우 c 차수 = a+b
		* a, b 항 감소
		*
		*/
		if (degree_a > degree_b) {
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--;
			degree_b--;
		}
		else {
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	printf("%d\n", C.degree);
	for (i = 0; i <= C.degree; i++) {
		printf("%f ", C.coef[i]);
	}
	return C; // polynomial structure 반혼
}

int main() {
	polynomial a = {
		5,{
		3, 6, 0, 0, 0, 10
	}
	};
	polynomial b = {
		4,{
		7, 0, 5, 0, 1
	}
	};
	polynomial c;
	c = poly_add1(a, b);
	return 0;
}