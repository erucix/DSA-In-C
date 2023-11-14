#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
	int size;
	int top;
	int *body;
} Stack;

Stack stack;

void push(int data){
	if(stack.size - 1 == stack.top) {
		fprintf(stderr, "Stack overflow.\n");
	} else {

		stack.body = realloc(stack.body, (stack.top == -1 ? 1 : 0) + ++stack.top);
		stack.body[stack.top] = data;
	}
}

int pop(){
	if(stack.top == -1) {
		fprintf(stderr, "Stack Underflow.\n");
		return -1;
	}
	return stack.body[stack.top--];
}

void print(){
	int x = stack.top;

	printf("\n");

	while(x != -1) {
		printf("%d  ", stack.body[x--]);
	}

	printf("\n");
}

int main(){

	stack.size = 10;
	stack.top = -1;

	push(1);
	push(5);
	push(7);
	push(7);
	push(12);
	print();
	pop();
	pop();
	push(332);
	pop();
	print();
	free(stack.body);
}
