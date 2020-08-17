#include<stdio.h>
#include<malloc.h>

typedef int element;

typedef struct StackNode{
	element item;
	struct StackNode* link;
}StackNode;

typedef struct {
	StackNode* top;
}LinkedStackType;

void init(LinkedStackType *s) {
	s->top = NULL;
}
//���� ���� �Ǵ�
int is_empty(LinkedStackType *s) {
	return (s->top == NULL);
}

//���� �Լ�
void push(LinkedStackType *s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "���� ��ȭ����");
		return;
	}
	else {
		temp->item = item;
		temp->link = s->top;
		s->top = temp;
	}
}
//��� - ���� �Լ�
element pop(LinkedStackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� �������");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		element item = temp->item;
		s->top = s->top->link;
		free(temp);
		return temp;
	}
}
//��ũ �Լ�
element peek(LinkedStackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� �������");
		exit(1);
	}
	else {
		return s->top->item;
	}
}
int main() {
	LinkedStackType s;
	init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", peek(&s));
	printf("%d\n", is_empty(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", peek(&s));
	printf("%d\n", is_empty(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", peek(&s));
	printf("%d\n", is_empty(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", is_empty(&s));
	return 0;
}
