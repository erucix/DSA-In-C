#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];
int top1 = -1;
int top2 = MAX;

void push1(int data){
	if(top1 == top2 - 1){
		fprintf(stderr, "Stack Overflow.\n");
	} else {
		stack[++top1] = data;
	}
}

void push2(int data){
	if(top1 == top2 - 1){
		fprintf(stderr, "Stack Overflow.\n");
	} else {
		stack[--top2] = data;
	}
}

int pop1(){
	if(top1 != -1) {
		return stack[top1--];
	} else {
		fprintf(stderr, "Stack Underflow.\n");
		return -1;
	}
}

int pop2(){
	if(top2 + 1 == MAX){
		fprintf(stderr, "Stack Underflow.\n");
		return -1;
	} else {
		return stack[top2++];
	}
}

int isFull(){
	return top1 == top2 - 1;
}

int isEmpty(){
	return (top1 == -1) && (top2 == MAX - 1);
}

void print(){
	int x = top1;
	int y = top2;

	printf("\n");
	while(x != -1) {
		printf("%d ", stack[x--]);
	}
	printf("\n");
	while(y != MAX - 1) {
		printf("%d ", stack[y++]);
	}
	printf("\n");
}

int main(){
	push1(2);
	push2(3);
	push1(1);
	push2(2);
	push2(3);
	push2(4);
	push2(5);
	push1(7);
	push2(10);
	push2(11);
	push1(100);
	pop1();
	pop2();
	print(); // 2 1 7 10, 3 2 3 4 5 10 11 => 2 1 7, 3 2 3 4 5 10 11 BUT stackoverflow for 100 so 2 1 7, 3 2 3 4 5 10
}
