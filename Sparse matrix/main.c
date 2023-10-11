#include <stdio.h>
#include <stdlib.h>

void usingArray()
{
    int sparse[3][2] = {{2, 0}, {0, 5}, {0, 0}};
    int nonZero = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (sparse[i][j] != 0)
            {
                nonZero++;
            }
        }
    }

    int newSparse[nonZero + 1][3];
    newSparse[0][0] = 3;
    newSparse[0][1] = 2;
    newSparse[0][2] = nonZero;
    int k = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (sparse[i][j] != 0)
            {
                newSparse[k][0] = i;
                newSparse[k][1] = j;
                newSparse[k][2] = sparse[i][j];
                k++;
            }
        }
    }
    printf("R | C | N\n");
    printf("---------\n");
    for (int i = 0; i <= nonZero; i++)
    {
        printf("%d   %d   %d\n", newSparse[i][0], newSparse[i][1], newSparse[i][2]);
    }
}

typedef struct Node
{
    int x;
    int y;
    int z;
    struct Node *next;
} Node;

void createNode(Node **head, int x, int y, int z)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->z = z;

    Node *temp = *head;

    if (temp != NULL)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        newNode->next = NULL;
        temp->next = newNode;
    }
    else
    {
        *head = newNode;
        newNode->next = NULL;
    }
}

void usingLinkedList()
{
    Node *head = NULL;

    int sparse[3][2] = {{2, 0}, {0, 5}, {0, 0}};
    int nonZero = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (sparse[i][j] != 0)
            {
                nonZero++;
            }
        }
    }

    createNode(&head, 3, 2, nonZero);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (sparse[i][j] != 0)
            {
                createNode(&head, i, j, sparse[i][j]);
            }
        }
    }

    Node *temp = head;

    printf("\n\nR | C | N\n");
    printf("---------\n");

    while (temp != NULL)
    {
        printf("%d   %d   %d\n", temp->x, temp->y, temp->z);
        temp = temp->next;
    }
}

int main(int argc, char **argv)
{
    usingArray();
    usingLinkedList();
}
