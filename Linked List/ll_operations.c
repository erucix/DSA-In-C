#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void traverseList(Node **head)
{
    Node *temp = *head;

    printf("HEAD-->");

    while (temp != NULL)
    {
        printf(" [%d] -->", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int count(Node **head)
{
    Node *temp = *head;
    int index = 0;

    while (temp != NULL)
    {
        index++;
        temp = temp->next;
    }

    return index;
}

void insert(Node **head, int position, int data)
{
    Node *tempNode = *head;

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (position == 0)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else if (position == count(head))
    {
        while (tempNode->next != NULL)
        {
            tempNode = tempNode->next;
        }

        newNode->next = NULL;
        tempNode->next = newNode;
    }
    else
    {
        int index = 0;

        while (index++ < position - 1 && tempNode->next != NULL)
        {
            tempNode = tempNode->next;
        }

        newNode->next = tempNode->next;
        tempNode->next = newNode;
    }
}

void reverse(Node **head)
{
    Node *current = *head;
    Node *next = NULL;
    Node *prev = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void sort(Node **head)
{
    Node *temp1 = *head;
    int swapped = 0;

    for (int i = 0; i <= count(head); i++)
    {
        temp1 = *head;
        for (int j = 0; j < count(head) - i - 1; j++)
        {
            if (temp1->data > temp1->next->data)
            {
                int temp = temp1->data;
                temp1->data = temp1->next->data;
                temp1->next->data = temp;
                swapped = 1;
            }
            temp1 = temp1->next;
        }
    }
}

int main()
{
    Node *head = NULL;

    for (int i = 0; i < 10; i++)
    {
        insert(&head, i, rand() % 10);
    }

    traverseList(&head);
    reverse(&head);
    traverseList(&head);
    sort(&head);
    traverseList(&head);
}
