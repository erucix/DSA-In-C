#include <stdio.h>

int main(int argc, char **argv)
{
    int a = 5;
    int b = 55;

    int *pa = &a;
    int *pb = &b;

    *pa = *pa + *pb; // 5 + 55 = 60
    *pb = *pa - *pb; // 60 - 5 = 55
    *pa = *pa - *pb; // 60 - 55 = 5

    // Also can be done by using XOR operators.

    // {
    //     *pa = *pa ^ *pb;
    //     *pb = *pa ^ *pb;
    //     *pa = *pa ^ *pb;
    // }

    printf("a: %d and b: %d", a, b);
}
