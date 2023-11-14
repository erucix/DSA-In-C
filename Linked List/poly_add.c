#include <stdio.h>
#include <stdlib.h>

void traverse(Node **head)
{
    Node *temp = *head;
    printf("\n");
    while (temp != NULL)
    {
        printf("[%d, %d]-->", temp->coff, temp->pow);
        temp = temp->next;
    }
    printf("\n");
}

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

void insert(Node **head, int pos, int data, int pow)
{
    Node *tempNode = *head;
    Node *newNode = malloc(sizeof(Node));
    newNode->coff = data;
    newNode->pow = pow;

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

static void add(Node **first, Node **second)
{
    Node *f = *first, *s = *second;
    Node *sum = NULL;

    while (f && s)
    {
        Node *newNode = malloc(sizeof(Node));

        if (f->pow > s->pow)
        {
            newNode->coff = f->coff;
            newNode->pow = f->pow;
            f = f->next;
        }
        else if (f->pow < s->pow)
        {
            newNode->coff = s->coff;
            newNode->pow = s->pow;
            s = s->next;
        }
        else
        {
            newNode->coff = s->coff + f->coff;
            newNode->pow = s->pow;
            s = s->next;
            f = f->next;
        }

        newNode->next = NULL;

        if (sum == NULL)
        {
            sum = newNode;
        }
        else
        {
            sum->next = newNode;
        }
    }

    while (f || s)
    {

        Node *newNode = malloc(sizeof(Node));

        if (f)
        {
            newNode->coff = f->coff;
            newNode->pow = f->pow;
            f = f->next;
            newNode->next = NULL;
        }

        if (s)
        {
            newNode->coff = s->coff;
            newNode->pow = s->pow;
            s = s->next;

            newNode->next = NULL;
        }

        if (sum == NULL)
        {
            sum = newNode;
        }
        else
        {
            sum->next = newNode;
        }
    }
    &heaf
        traverse(&sum);
}

void main()
{
    Node *head = NULL;
    Node *shead = NULL;
    Node *sum = NULL;
    int i = 0, j = 7;
    int l = 0, k = 7;

    insert(&head, length(&head), ++i, --j);
    insert(&head, length(&head), ++i, --j);
    insert(&head, length(&head), ++i, --j);
    insert(&head, length(&head), ++i, --j);
    insert(&head, length(&head), ++i, --j);
    insert(&head, length(&head), ++i, --j);

    insert(&head, length(&shead), ++l, --k);
    insert(&head, length(&shead), ++l, --k);
    insert(&head, length(&shead), ++l, --k);
    insert(&head, length(&shead), ++l, --k);
    insert(&head, length(&shead), ++l, --k);
    insert(&head, length(&shead), ++l, --k);

    add(&head, &shead);

    traverse(&sum);
}
