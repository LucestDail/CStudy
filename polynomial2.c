#include<stdio.h>
#include<stdlib.h>

#define MAX_TERMS 101

struct {
	float coef;
	int expon;
} terms[MAX_TERMS] = {
	{8,3},
	{7,1},
	{1,0},//8x^3 + 7x^1 + 1
	{10,3},
	{3,2},
	{1,0}//10x^3  3x^2 + 1
};

int avail = 6;
// terms structure 끝나는 지점.(0,1,2,3,4,5 까지 사용하여 6 지점 부터 사용 가능 명시) 
char compare(int a, int b) {
	//비교 후 큰쪽으로 > || < 반환, 같으면 = 반환
	if (a > b)
		return '>';
	else if (a == b)
		return '=';
	else return '<';
}

//terms 배열 빈공간으로 이동
void attach(float coef, int expon) {
	// 파라매터 coef, expon 통하여비교 연산(while, swith) 결과 아규먼트 입력
	if (avail>MAX_TERMS) {
		// avail 값이 MAX_TERMS 보다 많은 경우 강제 브레이크, 4번째 줄 define 코드 참조!
		fprintf(stderr, "혀엉...");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail++].expon = expon;
	//terms avail 에 coef expon 값 추가 이후 avail 값 1 증가
}

void poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce) {
	float tempcoef;
	//임시 버퍼 선언(6 변수 선언 지점의포인터를 가져오는겁니다!)
	*Cs = avail; 
	printf("%d\n", *Cs);
	//작성 가능 구조체 terms 지점 포인터 선언
	while (As <= Ae && Bs <= Be) { // A,B 둘다 시작값보다 끝값이 작을때 루프 탈출
		switch (compare(terms[As].expon, terms[Bs].expon))// 비교연산 스위치
		{
		case '>':// A 차수값이클경우 (A 항만 값이 있는 경우) A 계수 추가
			attach(terms[As].coef, terms[As].expon);
			As++;
			break;
		case '=':// A, B 차수 같으면 coef 더한 후, +- 0이 아니면 지수에 계수 추가
			tempcoef = terms[As].coef + terms[Bs].coef;
			if (tempcoef)
				attach(tempcoef, terms[As].expon);
			As++;
			Bs++;
			break;
		case '<':// B 차수값이클경우(B 항만 값이 있는 경우) B 계수 추가
			attach(terms[Bs].coef, terms[Bs].expon);
			Bs++;
			break;
		default://이외 상황 break
			break;
		}
	}
	//루프 탈출 후, A/B term 빈 공간으로 이동.
	for (; As <= Ae; As++)
		attach(terms[As].coef, terms[As].expon);
	for (; Bs <= Be; Bs++)
		attach(terms[Bs].coef, terms[Bs].expon);
	*Ce = avail - 1;
	int i = 0;
	for (i=0;i<avail;i++){
		printf("(%g, %d)\n",terms[i].coef, terms[i].expon);
	}
}

int main() {
	int Cs, Ce;
	poly_add2(0, 2, 3, 5, &Cs, &Ce);
	//0 ~ 2 까지의 다항식, 3~ 5까지의 다항식을 더하여 Cs, Ce 로 반환할 겁니당.
	return 0;
}