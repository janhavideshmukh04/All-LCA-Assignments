#include <stdio.h>

// Function declarations
long long factorial_iterative(int n);
long long factorial_recursive(int n);

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d (Without Recursion) = %lld\n", num, factorial_iterative(num));
        printf("Factorial of %d (With Recursion)    = %lld\n", num, factorial_recursive(num));
    }

    return 0;
}

// Function without recursion (Iterative approach)
long long factorial_iterative(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function with recursion (Recursive approach)
long long factorial_recursive(int n) {
    if (n == 0 || n == 1) {
        return 1; // Base case
    }
    return n * factorial_recursive(n - 1); // Recursive call
}
