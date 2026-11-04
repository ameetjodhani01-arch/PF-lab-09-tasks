
#include <stdio.h>

double getSubtotal(double, int, double, int);
double calculateDiscount(double);
double calculateFinalBill(double, double);
int comparePrices(double, double);
void displayReceipt(double, int, double, int, double, double, double);
int validateInput(double, int, double, int);

int main()
{
    double price1, price2;
    int quantity1, quantity2;

    printf("Enter price of Item 1: ");
    scanf("%lf", &price1);

    printf("Enter quantity of Item 1: ");
    scanf("%d", &quantity1);

    printf("Enter price of Item 2: ");
    scanf("%lf", &price2);

    printf("Enter quantity of Item 2: ");
    scanf("%d", &quantity2);

    if (!validateInput(price1, quantity1, price2, quantity2))
    {
        printf("Invalid input! Prices and quantities cannot be negative.\n");
        return 0;
    }

    double subtotal = getSubtotal(price1, quantity1, price2, quantity2);
    double discount = calculateDiscount(subtotal);
    double finalBill = calculateFinalBill(subtotal, discount);

    displayReceipt(price1, quantity1, price2, quantity2,
                   subtotal, discount, finalBill);

    int result = comparePrices(price1, price2);

    if (result == 1)
        printf("Item 1 has the higher unit price.\n");
    else if (result == 2)
        printf("Item 2 has the higher unit price.\n");
    else
        printf("Both items have equal unit prices.\n");

    return 0;
}

double getSubtotal(double p1, int q1, double p2, int q2)
{
    return (p1 * q1) + (p2 * q2);
}

double calculateDiscount(double total)
{
    if (total > 1000)
        return total * 0.10;

    return 0;
}

double calculateFinalBill(double total, double discount)
{
    return total - discount;
}

int comparePrices(double p1, double p2)
{
    if (p1 > p2)
        return 1;
    else if (p2 > p1)
        return 2;

    return 0;
}

int validateInput(double p1, int q1, double p2, int q2)
{
    return p1 >= 0 && p2 >= 0 && q1 >= 0 && q2 >= 0;
}

void displayReceipt(double p1, int q1, double p2, int q2,
                    double subtotal, double discount, double finalBill)
{
    printf("\n========== CUSTOMER RECEIPT ==========\n");

    printf("Item 1 Price: Rs. %.2f\n", p1);
    printf("Item 1 Quantity: %d\n", q1);
    printf("Item 1 Total: Rs. %.2f\n", p1 * q1);

    printf("\nItem 2 Price: Rs. %.2f\n", p2);
    printf("Item 2 Quantity: %d\n", q2);
    printf("Item 2 Total: Rs. %.2f\n", p2 * q2);

    printf("\nSubtotal: Rs. %.2f\n", subtotal);
    printf("Discount: Rs. %.2f\n", discount);
    printf("Final Bill: Rs. %.2f\n", finalBill);

    printf("======================================\n");
}
