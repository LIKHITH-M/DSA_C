#include <stdio.h>

// Function to return the nth Fibonacci number using recursion
int fibonacci(int n) {
    if (n <= 1) {
        return n; // Base cases: F(0) = 0, F(1) = 1
    }
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive call
}

int main() {
    int n;

    // Ask the user for the number of terms
    printf("Enter the number of terms for the Fibonacci series: ");
    scanf("%d", &n);

    // Print the Fibonacci series up to n terms
    printf("Fibonacci series up to %d terms: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n"); // Print a new line

    return 0;
}
