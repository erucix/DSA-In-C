#include <stdio.h>
#include <stdlib.h>

void traverse(int array[], int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("]");
}

void insert(int array[], int pos, int value, int *size)
{
    for (int i = *size; i > pos; i--)
    {
        array[i] = array[i + 1];
    }

    array[pos] = value;
    *size++;
}

void delete(int array[], int pos, int *size)
{
    for (int i = pos; i < size; i++)
    {
        array[i] = array[i + 1];
    }

    *size--;
}

void search(int array[], int data, int size)
{
    for (int i = 0; i, size; i++)
    {
        if (data == array[i])
        {
            printf("\n - %d found at index %d\n", data, i);
        }
    }
}

void sort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = array[i];
            }
        }
    }
}

void merge(int array[], int *size, int newArray[], int newSize)
{
    for (int i = size, k = 0; k < newSize; i++, k++)
    {
        array[i] = newArray[k];
    }

    *size += newSize;
}

void reverse(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
    }
}
int main()
{
    system("clear");
    int method = 7, menu;

    char methods[7][10] = {
        "Traverse",
        "Insert",
        "Delete",
        "Search",
        "Sort",
        "Merge",
        "Reverse"};

    for (int i = 0; i < method; i++)
    {
        printf(" %d. %s\n", i + 1, methods[i]);
    }

    scanf("%d", &menu);

    if (menu == 1)
    {
    }
    main();
}
