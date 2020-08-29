#include<stdio.h>
#include<malloc.h>

typedef int element;

typedef struct QueueNode{
	element item;
	struct QueueNode* link;
}QueueNode;

typedef struct {
	QueueNode *front, *rear;
}QueueType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(QueueType* q) {
	q->front = q->rear = NULL;
}

int is_empty(QueueType* q) {
	return (q->front == NULL);
}

void enqueue(QueueType* q, element item) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL) {
		error("메모리 할당 불가");
	}
	else {
		temp->item = item;
		temp->link = NULL;
		if (is_empty(q)) {
			q->front = temp;
			q->rear = temp;
		}
		else {
			q->rear->link = temp;
			q->rear = temp;
		}
	}
}

element dequeue(QueueType* q) {
	QueueNode* temp = q->front;
	element item;
	if (is_empty(q)) {
		error("큐 공백 상태");
	}
	else {
		item = temp->item;
		q->front = q->front->link;
		if (q->front == NULL) {
			q->rear = NULL;
		}
		free(temp);
		return item;
	}
}

element peak(QueueType* q) {
	if (is_empty(q)) {
		error("큐 공백 상태");
	}
	return q->front->item;
}

void main() {
	QueueType q;
	init(&q);
	printf("front : %p\nrear : %p\n", q.front, q.rear);
	enqueue(&q, 1);
	printf("front : %p\nrear : %p\n", q.front, q.rear);
	enqueue(&q, 2);
	printf("front : %p\nrear : %p\n", q.front, q.rear);
	enqueue(&q, 3);
	printf("front : %p\nrear : %p\n", q.front, q.rear);
	printf("dequeue : %d\n", dequeue(&q));
	printf("front : %p\nrear : %p\n", q.front, q.rear);
	printf("dequeue : %d\n", dequeue(&q));
	printf("front : %p\nrear : %p\n", q.front, q.rear);
	printf("dequeue : %d\n", dequeue(&q));
	printf("front : %p\nrear : %p\n", q.front, q.rear);
}