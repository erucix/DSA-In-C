#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int val;
	struct Node *left, *right;
} Node;

typedef struct Stack
{
	Node *val;
	struct Stack *next;
} Stack;

Node *new *(int);
void pre_print(Node *);
void in_print(Node *);
void u_in_print(Node *);
void u_in_print(Node *);
void insert(Node *, Node *);
void push(Node *, Stack **);
Node *pop(Stack **);
int isEmpty(Stack **);

/* Creates a barebone Node and returns its
 * address.
 *
 * @param {number} val - Value to store in Node.
 * @return {Node *} newNode - Address of Node.
 */
Node *new(int val)
{
	Node *newNode = malloc(sizeof(Node));
	newNode->val = val;
	newNode->right = newNode->left = NULL;

	return newNode;
}

/* Traverse tree in pre-order
 *
 * @param {Node *} - Address of root node.
 * @return {void}
 */
void pre_print(Node *root)
{
	if (root == NULL)
	{
		return;
	}

	printf("%d ", root->val);
	pre_print(root->left);
	pre_print(root->right);
}

/* Traverse tree in in-order
 *
 * @param {Node *} - Address of root node.
 * @return {void}
 */
void in_print(Node *root)
{
	if (root == NULL)
	{
		return;
	}

	in_print(root->left);
	printf("%d ", root->val);
	in_print(root->right);
}

/* Traverse tree in post-order.
 *
 * @param {Node *} - Address of root node.
 * @return {void}
 */
void post_print(Node *root)
{
	if (root == NULL)
	{
		return;
	}

	post_print(root->left);
	post_print(root->right);
	printf("%d ", root->val);
}

void u_in_print(Node *root)
{
	Stack *stack;

	while (root)
	{
		if (root != NULL)
		{

			push(&stack, root);
			root = root->left;
		}
		else if (!isEmpty(&stack))
		{

			root = pop(&stack);
			printf("%d ", root->val);
			root = root->right;
		}
		else
		{
			break;
		}
	}
}

/* Inserts a node to a tree.
 *
 * @param {Node *} - Address of the root node.
 * @param {Node *} - Address of node to insert.
 * @return {void}
 */
void insert(Node *root, Node *newNode)
{
}

/* Pushes a Node * into stack.
 *
 * @param {Node *val} - Address of node to push.
 * @param {Stack **stack} - Address of top of stack.
 *
 */
void push(Node *val, Stack **stack)
{
	Stack *newItem = malloc(sizeof(Node));
	newItem->val = val;
	newItem->next = NULL;

	if (*stack == NULL)
	{
		*stack = newItem;
	}
	else
	{
		newItem->next = *stack;
		*stack = newItem;
	}
}

Node *pop(Stack **stack)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "Stack Underflow.");
		return NULL;
	}
	else
	{
		Node *item = (*stack)->val;
		Stack *temp = *stack;
		*stack = (*stack)->next;

		free(temp);
		return item;
	}
}

int isEmpty(Stack **stack)
{
	return *stack == NULL;
}

#endif
