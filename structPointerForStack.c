#include<stdio.h>

#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef int element;

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;

void init(StackType *s) {
	s->top = -1;
}
//스택 공백 판단
int is_empty(StackType *s) {
	return (s->top == -1);
}
//스택 포화 판단
int is_full(StackType *s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}
//삽입 함수
void push(StackType *s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화상태");
		return;
	}
	else {
		s->stack[++(s->top)] = item;
	}
}
//출력 - 삭제 함수
element pop(StackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백상태");
		exit(1);
	}
	else {
		return s->stack[(s->top)--];
	}
}
//피크 함수
element peek(StackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백상태");
		exit(1);
	}
	else {
		return s->stack[(s->top)];
	}
}
int main() {
	StackType s;
	init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", peek(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", peek(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", peek(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", is_empty(&s));
	return 0;
}

