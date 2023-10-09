#include <stdio.h>
#include <stdlib.h>

struct Nord
{
    int number;
    char grade;
};

// Pass as value
void testCase1(struct Nord comeHere)
{
    printf("Number: %d\n", comeHere.number);

    printf("Grade: %c\n", comeHere.grade);
}

// Pass by refrence
void testCase2(struct Nord *comeHere)
{
    printf("Number: %d\n", comeHere->number);

    printf("Grade: %c\n", comeHere->grade);
}

// Pass by address
void testCase3(struct Nord **comeHere)
{
    printf("Number: %d\n", (*comeHere)->number);

    printf("Grade: %c\n", (*comeHere)->grade);
}

// Pass as array
void testCase4(struct Nord comeHere[])
{
    printf("Number: %d\n", comeHere[0].number);

    printf("Grade: %c\n", comeHere[0].grade);
}

int main(int argc, char **argv)
{
    struct Nord pepe;
    struct Nord *temp = &pepe; // For pass by address
    struct Nord temp1[1];      // For pass as array

    pepe.number = 89921;
    pepe.grade = 'O';

    testCase1(pepe);
    testCase2(&pepe);
    testCase3(&temp);

    temp1[0] = pepe;

    testCase4(temp1);
    return 0;
}
