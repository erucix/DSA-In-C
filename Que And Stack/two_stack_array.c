#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack1[MAX];
int stack2[MAX];

int top1, top2;
top1=top2=-1;

void push1(int data){
	if (top1 == MAX/2 - 1) {
		fprintf(stderr, "Stack overflow.");
	} else {
		stack1[++top1] = data;
	}
}

void push2(int data){
	if(top2 == MAX - 1) {
		fprintf(stderr, "Stack overflow.");
	} else {
		stack2[++top2] = data;
	}
}

int pop1(){
	if(top1 == -1){
		fprintf(stderr, "Stack underflow.");
		return -1;
	} else {
		return stack1[top--];
	}
}

int pop2(){
	if(top2 == MAX/2 -1) {
		fprintf(stderr, "Stack underflow.");
		return -1;
	} else {
		return stack2[top2--];
	}
}

int isEmpty1(){
	return (top1 == -1);
}

int isEmpty2(){
	return (top2 == MAX/2 -1);
}

int main(){
	
}
