#include <stdio.h>
#include <stdlib.h>

// Incomplete

void print(int pol[], int degree)
{
    printf("\n");
    for (int i = degree - 1; i >= 0; i--)
    {
        int val = pol[i];
        printf("%c %dX^%d ", val < 0 ? '\0' : '+', val, i);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    int coff1 = 5;
    int coff2 = 7;
    int k = 0;

    int a[coff1][2], b[coff2][2];

    for (int i = 0; i < coff1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            a[i][j] = rand() % 6;
        }
    }

    for (int i = 0; i < coff2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            b[i][j] = rand() % 6;
        }
    }

    for (int i = 0; i < (coff1 < coff2 ? coff1 : coff2); i++)
    {
        for (int j = 0; j < (coff1 > coff2 ? coff1 : coff2); j++)
        {
            if (a[i][1] == b[j][1])
            {
                k++;
                break;
            }
        }
    }

    int c[k];
}
