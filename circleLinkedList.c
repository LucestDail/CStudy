#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode;

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode *create_node(element data, ListNode *link) {
	ListNode *new_node;
	new_node = (ListNode *)malloc(sizeof(ListNode));
	if (new_node == NULL) {
		error("memory allocating error");
	}
	new_node->data = data;
	new_node->link = link;
	return(new_node);
}

void display(ListNode *head) {
	ListNode *p;
	if (head == NULL)
		return;
	p = head;
	do {
		printf("%d ->", p->data);
		p = p->link;
	} while (p != head);
	printf("\n");
}

void get_length(ListNode *head) {
	ListNode *p;
	if (head == NULL)
		return;
	p = head;
	int size = 0;
	do {
		p = p->link;
		size++;
	} while (p != head);
	printf("length : %d\n", size);
}


void insert_first(ListNode **phead, ListNode *node) {
	if (*phead == NULL) {
		*phead = node;
		node->link = node;
	}
	else {
		node->link = (*phead)->link;
		(*phead)->link = node;
	}
}

void insert_last(ListNode **phead, ListNode *node) {
	if (*phead == NULL) {
		*phead = node;
		node->link = node;
	}
	else {
		node->link = (*phead)->link;
		(*phead)->link = node;
		*phead = node;
	}
}

int main() {
	ListNode *list1 = NULL;
	insert_first(&list1, create_node(10, NULL));
	insert_first(&list1, create_node(20, NULL));
	insert_last(&list1, create_node(30, NULL));
	display(list1);
	get_length(list1);
	return 0;
}