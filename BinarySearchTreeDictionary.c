#pragma warning(disable: 4996)

#include
#include
#include
#include

#define MAX_WORD_SIZE 100
#define MAX_MEANING_SIZE 200

typedef struct {
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANING_SIZE];
} element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

int compare(element e1, element e2) {
	return strcmp(e1.word, e2.word);
}

void display(TreeNode* p) {
	if (p != NULL) {
		printf("(");
		display(p->left);
		printf("%s", p->key.word);
		display(p->right);
		printf(")");
	}
}
TreeNode* search(TreeNode* root, element key) {
	TreeNode* p = root;
	while (p != NULL) {
		switch (compare(key, p->key)) {
		case -1:
			p = p->left; break;
		case 0:
			return p;
		case 1:
			p = p->right; break;
		}
	}
	return p;
}

void insert_node(TreeNode** root, element key) {
	TreeNode* p, * t;
	TreeNode* n;
	t = *root;
	p = NULL;
	while (t != NULL) {
		if (compare(key, t->key) == 0) return;
		p = t;
		if (compare(key, t->key) < 0)
			t = t->left;
		else
			t = t->right;
	}
	n = (TreeNode*)malloc(sizeof(TreeNode));
	if (n == NULL)
		return;
	n->key = key;
	n->left = n->right = NULL;
	if (p != NULL)
		if (compare(key, t->key) < 0)
			p->left = n;
		else p->right = n;
	else *root = n;
}

void delete_node(TreeNode** root, element key) {
	TreeNode* p, * child, * succ, * succ_p, * t;
	// key 를 갖는 노드 t 를 탐색하며, p 는 t 의 부모 노드입니다!
	p = NULL;
	t = *root;
	//key 를 가지고 있는 노드 t 를 탐색합니다.
	while (t != NULL && compare(t->key, key) != 0) {
		p = t;
		t = (compare(t->key, key) < 0) ? t->left : t->right;
	}
	//key 가 없을 경우
	if (t == NULL) {
		printf("키값이 없습니다...");
		return;
	}
	//key 는 찾았는데 터미널 노드인 경우
	if ((t->left == NULL) && (t->right == NULL)) {
		if (p != NULL) {
			if (p->left == t)
				p->left == NULL;
			else p->right = NULL;
		}
		else
			*root = NULL;
	}
	//key 는 찾았는데 한쪽만 서브트리가 있는 경우
	else if ((t->left == NULL) || (t->right == NULL)) {
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL) {
			if (p->left == t)
				p->left = child;
			else p->right = child;
		}
		else
			*root = child;
	}
	//key 는 찾았는데 양쪽에 서브트리가 있는 경우
	else {
		succ_p = t;
		succ = t->right;
		// 우측 서브트리로 쭉쭉 내려갑시다.
		while (succ->left != NULL) {
			succ_p = succ;
			succ = succ->left;
		}
		if (succ_p->left == succ)
			succ_p->left = succ->right;
		else
			succ_p->right = succ->right;
		t->key = succ->key;
		t = succ;
	}
	free(t);
}

void help() {
	printf("--------------------\n");
	printf("i : 입력(input)\n");
	printf("d : 삭제(delete)\n");
	printf("s : 탐색(search)\n");
	printf("p : 출력(print)\n");
	printf("q : 종료(quit)\n");
	printf("--------------------\n");
}

void main() {
	char command;
	element e;
	TreeNode* root = NULL;
	TreeNode* tmp;

	do {
		help();
		command = getchar();
		fflush(stdin);
		switch (command) {
		case 'i':
			printf("단어 : ");
			gets(e.word);
			printf("의미 : ");
			gets(e.meaning);
			insert_node(&root, e);
			break;
		case 'd':
			printf("단어 : ");
			gets(e.word);
			delete_node(&root, e);
			break;
		case 'p':
			display(root);
			printf("\n");
			break;
		case 's':
			printf("단어 : ");
			gets(e.word);
			tmp = search(root, e);
			if (tmp != NULL)
				printf("의미 : %s\n",e.meaning);
			break;
		}
	} while (command != 'q');
}