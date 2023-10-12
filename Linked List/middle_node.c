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
        insert(head, i, rand() % 10);
    }

    traverse(head);
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

    int k = 1;

    while (k < step && temp != NULL)
    {
        temp = temp->next;
        k++;
    }

    Node *kthNode = temp;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = *head;
    *head = kthNode->next;
    kthNode->next = NULL;
}

void nthFromEnd(Node **head, int pos)
{
    Node *temp = *head;
    int len = length(head);

    for (int i = 0; i < len - pos; i++)
    {
        temp = temp->next;
    }

    printf("\n%dth data is %d\n", pos, temp->data);
}

void deleteLast(Node **head)
{
    Node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *freeTemp = temp->next;
    temp->next = NULL;
    free(freeTemp);
}

void deleteMiddle(Node **head)
{
    Node *slow = *head;
    Node *fast = *head;
    Node *prev = NULL;

    while (slow != NULL && fast != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;

    free(slow);
}

void deleteGivenNodes(Node **head, int pos, int num)
{
    Node *temp = *head;

    int counter = 0;

    while (temp != NULL && counter < pos)
    {
        temp = temp->next;
        counter++;
    }

    Node *nthNode = temp;
    Node *prev = NULL;
    int counter1 = 0;

    while (temp != NULL && counter1 <= num)
    {
        prev = temp;
        temp = temp->next;
        counter1++;
    }

    nthNode->next = temp->next;
}

void sort(Node **head)
{
    Node *p1 = *head;

    for (int i = 0; i <= length(head); i++)
    {
        p1 = *head;
        for (int j = 0; j < length(head) - i - 1; j++)
        {
            if (p1->data > p1->next->data)
            {
                int temp = p1->data;
                p1->data = p1->next->data;
                p1->next->data = temp;
            }
            p1 = p1->next;
        }
    }
}

void deleteDuplicates(Node **head)
{
    Node *temp = *head;
    Node *next = NULL;

    while (temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            next = temp->next->next;
            free(temp->next);
            temp->next = next;
        }
        else
        {
            temp = temp->next;
        }
    }
}

int main(int argc, char **argv)
{
    Node *head = NULL;

    randomize(&head, 10);
    sort(&head);
    traverse(&head);

    deleteDuplicates(&head);

    traverse(&head);
}
