#include<stdio.h>
#include<malloc.h>
#include<limits.h>
#include<stdlib.h>

#define FALSE 0
#define TRUE 1

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode;

typedef struct {
	int length;
	ListNode *head;
}LinkedListType;

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void insert_node(ListNode **phead, ListNode *p, ListNode *new_node) {
	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) {
		new_node->link = *phead;
		*phead = new_node;
	}
	else {
		new_node->link = p->link;
		p->link = new_node;
	}
}

void remove_node(ListNode **phead, ListNode *p, ListNode *remove) {
	if (p == NULL)
		*phead = (*phead)->link;
	else
	{
		p->link = remove->link;
	}
	free(remove);
}

ListNode *get_node_at(LinkedListType *list, int index) {
	int i;
	ListNode *temp_node = list->head;
	if (index < 0)
		return NULL;
	for (i = 0; i < index; i++) {
		temp_node = temp_node->link;
	}
	return temp_node;
}

int get_length(LinkedListType *list) {
	return list->length;
}

void add(LinkedListType *list, int index, element data) {
	ListNode *p;
	if ((index >= 0) && (index <= list->length)) {
		ListNode *node = (ListNode *)malloc(sizeof(ListNode));
		if (node == NULL)
			error("memory allocation error");
		node->data = data;
		p = get_node_at(list, index - 1);
		insert_node(&(list->head), p, node);
		list->length++;
	}
}

void add_last(LinkedListType *list, element data) {
	add(list, get_length(list), data);
}

void add_first(LinkedListType *list, element data) {
	add(list, 0, data);
}

int is_empty(LinkedListType *list) {
	if (list->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void delete(LinkedListType *list, int index) {
	if (!is_empty(list) && (index >= 0) && (index < list->length)) {
		ListNode *p = get_node_at(list, index - 1);
		ListNode *remove = get_node_at(list, index);
		remove_node(&(list->head), p, remove);
		list->length--;
	}
}

element get_entry(LinkedListType *list, int index) {
	ListNode *p;
	if (index >= list->length)
		error("index error");
	p = get_node_at(list, index);
	return p->data;
}

void clear(LinkedListType *list) {
	int i;
	for (i = 0; i < list->length; i++)
		delete(list, i);
}

void display(LinkedListType *list) {
	int i;
	ListNode *node = list->head;
	printf("(");
	for (i = 0; i < list->length; i++) {
		printf("%d ", node->data);
		node = node->link;
	}
	printf(")\n");
}

int is_in_list(LinkedListType *list, element item) {
	ListNode *p;
	p = list->head;
	while ((p != NULL)) {
		if (p->data == item)
			break;
		p = p->link;
	}
	if (p == NULL)
		return FALSE;
	else
		return TRUE;
}

void init(LinkedListType *list) {
	if (list == NULL)
		return;
	list->length = 0;
	list->head = NULL;
}

int main() {
	LinkedListType list1;

	init(&list1);
	add(&list1, 0, 20);
	add_last(&list1, 30);
	add_first(&list1, 10);
	add_last(&list1, 40);

	display(&list1);

	delete(&list1, 3);
	display(&list1);

	delete(&list1, 0);
	display(&list1);

	printf("%s\n", is_in_list(&list1, 20) == TRUE ? "TRUE" : "FALSE");
	printf("%d\n", get_entry(&list1, 0));

	return 0;
}