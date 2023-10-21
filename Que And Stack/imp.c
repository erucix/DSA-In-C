#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void push1(int data)
{
    if (top1 == MAX - 1)
    {
        printf("\nOverflow condition in stack1\n");
        exit(0); // Overflow condition
    }
    stack1[++top1] = data;
}

void push2(int data)
{
    if (top2 == MAX - 1)
    {
        printf("\nOverflow condition in stack2\n");
        exit(0); // Overflow condition
    }
    stack2[++top2] = data;
}

int pop1()
{
    if (top1 == -1)
    {
        printf("\nEmpty condition in stack1\n");
        exit(0); // Empty condition
    }
    return stack1[top1--];
}

int pop2()
{
    if (top2 == -1)
    {
        printf("\nEmpty condition in stack2\n");
        exit(0); // Empty condition
    }
    return stack2[top2--];
}

void enque(int data)
{
    push1(data);
}

int deque()
{
    int count1 = top1, count2 = top2;

    for (int i = 0; i <= count1; i++)
    {
        push2(pop1());
    }

    int x = pop2();

    for (int i = 0; i <= count2; i++)
    {
        push1(pop2());
    }

    return x;
}

int main(int argc, char **argv)
{
    enque(55);
}
