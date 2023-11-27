#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int que[MAX];
int count = 0;

void push(int data){
	int i = 0;
	if(count == 0) {
		que[count++] = data; 
	} else {
		for(i = count - 1; i >=0; i--){
			if(data > que[i]) {
				que[i+1] = que[i];
			} else {
				break;
			}
		}
		que[i+1] = data;
		count++;
	}
}

int del(){
	if(count != 0) {
		return que[--count];
	} else {
		fprintf(stderr, "Que Underflow\n");
	}
}
int main(){
	push(10);
	push(20);
	int i = del();
	printf("%d", i);
}
