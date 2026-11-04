
#include <stdio.h>

void displayHall1(int (*ptr)[4]);
void displayHall2(int *rows[], int sizes[]);
int countVacantHall1(int (*ptr)[4]);
int countVacantHall2(int *rows[], int sizes[]);
void bookSeat(int *rows[], int sizes[]);

int main()
{
    int hall1[3][4] = {
        {1, 0, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 1}
    };

    int row1[] = {1, 0, 1};
    int row2[] = {0, 1, 0, 0, 1};
    int row3[] = {1, 0, 0, 1, 0, 1, 0};

    int *hall2[] = {row1, row2, row3};
    int sizes[] = {3, 5, 7};

    printf("========== HALL 1 ==========\n");

    displayHall1(hall1);

    printf("Vacant Seats in Hall 1: %d\n",
           countVacantHall1(hall1));

    printf("\n========== HALL 2 ==========\n");

    displayHall2(hall2, sizes);

    printf("Vacant Seats in Hall 2: %d\n",
           countVacantHall2(hall2, sizes));

    bookSeat(hall2, sizes);

    printf("\n========== UPDATED HALL 2 ==========\n");

    displayHall2(hall2, sizes);

    printf("Updated Vacant Seats: %d\n",
           countVacantHall2(hall2, sizes));

    return 0;
}

void displayHall1(int (*ptr)[4])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (*(*(ptr + i) + j) == 1)
                printf("[B] ");
            else
                printf("[V] ");
        }

        printf("\n");
    }
}

void displayHall2(int *rows[], int sizes[])
{
    for (int i = 0; i < 3; i++)
    {
        printf("Row %d: ", i + 1);

        for (int j = 0; j < sizes[i]; j++)
        {
            if (*(*(rows + i) + j) == 1)
                printf("[B] ");
            else
                printf("[V] ");
        }

        printf("\n");
    }
}

int countVacantHall1(int (*ptr)[4])
{
    int count = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (*(*(ptr + i) + j) == 0)
                count++;
        }
    }

    return count;
}

int countVacantHall2(int *rows[], int sizes[])
{
    int count = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < sizes[i]; j++)
        {
            if (*(*(rows + i) + j) == 0)
                count++;
        }
    }

    return count;
}

void bookSeat(int *rows[], int sizes[])
{
    int row, seat;

    printf("\nEnter row number (1-3): ");
    scanf("%d", &row);

    if (row < 1 || row > 3)
    {
        printf("Invalid row number!\n");
        return;
    }

    printf("Enter seat number (1-%d): ", sizes[row - 1]);
    scanf("%d", &seat);

    if (seat < 1 || seat > sizes[row - 1])
    {
        printf("Invalid seat number!\n");
        return;
    }

    if (*(*(rows + row - 1) + seat - 1) == 1)
    {
        printf("This seat is already booked!\n");
        return;
    }

    *(*(rows + row - 1) + seat - 1) = 1;

    printf("Seat successfully booked!\n");
}
