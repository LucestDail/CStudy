#include<stdio.h>
#include<stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct {
	int student_no;
	char name[MAX_STRING];
	char address[MAX_STRING];
}element;
element stack[MAX_STACK_SIZE];
int top = -1;
//���� ���� �Ǵ�
int is_empty() {
	return (top == -1);
}
//���� ��ȭ �Ǵ�
int is_full() {
	return (top == (MAX_STACK_SIZE - 1));
}
//���� �Լ�
void push(element item) {
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ����");
		return;
	}
	else {
		stack[++top] = item;
	}
}
//��� - ���� �Լ�
element pop() {
	if (is_empty()) {
		fprintf(stderr, "���� �������");
		exit(1);
	}
	else {
		return stack[top--];
	}
}
//��ũ �Լ�
element peek() {
	if (is_empty()) {
		fprintf(stderr, "���� �������");
		exit(1);
	}
	else {
		return stack[top];
	}
}
int main() {
	element ie, oe;
	strcpy(ie.name, "OhSeungHyun");
	strcpy(ie.address, "Incheon");
	ie.student_no = 201411139;
	push(ie);
	oe = pop();
	printf("name : %s\n", oe.name);
	printf("address : %s\n", oe.address);
	printf("student number : %s\n", oe.student_no);
	return 0;
}

