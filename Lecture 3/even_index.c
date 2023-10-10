#include <stdio.h>
#include <stdlib.h>

void sort(int a[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }

        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void sortAtEvenIndex(int a[], int size)
{
    for (int i = 0; i < size - 1; i += 2)
    {
        int min = i;
        for (int j = i + 2; j < size; j += 2)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }

        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void printLeaders(int a[], int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (a[i] <= a[j])
                break;
        }

        if (j == size)
        {
            printf("%d ", a[i]);
        }
    }
}

void print(int a[], int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    int size = 10;
    int a[size];

    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 10;
    }

    print(a, size);
    sort(a, size);
    print(a, size);
    int x[] = {16, 17, 4, 3, 5, 2};
    printLeaders(x, 6);
}
