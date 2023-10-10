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
}
