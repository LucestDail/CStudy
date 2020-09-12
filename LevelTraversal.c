#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<malloc.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

typedef TreeNode* element;

typedef struct QueueNode {
	element item;
	struct QueueNode* link;
}QueueNode;

typedef struct {
	QueueNode* front, * rear;
}QueueType;

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

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

void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("%d\n", root->data);
		inorder(root->right);
	}
}

void preorder(TreeNode* root) {
	if (root) {
		printf("%d\n", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(TreeNode* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("%d\n", root->data);
	}
}

void level_order(TreeNode* ptr) {
	QueueType q;
	init(&q);
	if (ptr == NULL)
		return;
	
	enqueue(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		printf("%d\n", ptr->data);
		if (ptr->left)
			enqueue(&q, ptr->left);
		if (ptr->right)
			enqueue(&q, ptr->right);
	}
}


void main() {
	printf("Level Order Traversal -----------------\n");
	level_order(root);
	printf("Inorder Traversal -----------------\n");
	inorder(root);
	printf("preorder Traversal ----------------\n");
	preorder(root);
	printf("postorder Traversal ---------------\n");
	postorder(root);
}