#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define FIELD_SIZE 100
#define UPPERLIMIT 100
#define LOWERLIMIT 0

void bubblesort(int array[]);
void swap(int *a, int *b);
void outputarray(int array[]);
void initArray(int array[]);

int main() {
    int field[FIELD_SIZE];
    initArray(field);
    printf("Unsorted Array:\n");
    outputarray(field);
    clock_t startTime = clock();
    bubblesort(field);
    clock_t duration = clock() - startTime;
    printf("\nSorted %d elements in  %ld ms.", FIELD_SIZE, duration);
    printf("\nSorted Array:\n");
    outputarray(field);

    return 0;
}

void initArray(int array[]) {
    for (int i = 0; i < FIELD_SIZE; i++) {
        array[i] = 0 + rand() % (UPPERLIMIT - LOWERLIMIT + 1);
    }
}

void bubblesort(int array[]) {
    for (int k = 0; k < FIELD_SIZE; k++) {
        for (int i = 0; i < FIELD_SIZE - 1 - k; i++) {
            if (array[i] > array[i + 1]) {
                swap(&array[i], &array[i + 1]);
            }
        }
    }
}

void swap(int *a, int *b) {
    int cache = *a;
    *a = *b;
    *b = cache;
}

void outputarray(int array[]) {
    printf("\n");
    for (int i = 0; i < FIELD_SIZE; i++) {
        printf("| %d ", array[i]);
    }
    printf("\n");
}
