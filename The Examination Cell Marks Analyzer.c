
#include <stdio.h>

int calculateTotal(int arr[], int size);
double calculateAverage(int arr[], int size);
int findHighest(int arr[], int size);
int findLowest(int arr[], int size);
int countPass(int arr[], int size, int passMarks);
int countTopScorers(int arr[], int size);
void applyBonus(int arr[], int size, int bonus);
void displayReport(int arr[], int size, int passMarks);

int main()
{
    int marks[10];
    int passMarks, bonus;

    for (int i = 0; i < 10; i++)
    {
        do
        {
            printf("Enter marks of Student %d: ", i + 1);
            scanf("%d", &marks[i]);

            if (marks[i] < 0 || marks[i] > 100)
                printf("Invalid marks! Enter between 0 and 100.\n");

        } while (marks[i] < 0 || marks[i] > 100);
    }

    printf("\nEnter passing marks: ");
    scanf("%d", &passMarks);

    while (passMarks < 0 || passMarks > 100)
    {
        printf("Enter valid passing marks (0-100): ");
        scanf("%d", &passMarks);
    }

    printf("\n========== ORIGINAL REPORT ==========\n");
    displayReport(marks, 10, passMarks);

    printf("\nEnter bonus marks: ");
    scanf("%d", &bonus);

    while (bonus < 0)
    {
        printf("Bonus cannot be negative. Enter again: ");
        scanf("%d", &bonus);
    }

    applyBonus(marks, 10, bonus);

    printf("\n========== MODERATED REPORT ==========\n");
    displayReport(marks, 10, passMarks);

    return 0;
}

int calculateTotal(int arr[], int size)
{
    int total = 0;

    for (int i = 0; i < size; i++)
        total += arr[i];

    return total;
}

double calculateAverage(int arr[], int size)
{
    return (double)calculateTotal(arr, size) / size;
}

int findHighest(int arr[], int size)
{
    int highest = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > highest)
            highest = arr[i];
    }

    return highest;
}

int findLowest(int arr[], int size)
{
    int lowest = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < lowest)
            lowest = arr[i];
    }

    return lowest;
}

int countPass(int arr[], int size, int passMarks)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= passMarks)
            count++;
    }

    return count;
}

int countTopScorers(int arr[], int size)
{
    int highest = findHighest(arr, size);
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == highest)
            count++;
    }

    return count;
}

void applyBonus(int arr[], int size, int bonus)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] += bonus;

        if (arr[i] > 100)
            arr[i] = 100;
    }
}

void displayReport(int arr[], int size, int passMarks)
{
    printf("Total Marks: %d\n", calculateTotal(arr, size));
    printf("Average Marks: %.2f\n", calculateAverage(arr, size));
    printf("Highest Marks: %d\n", findHighest(arr, size));
    printf("Lowest Marks: %d\n", findLowest(arr, size));
    printf("Students Passed: %d\n", countPass(arr, size, passMarks));
    printf("Top Scorers: %d\n", countTopScorers(arr, size));
}
