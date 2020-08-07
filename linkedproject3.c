#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX_CHAR_PER_LINE 1000
#define MAX_NAME 256
#define TRUE 1
#define FALSE 0

void warning(char *);
void error(char *);

typedef struct {
	char a[MAX_CHAR_PER_LINE];
}element;

typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode;

typedef struct {
	ListNode *head;
	int length;
}LinkedListType;

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

void init(LinkedListType *list) {
	if (list == NULL)
		return;
	list->length = 0;
	list->head = NULL;
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

void display(LinkedListType *buffer) {
	int i;
	ListNode *temp_node;
	temp_node = buffer->head;
	printf("----------------------------\n");
	for (i = 0; i < buffer->length; i++) {
		printf("%s", temp_node->data.a);
		temp_node = temp_node->link;
	}
	printf("----------------------------\n");
}

void warning(char *message) {
	fprintf(stderr, "%s\n", message);
}

void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void help() {
	printf("----------------------------\n");
	printf("i : 입력\n");
	printf("d : 삭제\n");
	printf("r : 읽기\n");
	printf("w : 쓰기\n");
	printf("q : 종료\n");
	printf("----------------------------\n");
}

void read_file(LinkedListType *buffer) {
	char fname[MAX_NAME];
	FILE *fd;
	element p;
	if (!is_empty(buffer)) {
		clear(buffer);
	}
	init(buffer);

	printf("파일 이름 : ");
	scanf("%s", fname);
	if ((fd = fopen(fname, "r")) == NULL) {
		warning("파일 못열겠어용...\n");
		return;
	}
	while (fgets(p.a, MAX_CHAR_PER_LINE, fd)) {
		add_last(buffer, p);
	}
	fclose(fd);
	display(buffer);
}

void write_file(LinkedListType *buffer) {
	FILE *fd;
	char fname[MAX_NAME];
	element p;
	int i;
	printf("파일 이름 : ");
	scanf("%s", fname);
	if ((fd = fopen(fname, "w")) == NULL) {
		warning("파일 못열겠어용...\n");
		return;
	}
	for (i = 0; i < get_length(buffer); i++) {
		p = get_entry(buffer, i);
		fputs(p.a, fd);
	}
	fclose(fd);
	display(buffer);
}

void delete_line(LinkedListType *buffer) {
	int index;
	if (is_empty(buffer)) {
		printf("이미 없어용...\n");
	}
	else {
		printf("지울 줄은 몇번쨰 줄인가용?\n");
		scanf("%d", &index);
		delete(buffer, index);
	}
	display(buffer);
}

void insert_line(LinkedListType *buffer) {
	int index;
	char line[MAX_CHAR_PER_LINE];
	element p;
	printf("몇번째 줄에 쓰실건가용\n");
	scanf("%d", &index);
	printf("쓰실 내용을 입력하세용\n");
	fflush(stdin);
	fgets(line, MAX_CHAR_PER_LINE, stdin);
	strcpy(p.a, line);
	add(buffer, index, p);
	display(buffer);
}

void do_command(LinkedListType *buffer, char command) {
	switch (command)
	{
		case 'd':
			delete_line(buffer);
			break;
		case 'i':
			insert_line(buffer);
			break;
		case 'r':
			read_file(buffer);
			break;
		case 'w':
			write_file(buffer);
			break;
		case 'q':
			break;
	}
}

int main() {
	char command;
	LinkedListType buffer;

	init(&buffer);
	do {
		help();
		command = getchar();
		do_command(&buffer, command);
		fflush(stdin);
	} while (command != 'q');
}