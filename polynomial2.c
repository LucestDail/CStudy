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
// terms structure ������ ����.(0,1,2,3,4,5 ���� ����Ͽ� 6 ���� ���� ��� ���� ���) 
char compare(int a, int b) {
	//�� �� ū������ > || < ��ȯ, ������ = ��ȯ
	if (a > b)
		return '>';
	else if (a == b)
		return '=';
	else return '<';
}

//terms �迭 ��������� �̵�
void attach(float coef, int expon) {
	// �Ķ���� coef, expon ���Ͽ��� ����(while, swith) ��� �ƱԸ�Ʈ �Է�
	if (avail>MAX_TERMS) {
		// avail ���� MAX_TERMS ���� ���� ��� ���� �극��ũ, 4��° �� define �ڵ� ����!
		fprintf(stderr, "����...");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail++].expon = expon;
	//terms avail �� coef expon �� �߰� ���� avail �� 1 ����
}

void poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce) {
	float tempcoef;
	//�ӽ� ���� ����(6 ���� ���� �����������͸� �������°̴ϴ�!)
	*Cs = avail; 
	printf("%d\n", *Cs);
	//�ۼ� ���� ����ü terms ���� ������ ����
	while (As <= Ae && Bs <= Be) { // A,B �Ѵ� ���۰����� ������ ������ ���� Ż��
		switch (compare(terms[As].expon, terms[Bs].expon))// �񱳿��� ����ġ
		{
		case '>':// A ��������Ŭ��� (A �׸� ���� �ִ� ���) A ��� �߰�
			attach(terms[As].coef, terms[As].expon);
			As++;
			break;
		case '=':// A, B ���� ������ coef ���� ��, +- 0�� �ƴϸ� ������ ��� �߰�
			tempcoef = terms[As].coef + terms[Bs].coef;
			if (tempcoef)
				attach(tempcoef, terms[As].expon);
			As++;
			Bs++;
			break;
		case '<':// B ��������Ŭ���(B �׸� ���� �ִ� ���) B ��� �߰�
			attach(terms[Bs].coef, terms[Bs].expon);
			Bs++;
			break;
		default://�̿� ��Ȳ break
			break;
		}
	}
	//���� Ż�� ��, A/B term �� �������� �̵�.
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
	//0 ~ 2 ������ ���׽�, 3~ 5������ ���׽��� ���Ͽ� Cs, Ce �� ��ȯ�� �̴ϴ�.
	return 0;
}