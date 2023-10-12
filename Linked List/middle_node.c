#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int length(Node **head)
{
    int len = 0;
    Node *temp = *head;

    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void traverse(Node **head)
{
    Node *tempNode = *head;
    printf("\n");

    while (tempNode != NULL)
    {
        printf("%d --> ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

void insert(Node **head, int pos, int data)
{
    Node *tempNode = *head;
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;

    if (pos == 0)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else if (pos == length(head))
    {
        while (tempNode->next != NULL)
        {
            tempNode = tempNode->next;
        }
        tempNode->next = newNode;
        newNode->next = NULL;
    }
    else
    {
        for (int i = 0; i < pos - 1 && tempNode != NULL; i++)
        {
            tempNode = tempNode->next;
        }

        newNode->next = tempNode->next;
        tempNode->next = newNode;
    }
}

void randomize(Node **head, int limit)
{
    for (int i = 0; i < limit; i++)
    {
        insert(head, i, i);
    }
}

void middle(Node **head)
{
    Node *slow = *head;
    Node *fast = *head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    printf("\nMiddle: %d\n", slow->data);
}

void middle1(Node **shead)
{
    Node *head = *shead;
    Node *temp = *shead;
    int c = 0;

    while (head != NULL)
    {
        if (c % 2 == 1)
        {
            temp = temp->next;
        }
        c++;
        head = head->next;
    }

    printf("\nMiddle: %d\n", temp->data);
}

void reverse(Node **head)
{
    Node *curr = *head;
    Node *prev = NULL;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
}

void rotate(Node **head, int step)
{
    Node *temp = *head;

    for (int i = 0; i < step && temp != NULL; i++)
    {
        temp = temp->next;
    }
}

int main(int argc, char **argv)
{
    Node *head = NULL;

    randomize(&head, 10);

    traverse(&head);

    reverse(&head);

    traverse(&head);
}
