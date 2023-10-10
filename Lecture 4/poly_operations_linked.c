#include <stdio.h>
#include <stdlib.h>

typedef struct poly
{
    int coff;
    int pwr;
    struct poly *next;
} Poly;

int length(Poly **head)
{
    int len = 0;
    Poly *temp = *head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void traverse(Poly **head)
{
    Poly *temp = *head;
    printf("\nHEAD-->");

    while (temp != NULL)
    {
        printf("[%d, %d]-->", temp->coff, temp->pwr);
        temp = temp->next;
    }

    printf("NULL\n");
}

void insertPoly(Poly **head, int pos, int coff, int pwr)
{
    Poly *newPoly = malloc(sizeof(Poly));
    newPoly->coff = coff;
    newPoly->pwr = pwr;

    if (pos == 0)
    {
        newPoly->next = *head;
        *head = newPoly;
    }
    else if (pos == length(head))
    {
        Poly *temp = *head;

        while (temp->next != NULL && (temp = temp->next))
            ;

        newPoly->next = NULL;
        temp->next = newPoly;
    }
    else
    {
        Poly *temp = *head;

        for (int i = 0; i < pos - 2; i++, temp = temp->next)
            ;
        newPoly->next = temp->next;
        temp->next = newPoly;
    }
}

int main()
{
    int size1 = 5, size2 = 6;

    Poly *head1 = NULL;
    Poly *head2 = NULL;

    for (int i = 0, j = size1; i < size1; i++, j--)
    {
        insertPoly(&head1, i, j, i);
    }
    for (int i = 0, j = size2; i < size2; i++, j--)
    {
        insertPoly(&head2, i, j, i);
    }

    traverse(&head1);
    traverse(&head2);
}
