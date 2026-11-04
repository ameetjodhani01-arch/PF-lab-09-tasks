
#include <stdio.h>
#include <stddef.h>

int main()
{
    int readings[7];
    int *ptr = readings;
    int *linkedMeter = NULL;
    int threshold;
    int total = 0;
    int highest;
    int highestDay = 1;

    printf("Enter electricity readings for 7 days:\n");

    for (int i = 0; i < 7; i++)
    {
        printf("Day %d: ", i + 1);
        scanf("%d", ptr + i);
    }

    printf("\n========== MEMORY INSPECTION ==========\n");

    for (int i = 0; i < 7; i++)
    {
        printf("Day %d: %d\n", i + 1, *(ptr + i));
        printf("Address: %p\n", (void *)(ptr + i));

        total += *(ptr + i);
    }

    printf("\n========== ADDRESS DISTANCES ==========\n");

    for (int i = 0; i < 6; i++)
    {
        ptrdiff_t distance = (char *)(ptr + i + 1) - (char *)(ptr + i);

        printf("Day %d to Day %d: %td bytes\n",
               i + 1, i + 2, distance);
    }

    printf("\nEach address is %zu bytes apart because an integer occupies %zu bytes on this system.\n",
           sizeof(int), sizeof(int));

    highest = *ptr;

    for (int i = 1; i < 7; i++)
    {
        if (*(ptr + i) > highest)
        {
            highest = *(ptr + i);
            highestDay = i + 1;
        }
    }

    printf("\nWeekly Total: %d\n", total);
    printf("Highest Consumption: %d\n", highest);
    printf("Highest Consumption Day: %d\n", highestDay);

    printf("\nEnter peak tariff threshold: ");
    scanf("%d", &threshold);

    for (int i = 0; i < 7; i++)
    {
        if (*(ptr + i) > threshold)
            *(ptr + i) *= 2;
    }

    printf("\n========== UPDATED READINGS ==========\n");

    total = 0;

    for (int i = 0; i < 7; i++)
    {
        printf("Day %d: %d\n", i + 1, *(ptr + i));
        total += *(ptr + i);
    }

    printf("Updated Weekly Total: %d\n", total);

    printf("\n========== LINKED METER ==========\n");

    if (linkedMeter == NULL)
        printf("Linked meter is currently unassigned.\n");

    linkedMeter = ptr + 2;

    if (linkedMeter != NULL)
        printf("Linked meter assigned to Day 3: %d\n", *linkedMeter);

    linkedMeter = NULL;

    if (linkedMeter == NULL)
        printf("Linked meter has been safely unassigned.\n");

    return 0;
}
