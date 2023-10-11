#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 4, y = 4;
    int a[x][y], b[x][y];
    int k = 0, l = 0;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d %d", &a[i][j], &b[i][j]);

            if (a[i][j] != 0)
                k++;
            if (b[i][j] != 0)
                l++;
        }
    }

    int sa[k][3], sb[l][3];
    int sk = 1, sl = 1;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (a[i][j] != 0)
            {
                sa[sk][0] = i;
                sa[sk][1] = j;
                sa[sk][2] = a[i][j];
                sk++;
            }
            if (b[i][j] != 0)
            {
                sb[sl][1] = j;
                sb[sl][0] = i;
                sb[sl][2] = b[i][j];
                sl++;
            }
        }
    }

    for (int i = 0; i < sk; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d   ", sa[i][j]);
        }
        printf("\n");
    }
}
