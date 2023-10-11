#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int sparse[3][2] = {{2, 0}, {0, 5}, {0, 0}};
    int nonZero = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (sparse[i][j] != 0)
            {
                nonZero++;
            }
        }
    }

    int newSparse[nonZero + 1][3];
    newSparse[0][0] = 3;
    newSparse[0][1] = 2;
    newSparse[0][2] = nonZero;
    int k = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (sparse[i][j] != 0)
            {
                newSparse[k][0] = i;
                newSparse[k][1] = j;
                newSparse[k][2] = sparse[i][j];
            }
        }
    }

    for (int i = 0; i < nonZero; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d   %d   %d\n", newSparse[i][0], newSparse[i][1], newSparse[i][2]);
        }
    }
}
