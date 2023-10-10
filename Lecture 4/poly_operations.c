#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int size1 = 4, size2 = 5;

    int a[4] = {1, -2, 3, 0};

    int b[5] = {-2, 5, 0, 4, 0};

    int r[size1 + size2];

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            r[i + j] += a[i] * b[j];
        }
    }

    for (int i = 0; i < size1 + size2; i++)
    {
        printf("%d  ", r[i]);
    }
}
