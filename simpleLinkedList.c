/*
* 기본적인 헤더 삽입
*/
#include<stdio.h>
#include<stdlib.h>

/*
* 노드 구성할 요소 및 노드에 대한 정보(인트형 요소 데이터, 링크), ListNode 구조체로 선언
*/
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode;
//에러 캐치
void error(char *message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//삽입 연산
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
//삭제 연산
void remove_node(ListNode **phead, ListNode *p, ListNode *removed) {
	if (p == NULL) {
		*phead = (*phead)->link;
	}
	else {
		p->link = removed->link;
	}
	free(removed);
}
//방문 연산
void display(ListNode *head) {
	ListNode *p = head;
	while (p != NULL) {
		printf("%d -> ", p->data);
		p = p->link;
	}
	printf("\n");
}
//순환 연산(테스트 용)
void display_recur(ListNode *head) {
	ListNode *p = head;
	if (p != NULL) {
		printf("%d->", p->data);
		display_recur(p->link);
	}
}
//탐색 연산
ListNode *search(ListNode *head, int x) {
	ListNode *p;
	p = head;
	while (p != NULL) {
		if (p->data == x) {
			return p;
		}
		p = p->link;
	}
}
//리스트 연결 연산
ListNode *concat(ListNode *head1, ListNode *head2) {
	ListNode *p;
	if (head1 == NULL) {
		return head2;
	}
	else if(head2 == NULL){
		return head1;
	}
	else {
		p = head1;
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = head2;
		return head1;
	}
}
//역연산
ListNode *reverse(ListNode *head) {
	ListNode *p, *q, *r;
	p = head;
	q = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}
//리스트 길이 연산
void get_length(ListNode *head) {
	int size = 0;
	ListNode *p = head;
	while (p != NULL) {
		printf("%d -> ", p->data);
		p = p->link;
		size++;
	}
	printf("length : %d\n",size);
}

//노드 동적 생성
ListNode *create_node(element data, ListNode *link) {
	ListNode *new_node;
	new_node = (ListNode *)malloc(sizeof(ListNode));
	if (new_node == NULL) {
		error("메모리 할당 에러");
	}
	new_node->data = data;
	new_node->link = link;
	return (new_node);
}
int main() {
	ListNode *list1 = NULL;
	ListNode *list2 = NULL;
	ListNode *p;

	//list1 = 30 -> 20 -> 10
	insert_node(&list1, NULL, create_node(10, NULL));
	insert_node(&list1, NULL, create_node(20, NULL));
	insert_node(&list1, NULL, create_node(30, NULL));
	display(list1);

	//list2 = 300 -> 200 -> 100
	insert_node(&list2, NULL, create_node(100, NULL));
	insert_node(&list2, NULL, create_node(200, NULL));
	insert_node(&list2, NULL, create_node(300, NULL));
	display(list2);

	//length function
	get_length(list1);
	get_length(list2);

	//list1 = 20 -> 10
	remove_node(&list1, NULL, list1);
	display(list1);

	//list1 = list1 + list2
	list1 = concat(list1, list2);
	display(list1);

	//list1 역순
	list1 = reverse(list1);
	display(list1);

	//list1 20탐색
	p = search(list1, 20);
	printf("탐색 성공 : %d\n", p->data);

	return 0;
}