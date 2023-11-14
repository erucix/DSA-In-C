#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node *next;
} Node;

Node *head;

void push(int data){
	Node *newNode = malloc(sizeof(Node));
	newNode->val = data;
	newNode->next = head;
	head = newNode;
}

int pop(){
	if(head == NULL) {
		fprintf(stderr, "Stack underflow.\n"); 
		return -1;
	}
	int val = head->val;

	Node *temp = head;
	head=head->next;
	free(temp);

	return val;
}

void print(){
	Node *temp = head;

	while(temp){
		printf("%d-", temp->val);
		temp=temp->next;
	}

	printf("\n");
}

int main(){
	head=NULL;
	push(5);
	push(6);
	push(3);
	push(78);
	print();
	pop();
	pop();
	push(44);
	print();
}
