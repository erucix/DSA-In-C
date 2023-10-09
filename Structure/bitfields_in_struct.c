#include <stdio.h>

struct bitField
{
    unsigned int a : 3;
} test;

struct notBitField
{
    unsigned int a;
    unsigned int b;
};

// To remember easily use this concept.
// Struct size <= 32 means 4 bit size.
// Similarly for every increase in struct's size by 32 means add 4 bit.

// Eg: 63 bit field = 4 + 4 + 4
// Eg: 33 bit field = 4 + 4

// Further to note that:
// Bit field is not allowed for pointers. Eg a[10] : 5

int main(int argc, char **argv)
{
    printf("Sizeof bitField: %d \n", sizeof(struct bitField));
    printf("Sizeof notBitField: %d", sizeof(struct notBitField));

    test.a = 8;

    printf("\ntest.a: %d", test.a);
}
