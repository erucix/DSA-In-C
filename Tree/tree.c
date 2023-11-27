#include "tree.h"

int main(){
	Node *root = new(5);
	root->left = new(4);
	root->right = new(6);

	in_print(root);
}
