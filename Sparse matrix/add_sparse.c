#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 2, y = 2;
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

    int sa[k + 1][3], sb[l + 1][3];
    int sk = 1, sl = 1;

    sa[0][0] = x;
    sa[0][1] = y;
    sa[0][2] = k;
    sb[0][0] = x;
    sb[0][1] = y;
    sb[0][2] = l;

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
                sb[sl][0] = i;
                sb[sl][1] = j;
                sb[sl][2] = b[i][j];
                sl++;
            }
        }
    }

    printf("\nR | C | V\n");
    printf("-----------\n");
    for (int i = 0; i < sk; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d   ", sa[i][j]);
        }
        printf("\n");
    }

    printf("\nR | C | V\n");
    printf("-----------\n");
    for (int i = 0; i < sl; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d   ", sb[i][j]);
        }
        printf("\n");
    }

    int s[x][y];
    int k1, k2, k3;
    k1 = k2 = k3 = 1;

    while (k1 < k + 1 && k2 < l + 1)
    {
        if (sa[k1][0] < sb[k2][0] || (sa[k1][0] == sb[k2][0] && sa[k1][1] < sb[k2][1]))
        {
            s[k3][0] = sa[k1][0];
            s[k3][1] = sa[k1][1];
            s[k3][2] = sa[k1][2];
            k1++;
            k3++;
        }
        else if (sa[k1][0] > sb[k2][0] || (sa[k1][0] == sb[k2][0] && sa[k1][1] > sb[k2][1]))
        {
            s[k3][0] = sb[k2][0];
            s[k3][1] = sb[k2][1];
            s[k3][2] = sb[k2][2];
            k2++;
            k3++;
        }
        else if (sa[k1][0] == sb[k2][0] && sa[k1][1] == sb[k2][1])
        {
            s[k3][0] = sa[k1][0];
            s[k3][1] = sa[k1][1];
            s[k3][2] = sa[k1][2] + sb[k2][2];
            k3++;
            k2++;
            k1++;
        }
    }

    while (k1 <= k)
    {
        s[k3][0] = sa[k1][0];
        s[k3][1] = sa[k1][1];
        s[k3][2] = sa[k1][2];
        k1++;
        k3++;
    }

    while (k2 <= l)
    {
        s[k3][0] = sb[k2][0];
        s[k3][1] = sb[k2][1];
        s[k3][2] = sb[k2][2];
        k2++;
        k3++;
    }

    s[0][0] = x;
    s[0][1] = y;
    s[0][2] = k3 - 1;

    printf("\nR | C | V\n");
    printf("-----------\n");
    for (int i = 0; i < k3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d   ", s[i][j]);
        }
        printf("\n");
    }
}
