#include <stdio.h>

union test
{
    int a;
    int b;
    int c;
} myFirstUnionEver;

int main(int argc, char **argv)
{
    myFirstUnionEver.a = 5;
    printf("%d\n", myFirstUnionEver.a);
    myFirstUnionEver.a = 55;
    printf("%d\n", myFirstUnionEver.b);
    myFirstUnionEver.a = 555;
    printf("%d\n", myFirstUnionEver.c);
    printf("%d  %d  %d\n", myFirstUnionEver.a, myFirstUnionEver.b, myFirstUnionEver.c);

    printf("Sizeof union: %d", sizeof(myFirstUnionEver)); // Probably 4
}
