#include <stdio.h>

int main() {
    int a, b, choice;

    do {
        printf("Enter two numbers: ");
        scanf("%d %d", &a, &b);

        printf("\n1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Addition is=%d\n", a + b);
                break;

            case 2:
                printf("Subtraction is=%d\n", a - b);
                break;

            case 3:
                printf("Multiplication is=%d\n", a * b);
                break;

            case 4:
                if (b == 0)
                    printf("Error: Division by zero is not allowed!\n");
                else
                    printf("Division is=%d\n", a / b);
                break;

            case 5:
                if (b == 0)
                    printf("Error: Modulus by zero is not allowed!\n");
                else
                    printf("Modulus is=%d\n", a % b);
                break;

            case 6:
                break;

            default:
                printf("Invalid choice!\n");
        }
        printf("\n");
    } while (choice != 6);

    printf("Thank you for using the calculator.\n");
    return 0;
}
