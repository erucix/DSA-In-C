#include <stdio.h>

int main()
{
    int size1 = 5, size2 = 4;
    int size3 = size1 + size2;

    int a1[5] = {1, 4, 6, 9, 11};
    int a2[4] = {0, 3, 6, 8};
    int a3[size3];

    int i = 0, j = 0, k = 0;

    // [2,4,5,6,7,8]
    while (i < size1 && j < size2)
    {
        if (a1[i] < a2[j])
        {
            a3[k++] = a1[i++];
        }
        else
        {
            a3[k++] = a2[j++];
        }
    }

    while (i < size1)
    {
        a3[k++] = a1[i++];
    }
    while (j < size2)
    {
        a3[k++] = a2[j++];
    }

    for (int i = 0; i < size3; i++)
    {
        printf("%d  ", a3[i]);
    }
}
