#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int rear = -1;
int front = 0;
int que[MAX];


int enque(int data){
	if(rear == MAX - 1) {
		fprintf(stderr, "Stack Overflow.\n");
	} else {
		que[++rear] = data;
	}
}

int deque(){
	if(rear < front) {
		fprintf(stderr, "Que Underflow\n");
		return -1;
	} else {
		return que[front++];
	}
}

int print(){
	printf("\n");

	for(int i = front; i != rear && rear != -1; i++) {
		printf("%d ", que[i]);
	}

	printf("\n");
}

int main(){
	enque(10);
	enque(20);
	enque(30);
	enque(40);
	print();
	deque();
	print();
	enque(50);
	enque(60);
	enque(70);
	enque(80);
	enque(90);
	enque(100);
	enque(110);
	print();
	deque();
	print();
}
