#include <stdio.h>

int main(int argc, char **argv)
{
    int degree = 5;
    int pol[degree];

    for (int i = 0; i < degree; i++)
    {
        scanf("%d", &pol[i]);
    }

    for (int i = degree - 1; i >= 0; i--)
    {
        int val = pol[i];
        printf("%c %dX^%d ", val < 0 ? '\0' : '+', val, i);
    }
}
