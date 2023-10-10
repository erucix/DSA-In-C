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
    if (*size >= pos)
    {
        for (int i = *size; i > pos; i--)
        {
            array[i] = array[i - 1]; // Shift elements to the right
        }

        array[pos] = value;
        (*size)++;
    }
    else
    {
        // Handle the case where pos is out of bounds or invalid
        printf("Invalid position for insertion.\n");
    }
}

void delete(int array[], int pos, int *size)
{
    for (int i = pos; i < *size; i++)
    {
        array[i] = array[i + 1];
    }

    (*size)--;
}

void search(int array[], int data, int size)
{
    for (int i = 0; i < size; i++)
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
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int array[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        int MIN = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[MIN] > array[j])
            {
                MIN = j;
            }
        }
        int temp = array[i];
        array[i] = array[MIN];
        array[MIN] = temp;
    }
}

void merge(int array[], int *size, int newArray[], int newSize)
{
    for (int i = *size, k = 0; k < newSize; i++, k++)
    {
        array[i] = newArray[k];
    }

    *size += newSize;
}

void reverse(int array[], int size)
{
    for (int i = 0, j = size - 1; i < size; i++, j--)
    {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void mergeTwo()
{
    int size1 = 5, size2 = 3;
    int newSize = size1 + size2;

    int a[5] = {13, 65, 23, 8, 1};
    int b[3] = {12, 34, 67};
    int c[newSize];

    for (int i = 0; i < size1; i++)
    {
        c[i] = a[i];
    }

    for (int i = size1, j = 0; i < newSize; i++, j++)
    {
        c[i] = b[j];
    }
    for (int i = 0; i < newSize; i++)
    {

        printf("%d  ", c[i]);
    }
}
int array[5] = {1, 5, 64, 4, 9};

int method = 7, menu, size = 5;
int main()
{
    mergeSorted();
    //     char methods[7][10] = {
    //         "Traverse",
    //         "Insert",
    //         "Delete",
    //         "Search",
    //         "Sort",
    //         "Merge",
    //         "Reverse"};

    //     printf("\n");

    //     for (int i = 0; i < method; i++)
    //     {
    //         printf(" %d. %s\n", i + 1, methods[i]);
    //     }

    //     scanf("%d", &menu);

    //     if (menu == 1)
    //     {
    //         traverse(array, size);
    //     }
    //     else if (menu == 2)
    //     {
    //         insert(array, 3, 2, &size); // Insert 3 at position 2
    //     }
    //     else if (menu == 3)
    //     {
    //         delete (array, 3, &size); // Delete element form position 3
    //     }
    //     else if (menu == 4)
    //     {
    //         search(array, 2, size); // Search for number "2"
    //     }
    //     else if (menu == 5)
    //     {
    //         sort(array, size);
    //     }
    //     else if (menu == 6)
    //     {
    //         int newSize = 5;
    //         int newArray[5] = {6, 7, 8, 9, 10};
    //         merge(array, &size, newArray, newSize);
    //     }
    //     else if (menu == 7)
    //     {
    //         reverse(array, size);
    //     }
    //     else
    //     {
    //         selectionSort(array, size);
    //     }
    //     main();
}
