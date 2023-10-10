#include <stdio.h>
#include <stdlib.h>
#include <time.h> // For random value i:e `srand(time(NULL))`

#define insertValue 10 // Insert 10 to array
#define position 2     // Insert insertValue at index 2

int *myArray;
int init = 5;

int main(int argc, char **argv)
{
    srand(time(NULL));

    myArray = malloc(init * sizeof(int));

    for (int i = 0; i < init; i++)
    {
        myArray[i] = rand() % 10;
    }

    // Using realloc to securely increase array size
    // and prevent from possible unwritable memory errors.

    myArray = realloc(myArray, (init + 1) * sizeof(int));

    for (int i = init; i > position; i--)
    {
        myArray[i] = myArray[i - 1];
    }

    myArray[position] = insertValue;

    for (int i = 0; i < init; i++)
    {
        printf("%d  ", myArray[i]);
    }
}
