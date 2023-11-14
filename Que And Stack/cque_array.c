/* Circular Que is also known as 'Ring Buffer'.
 *
 * Full : (rear + 1) % MAX == front
 * Empty: rear == front
 *
 * Inserting: rear = (rear + 1) % MAX
 * Deleting : front = (front + 1) % MAX
 * */

#include <stdio.h>
#include <stdlib.h>

#define MAX 6

int rear = -1;
int front = -1;

int que[MAX];

void push(int data)
{
	if ((rear + 1) % MAX == front)
	{
		fprintf(stderr, "Que Overflow.\n");
	}
	else
	{
		rear = (rear + 1) % MAX;
		que[rear] = data;
	}
}

int pop()
{
	if (rear == front)
	{
		fprintf(stderr, "Que Underflow.\n");
		return -1;
	}
	else
	{
		int x = front;
		front = (front + 1) % MAX;

		return que[x];
	}
}

void print()
{
	printf("\n");

	for (int i = front; i != rear + 1; i++)
	{
		printf("%d ", que[i]);
	}

	printf("\n");
}

int main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	push(70);
	pop();
	pop();
	pop();
	push(90);
	pop();
	pop();
	pop();
	print();
}
