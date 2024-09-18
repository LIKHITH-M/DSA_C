#include <stdio.h>

// Define a structure to represent a term in a polynomial using typedef
typedef struct {
    int coefficient;
    int exponent;
} Term;

// Function to add two polynomials
void addPolynomials(Term A[], int sizeA, Term B[], int sizeB, Term result[], int *resultSize) {
    int i = 0, j = 0, k = 0;

    // Add terms based on the exponents
    while (i < sizeA && j < sizeB) {
        if (A[i].exponent == B[j].exponent) {
            result[k].coefficient = A[i].coefficient + B[j].coefficient;
            result[k].exponent = A[i].exponent;
            i++;
            j++;
        } else if (A[i].exponent > B[j].exponent) {
            result[k] = A[i];
            i++;
        } else {
            result[k] = B[j];
            j++;
        }
        k++;
    }

    // If there are remaining terms in A
    while (i < sizeA) {
        result[k] = A[i];
        i++;
        k++;
    }

    // If there are remaining terms in B
    while (j < sizeB) {
        result[k] = B[j];
        j++;
        k++;
    }

    *resultSize = k;  // Update the result size
}

// Function to print a polynomial
void printPolynomial(Term poly[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%dx^%d", poly[i].coefficient, poly[i].exponent);
        if (i != size - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    // Define the first polynomial A(x) = 3x^2 + 5x + 6
    Term A[] = {{3, 2}, {5, 1}, {6, 0}};
    int sizeA = 3;

    // Define the second polynomial B(x) = 2x^2 + 4x + 1
    Term B[] = {{2, 2}, {4, 1}, {1, 0}};
    int sizeB = 3;

    // Array to store the result of A + B
    Term result[10];
    int resultSize = 0;

    // Add the polynomials
    addPolynomials(A, sizeA, B, sizeB, result, &resultSize);

    // Print the result
    printf("Resultant Polynomial: ");
    printPolynomial(result, resultSize);

    return 0;
}
