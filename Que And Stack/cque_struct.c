#include <stdio.h>
#include <stdlib.h>

struct Que {
	int size;
	int rear;
	int front;
	int *body;
} que;


int isFull(){
	return ((que.front == que.rear + 1) || (que.front == 0 && (que.rear == que.size - 1)));
}

void push(int data){
	if(isFull()) {
		fprintf(stderr, "Que Overflow.\n");
	} else {
		que.rear = (que.rear + 1) % que.size;
//		printf("%d\n", que.rear);
		que.body[que.rear] = data;
	}
}

int pop(){
	if(que.front == -1) {
		fprintf(stderr, "Que Underflow\n");
		return -1;
	} else {
		int x = que.front;
		
		if(que.front == que.rear){
			que.front = -1;
			que.rear = -1;
		} else {
			que.front = (que.front + 1) % que.size;
		}

		return que.body[x];
	}
}

void print(){
	printf("%d, %d\n", que.front, que.rear);

	for(int i = que.front; i != que.rear; i = (i+1) % que.size){
		printf("%d ", que.body[i]);
	}
	printf("\n");
}

int main(){

	que.size = 6;
	que.rear = -1;
	que.front = -1;
	que.body = malloc(sizeof(int)*que.size);

	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	push(70);
	pop();
//	printf("%d %d", que.rear, que.front);
	pop();
	pop();
	push(90);
	pop();
	pop();
	pop();
	print();
//	printf("%d", pop());
}

