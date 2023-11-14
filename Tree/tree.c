#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node *left, *right;
} Node;

void insert(Node *tree, int val){
	Node *temp = tree;
	Node *newNode = malloc(sizeof(temp));
	newNode->val = val;
	
	if(temp == NULL) {
		tree = newNode;
		return;
	}

	while(temp){
		if(temp->right->val > val){
			temp = temp->right;
		} else {
			temp = temp->left;
		}
	}

	temp = newNode;
}

void preOrder(Node *tree){
	if(tree == NULL) {
		printf("%d", 69);
		return;
	}

	printf("%d ", tree->val);
	preOrder(tree->left);
	preOrder(tree->right);
}

int main(){
	Node *tree;
	insert(tree, 10);
	insert(tree, 20);
	insert(tree, 33);
	insert(tree, 1);
	insert(tree, 6);
	preOrder(tree);
}
