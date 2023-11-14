#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];
int top = -1;

void push(int data){
	if(top + 1 == MAX){
		fprintf(stderr, "Stack overflow.");
	} else {
		stack[++top] = data;
	}
}

int pop(){
	if(top == -1) {
		fprintf(stderr, "Stack underflow.");
		return -1;
	}

	return stack[top--];
}

int isFull(){
	return (top == MAX + 1);
}

int isEmpty(){
	return (top == -1);
}

void traverse(){
	int i = top;
	printf("\n");

	while(i != -1){
		printf("%d  ", stack[i--]);
	}

	printf("\n");
}

int main(){
	int option;
	while(1){
		printf("1] Push\n2] Pop\n3] Is Empty\n4] Is Full\n5] Traverse\n");
		scanf("%d", &option);
		system("clear");

		if(option == 1) {
			printf("Enter values:\n");
			while(1){
				scanf("%d", &option);
				if (option == -1)
					break;
				push(option);
			}
		} else if(option == 2) {
			printf("\nPopped: %d\n", pop());
		} else if (option == 3) {
			printf("\nIs Empty: %d\n", isEmpty());
		} else if (option == 4) {
			printf("\nIs Full: %d\n", isFull());
		} else {
			traverse();
		}
		//fflush(stdin);
		getchar();
	}

	return 0;
}
