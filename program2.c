// 2) Design, Develop and Implement a menu driven Program in C for the following 
// operations on STACK of Integers (Array Implementation of Stack with maximum size 
// MAX)
// a. Push an Element on to Stack
// b. Pop an Element from Stack
// c. Demonstrate how Stack can be used to check Palindrome
// d. Demonstrate Overflow and Underflow situations on Stack
// e. Display the status of Stack
// f. Exit
// Support the program with appropriate functions for each of the above operations


#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int stack[MAX], item, ch, top = -1; // Removed status variable

void push(int stack[], int item) {
    if (top == (MAX - 1))
        printf("\nOverflow\n");
    else
        stack[++top] = item; // Increment top and assign item
}

int pop() {
    if (top == -1) {
        printf("\nUnderflow\n");
        return -1; // Return a specific value for underflow
    }
    return stack[top--]; // Return item and decrement top
}

int is_palindrome(int stack[], int size) {
    // Check if the stack is a palindrome
    for (int i = 0; i < size / 2; i++) {
        if (stack[i] != stack[size - i - 1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}

void display(int stack[]) {
    if (top == -1) {
        printf("\nStack is empty\n");
    } else {
        printf("Stack contents:\n");
        for (int i = top; i >= 0; i--) {
            printf("|%d|\n", stack[i]);
        }
    }
}

int main() {
    while (1) { // Loop indefinitely until break
        printf("\n1. Push\t2. Pop\t3. Palindrome\t4. Display\t5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the item: ");
                scanf("%d", &item);
                push(stack, item);
                break;
            case 2:
                item = pop();
                if (item != -1) {
                    printf("Popped value = %d\n", item);
                }
                break;
            case 3:
                if (top == -1) {
                    printf("Stack is empty, not a palindrome\n");
                } else {
                    if (is_palindrome(stack, top + 1)) {
                        printf("Palindrome\n");
                    } else {
                        printf("Not palindrome\n");
                    }
                }
                break;
            case 4:
                display(stack);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    return 0; // Return success
}
