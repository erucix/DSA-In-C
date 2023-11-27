#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int val;
	int p;
	struct Node *next;
} Node;

Node *que;

void enque(int data, int p){
	Node *newNode = malloc(sizeof(Node));
	newNode->val = data;
	newNode->p = p;

	Node *temp = que;

	if(que == NULL) {
		newNode->next = NULL;
		que = newNode;	
	} else if(que->p > p) {
		newNode->next = que;
		que = newNode;
	} else {
		while(temp->next != NULL && temp->next->p < p) {
			temp=temp->next;
		}

		newNode->next = temp->next;
		temp->next = newNode;

	}
}

int deque(){
	if(que == NULL) {
		fprintf(stderr, "Que Underflow.\n");
		return -1;
	} else {
		Node *temp = que;
		que=que->next;
		free(temp);
	}
}

void print(){
	Node *temp = que;

	printf("\n");

	while(temp) {
		printf("%d ", temp->val);
		temp=temp->next;
	}

	printf("\n");
}

int main(){
	int option, p;

	while(1){
		printf("\n1] Enqueue\n2] Dequeue\n3] Traverse\n:>");
		scanf("%d", &option);

		if(option == 1) {
			printf("\nEnter values: \n");
			do{
				scanf("%d %d", &option, &p);
				enque(option, p);
			} while(option != 0);
		} else if (option == 2) {
			printf("\nDeleted: %d\n", deque());
		} else if(option == 3) {
			print();
		}
		fflush(stdin);
		getchar();
	}
}
