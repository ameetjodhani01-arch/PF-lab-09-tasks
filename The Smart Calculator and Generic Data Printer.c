
#include <stdio.h>

void printData(void *ptr, char type);

double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);

double calculate(double a, double b,
                 double (*operation)(double, double));

int main()
{
    int number = 25;
    float decimal = 15.75;
    char character = 'A';

    printf("========== GENERIC DATA PRINTER ==========\n");

    printData(&number, 'i');
    printData(&decimal, 'f');
    printData(&character, 'c');

    double (*operations[4])(double, double) = {
        add, subtract, multiply, divide
    };

    char *names[4] = {
        "Addition",
        "Subtraction",
        "Multiplication",
        "Division"
    };

    double num1, num2, result;
    int choice;

    printf("\n========== SMART CALCULATOR ==========\n");

    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");

    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    printf("Choose operation (1-4): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 4)
    {
        printf("Invalid menu choice!\n");
        return 0;
    }

    if (choice == 4 && num2 == 0)
    {
        printf("Error! Division by zero is not allowed.\n");
        return 0;
    }

    result = calculate(num1, num2, operations[choice - 1]);

    printf("\nOperation: %s\n", names[choice - 1]);
    printf("Result: %.2f\n", result);

    return 0;
}

void printData(void *ptr, char type)
{
    if (type == 'i')
        printf("Integer: %d\n", *(int *)ptr);

    else if (type == 'f')
        printf("Float: %.2f\n", *(float *)ptr);

    else if (type == 'c')
        printf("Character: %c\n", *(char *)ptr);

    else
        printf("Invalid data type!\n");
}

double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    if (b == 0)
        return 0;

    return a / b;
}

double calculate(double a, double b,
                 double (*operation)(double, double))
{
    return operation(a, b);
}
