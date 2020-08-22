#include<stdio.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;

void init(StackType* s) {
	s->top = -1;
}

//스택 공백 판단
int is_empty(StackType* s) {
	return (s->top == -1);
}
//스택 포화 판단
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}
//삽입 함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화상태");
		return;
	}
	else {
		s->stack[++(s->top)] = item;
	}
}
//출력 - 삭제 함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백상태");
		exit(1);
	}
	else {
		return s->stack[(s->top)--];
	}
}
//피크 함수
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백상태");
		exit(1);
	}
	else {
		return s->stack[s->top];
	}
}

int eval(char exp[]) {
	int op1, op2, value;
	int i = 0;
	int len = strlen(exp);
	char ch;
	StackType s;
	init(&s);
	for (i = 0; i < len; i++) {
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			value = ch - '0';
			push(&s, value);
		}
		else {
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch) {
			case '+':
				push(&s, op1 + op2);
				break;
			case '-':
				push(&s, op1 - op2);
				break;
			case '*':
				push(&s, op1 * op2);
				break;
			case '/':
				push(&s, op1 / op2);
				break;
			}
		}
	}
	return pop(&s);
}

int main() {
	int result;
	printf("postfix expression : 82/3-32*+\n");
	result = eval("82/3-32*+");
	printf("calculation result : %d", result);
}