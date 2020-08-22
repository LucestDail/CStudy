#include<stdio.h>
#include<string.h>

#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct {
	short r;
	short c;
}element;

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
}StackType;

element now = { 1,0 };
element next = { 1,0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1','1','1','1','1','1'},
	{'a','0','0','0','0','1'},
	{'1','0','1','0','1','1'},
	{'1','1','1','0','0','z'},
	{'1','1','1','0','1','1'},
	{'1','1','1','1','1','1'}
};

//스택 초기화
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

void push_loc(StackType* s, int r, int c) {
	if (r < 0 || c < 0)
		return;
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		element temp;
		temp.r = r;
		temp.c = c;
		push(s, temp);
	}
}

void main() {
	int r, c;
	StackType s;

	init(&s);
	now = next;
	while (maze[now.r][now.c] != 'z') {
		r = now.r;
		c = now.c;
		maze[r][c] = '.';
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);
		if (is_empty(&s)) {
			printf("미로 출구 없음\n");
			return;
		}
		else {
			now = pop(&s);
		}
	}
	printf("탈출 성공!\n");
}