#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int size;
    int r;
    int f;
    int *q;
} Que;

void enque(Que *que, int item)
{
    if ((que->r + 1) % que->size == que->f)
    {
        printf("Queue overflow.");
    }
    else
    {
        que->r = (que->r + 1) % que->size;
        que->q[que->r] = item;
    }
}

int deque(Que *que)
{
    if (que->r == que->f)
    {
        printf("Queue is full.");
        return -1;
    }
    else
    {
        que->f = (que->f + 1) % que->size;
        return que->q[que->f];
    }
}

int main(int argc, char **argv)
{
}
