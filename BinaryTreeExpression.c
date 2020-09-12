#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<malloc.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

int calc_direc_size(TreeNode* root) {
	int left_size, right_size;
	if (root != NULL) {
		left_size = calc_direc_size(root->left);
		right_size = calc_direc_size(root->right);
		return (root->data + left_size + right_size);
	}
	return 0;
}

int get_node_count(TreeNode* node)
{
	int count = 0;
	if (node != NULL)
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	return count;
}

int get_leaf_count(TreeNode* node) {
	int count = 0;
	if (node != NULL) {
		if (node->left == NULL && node->right == NULL)
			return 1;
		else count = get_leaf_count(node->left) + get_leaf_count(node->right);
	}
	return count;
}

int get_height(TreeNode* node) {
	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}


void main() {
	TreeNode n4 = { 500, NULL, NULL };
	TreeNode n5 = { 200, NULL, NULL };
	TreeNode n3 = { 100, &n4, &n5 };
	TreeNode n2 = { 50, NULL, NULL };
	TreeNode n1 = { 0, &n2, &n3 };
	printf("Directory Size Traversal -----------------\n");
	printf("total size : %d\n", calc_direc_size(&n1));
	printf("Node count : %d\n", get_node_count(&n1));
	printf("Terminal node count : %d\n", get_leaf_count(&n1));
	printf("Height : %d\n", get_height(&n1));
}