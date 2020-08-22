#include<stdio.h>

#define MAX_STACK_SIZE 100
#define FALSE 0
#define TRUE 1

typedef char element;
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

int check_matching(char* in) {
	StackType s;
	char ch, open_ch;
	int i;
	int n = strlen(in);
	init(&s);

	for (i = 0; i < n; i++) {
		ch = in[i];
		switch (ch) {
		case '(': case '[': case'{':
			push(&s, ch);
			break;
		case ')': case']': case'}':
			if (is_empty(&s))
				return FALSE;
			else {
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') ||
					(open_ch == '[' && ch != ']') ||
					(open_ch == '{' && ch != '}')) {
					return FALSE;
				}
				break;
			}

		}
	}
	if (!is_empty(&s)) {
		return FALSE;
	}
	return TRUE;
}

int main() {
	if (check_matching("{[()]}") == TRUE) {
		printf("괄호 정상\n");
	}
	else {
		printf("괄호 비정상\n");
	}
	if (check_matching("{)]}") == TRUE) {
		printf("괄호 정상\n");
	}
	else {
		printf("괄호 비정상\n");
	}
}