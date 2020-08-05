#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

typedef int element;
typedef struct DualListNode {
	element data;
	struct DualListNode *beforeLink;
	struct DualListNode *afterLink;
}DualListNode;
//초기화(헤드 노드)
void init(DualListNode *phead) {
	phead->afterLink = phead;
	phead->beforeLink - phead;
}
//에러
void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//전체 순환, 출력
void display(DualListNode *phead) {
	DualListNode *p;
	for (p = phead->afterLink; p != phead; p = p->afterLink) {
		printf("<===[ %x ][%d][ %x ] ===>\n", p->beforeLink, p->data, p->afterLink);
	}
	printf("\n");
}
//삽입
void insert_node(DualListNode *before_node, DualListNode *new_node) {
	new_node->beforeLink = before_node;
	new_node->afterLink = before_node->afterLink;
	before_node->afterLink->beforeLink = new_node;
	before_node->afterLink = new_node;
}
//삭제
void remove_node(DualListNode *phead_node, DualListNode *remove_node) {
	if(remove_node == phead_node)
		return;
	remove_node->beforeLink->afterLink = remove_node->afterLink;
	remove_node->afterLink->beforeLink = remove_node->beforeLink;
	free(remove_node);
}

int main() {
	DualListNode head_node;
	DualListNode *p[10];
	int i;

	init(&head_node);
	for (i = 0; i < 10; i++) {
		p[i] = (DualListNode *)malloc(sizeof(DualListNode));
		p[i]->data = i;
		insert_node(&head_node, p[i]);
	}
	remove_node(&head_node, p[5]);
	display(&head_node);
	return 0;
}