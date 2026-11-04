
#include <stdio.h>

void incorrectSwap(int a, int b);
void correctSwap(int *a, int *b);
void analyzeOccupancy(int arr[], int size, int *total,
                      int *highest, int *lowest);

int main()
{
    int wardA = 45;
    int wardB = 30;

    int x = 45;
    int y = 30;

    int occupancy[7] = {35, 42, 38, 50, 45, 40, 48};

    int total, highest, lowest;

    printf("========== INCORRECT SWAP ==========\n");

    printf("Before: x = %d, y = %d\n", x, y);
    printf("Main Address of x: %p\n", (void *)&x);
    printf("Main Address of y: %p\n", (void *)&y);

    incorrectSwap(x, y);

    printf("After: x = %d, y = %d\n", x, y);

    printf("\n========== CORRECT SWAP ==========\n");

    printf("Before: Ward A = %d, Ward B = %d\n", wardA, wardB);
    printf("Main Address of Ward A: %p\n", (void *)&wardA);
    printf("Main Address of Ward B: %p\n", (void *)&wardB);

    correctSwap(&wardA, &wardB);

    printf("After: Ward A = %d, Ward B = %d\n", wardA, wardB);

    printf("\n========== WEEKLY ANALYSIS ==========\n");

    analyzeOccupancy(occupancy, 7, &total, &highest, &lowest);

    printf("Total Occupancy: %d\n", total);
    printf("Highest Occupancy: %d\n", highest);
    printf("Lowest Occupancy: %d\n", lowest);

    return 0;
}

void incorrectSwap(int a, int b)
{
    int temp;

    printf("Function Address of a: %p\n", (void *)&a);
    printf("Function Address of b: %p\n", (void *)&b);

    temp = a;
    a = b;
    b = temp;

    printf("Inside Function: a = %d, b = %d\n", a, b);
}

void correctSwap(int *a, int *b)
{
    int temp;

    printf("Function Address stored in a: %p\n", (void *)a);
    printf("Function Address stored in b: %p\n", (void *)b);

    temp = *a;
    *a = *b;
    *b = temp;
}

void analyzeOccupancy(int arr[], int size, int *total,
                      int *highest, int *lowest)
{
    *total = 0;
    *highest = arr[0];
    *lowest = arr[0];

    printf("Function Address of total pointer: %p\n", (void *)total);
    printf("Function Address of highest pointer: %p\n", (void *)highest);
    printf("Function Address of lowest pointer: %p\n", (void *)lowest);

    for (int i = 0; i < size; i++)
    {
        *total += arr[i];

        if (arr[i] > *highest)
            *highest = arr[i];

        if (arr[i] < *lowest)
            *lowest = arr[i];
    }
}
