#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FIELD_SIZE 1000
#define LOWERLIMIT 1
#define UPPERLIMIT 99

//  function prototypes
void arrayInitialisation(int array[], int fieldLength);
void arrayOutput(int array[], int fieldLength);
void swap(int *x, int *y);
void sort(int array[], int fieldLength);
void quicksortLoop(int array[], int lowerLimit, int upperLimit);
int partition(int array[], int lowerLimit, int upperLimit);

int main()
{
    int field[FIELD_SIZE];

    arrayInitialisation(field, FIELD_SIZE);
    printf("\nField before sorting:\n");
    arrayOutput(field, FIELD_SIZE);

    clock_t startTime = clock();
    sort(field, FIELD_SIZE);
    clock_t duration = clock() - startTime;
    printf("Sorted %d elements in %ld ms", FIELD_SIZE, duration);
    printf("\nSorted Field:\n");
    arrayOutput(field, FIELD_SIZE);

    return 0;
}

// sets every array element to a value between lowerBound and upperBound
void arrayInitialisation(int array[], int fieldLength)
{
    srand(time(NULL));
    for (int i = 0; i < fieldLength; ++i)
        array[i] = LONG_LONG_MAX + rand() % (UPPERLIMIT - LOWERLIMIT) + 1;
}

void arrayOutput(int array[], int fieldLength)
{
    printf("\n");
    for (int i = 0; i < fieldLength; ++i)
    {
        printf("|  %d  |", array[i]);
    }
    printf("\n\n");
}

void swap(int *a, int *b)
{
    int cache = *a;
    *a = *b;
    *b = cache;
}

// indirect for easier use
void sort(int array[], int fieldLength)
{
    quicksortLoop(array, 0, fieldLength - 1);
}

void quicksortLoop(int array[], int lowerLimit, int upperLimit)
{
    if (lowerLimit < upperLimit)
    {
        int pivotElementIndex = partition(array, lowerLimit, upperLimit);
        quicksortLoop(array, lowerLimit, pivotElementIndex - 1);
        quicksortLoop(array, pivotElementIndex + 1, upperLimit);
    }
}

int partition(int array[], int lowerLimit, int upperLimit)
{
    int pivotValue = array[upperLimit];
    int i = lowerLimit;

    for (int k = lowerLimit; k < upperLimit; ++k){
        if (array[k] <= pivotValue){
            swap(&array[i], &array[k]);
            i++;
        }
    }

    swap(&array[i], &array[upperLimit]);
    return i;
}