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
//스택 공백 판단
int is_empty() {
	return (top == -1);
}
//스택 포화 판단
int is_full() {
	return (top == (MAX_STACK_SIZE - 1));
}
//삽입 함수
void push(element item) {
	if (is_full()) {
		fprintf(stderr, "스택 포화상태");
		return;
	}
	else {
		stack[++top] = item;
	}
}
//출력 - 삭제 함수
element pop() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백상태");
		exit(1);
	}
	else {
		return stack[top--];
	}
}
//피크 함수
element peek() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백상태");
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

