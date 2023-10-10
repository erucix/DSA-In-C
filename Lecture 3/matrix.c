#include <stdio.h>
#include <stdlib.h>

void sum(int a[][3], int b[][3], int x)
{
    int c[x][3];

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d  ", c[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void multiply()
{
    int a = 3, b = 2;
    int mA[a][b], mB[b][a], mC[a][a];

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            mA[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < a; j++)
        {
            mA[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            mC[i][j] = 0;
            for (int k = 0; k < b; k++)
            {
                mC[i][j] += mA[i][k] * mB[k][j];
            }
        }
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            printf("%d  ", mC[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

int main(int argc, char **argv)
{
    int a[3][3] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
    int b[3][3] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};

    sum(a, b, 3);
    multiply();
}
