#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sortArray(int *, int);
void swapItems(int *, int *);
void traverseArray(int *, int);

int main(int argc, char **argv)
{
    int *myArray;
    int size;

    srand(time(NULL)); // Generates new random numbers instead of pseudo randoms.

    printf("[+] Enter sizeof array: ");
    scanf("%d", &size);

    myArray = calloc(size, sizeof(int));

    for (int i = 0; i < size; i++)
    {
        myArray[i] = rand() % 101; // Assigning random value to the array.
    }

    printf("\n- Before sorting: \n");
    traverseArray(myArray, size);

    sortArray(myArray, size);

    printf("- After sorting: \n");
    traverseArray(myArray, size);
}

void swapItems(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortArray(int myArray[], int size)
{
    int MIN;
    for (int i = 0; i < size - 1; i++)
    {
        MIN = i; // Assuming first one to be minimum first.
        for (int j = i + 1; j < size; j++)
        {
            if (myArray[j] < myArray[MIN]) // If new smaller item found
            {
                MIN = j;
            }
            swapItems(&myArray[i], &myArray[j]);
        }
    }
}

void traverseArray(int myArray[], int size)
{
    printf("\033[1;32m[\033[0m"); // Escape sequences are for colors :p
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", myArray[i]);
    }
    printf("\033[1;32m]\033[0m\n");
}
