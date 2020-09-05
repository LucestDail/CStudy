#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int element;
typedef struct DlistNode {
	element data;
	struct DlistNode* llink;
	struct DlistNode* rlink;
}DlistNode;
typedef struct DequeType {
	DlistNode* head;
	DlistNode* tail;
}DequeType;

//error push function
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//initialization function
void init(DequeType* dq) {
	dq->head = dq->tail = NULL;
}
//creating node function
DlistNode* create_node(DlistNode* llink, element item, DlistNode* rlink) {
	DlistNode* node = (DlistNode*)malloc(sizeof(DlistNode));
	if (node == NULL) {
		error("Memory Allocation error has been occured");
	}
	node->llink = llink;
	node->data = item;
	node->rlink = rlink;
	return node;
}
//empty check function
int is_empty(DequeType* dq) {
	if (dq->head == NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}
//rear adding function
void add_rear(DequeType* dq, element item) {
	DlistNode* new_node = create_node(dq->tail, item, NULL);
	if (is_empty(dq)) {
		dq->head = new_node;
	}
	else {
		dq->tail->rlink = new_node;
	}
	dq->tail = new_node;
}
//front adding function
void add_front(DequeType* dq, element item) {
	DlistNode* new_node = create_node(NULL, item, dq->head);
	if (is_empty(dq)) {
		dq->tail = new_node;
	}
	else {
		dq->head->llink = new_node;
	}
	dq->head = new_node;
}
//front removing function
element delete_front(DequeType* dq) {
	element item;
	DlistNode* removed_node;

	if (is_empty(dq)) {
		error("Deque is empty now");
	}
	else {
		removed_node = dq->head;
		item = removed_node->data;
		dq->head = dq->head->rlink;
		free(removed_node);
		if (dq->head == NULL) {
			dq->tail = NULL;
		}
		else {
			dq->head->llink = NULL;
		}
	}
	return item;
}
//rear removing function
element delete_rear(DequeType* dq) {
	element item;
	DlistNode* removed_node;

	if (is_empty(dq)) {
		error("Deque is empty now");
	}
	else {
		removed_node = dq->tail;
		item = removed_node->data;
		dq->tail = dq->tail->llink;
		free(removed_node);
		if (dq->tail == NULL) {
			dq->head = NULL;
		}
		else {
			dq->tail->rlink = NULL;
		}
	}
	return item;
}
//peek element
void display(DequeType* dq) {
	DlistNode* p;
	printf("(");
	for (p = dq->head; p != NULL; p = p->rlink) {
		printf("%d", p->data);
	}
	printf(")\n");
}

void main() {
	DequeType deque;

	init(&deque);
	display(&deque);
	add_front(&deque, 10);
	display(&deque);
	add_front(&deque, 20);
	display(&deque);
	add_rear(&deque, 30);
	display(&deque);
	delete_front(&deque);
	display(&deque);
	delete_rear(&deque);
	display(&deque);
}