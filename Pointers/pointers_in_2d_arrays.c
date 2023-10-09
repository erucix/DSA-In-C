#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define x 4 // No. of rows
#define y 6 // No. co columns

void testCase1() // Creating 2d arrays using malloc
{
    srand(time(NULL));

    int **anArray = malloc(x * sizeof(int *));
    for (int i = 0; i < x; i++)
    {
        anArray[i] = malloc(y * sizeof(int));
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            anArray[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d  ", anArray[i][j]);
        }
        printf("\n");
    }
}

void testCase2() // Using 1d array as 2d
{
    srand(time(NULL));

    int anArray[x * y];

    for (int i = 0; i < x * y; i++)
    {
        anArray[i] = rand() % 10;
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d  ", anArray[i * y + j]);
        }
        printf("\n");
    }
}

void testCase3() // Purely based in DMA and pointers
{
    srand(time(NULL));

    int **anArray = malloc(x * sizeof(int *));

    for (int i = 0; i < x; i++)
    {
        anArray[i] = malloc(y * sizeof(int));
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            anArray[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d  ", *(*(anArray + i) + j));
        }
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    testCase1();
    testCase2();
    testCase3();
}
