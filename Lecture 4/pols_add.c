#include <stdio.h>
#include <stdlib.h>

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
    int deg1 = 5;
    int deg2 = 9;
    int max = deg1 < deg2 ? deg2 : deg1;

    int pol1[deg1], pol2[deg2];
    int pol3[max];

    for (int i = 0; i < deg1; i++)
    {
        pol1[i] = i;
    }
    for (int i = 0; i < deg2; i++)
    {
        pol2[i] = i;
    }
    print(pol1, deg1);
    print(pol2, deg2);

    int i = 0, j = 0, k = 0;

    while (i < deg1 && j < deg2)
    {
        pol3[k++] = pol1[i++] + pol2[j++];
    }
    while (i < deg1)
    {
        pol3[k++] = pol1[i++];
    }
    while (j < deg2)
    {
        pol3[k++] = pol2[j++];
    }

    print(pol3, k);
}
