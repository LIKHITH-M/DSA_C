#include <stdio.h>

// Function to perform the Tower of Hanoi move
void towerOfHanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
      printf("Move disk 1 from rod %c to rod %c\n", source, target);
        return;
    }

    // Move n-1 disks from source to auxiliary, using target as temporary storage
    towerOfHanoi(n - 1, source, auxiliary, target);

    // Move the nth disk from source to target
    printf("Move disk %d from rod %c to rod %c\n", n, source, target);

    // Move the n-1 disks from auxiliary to target, using source as temporary storage
    towerOfHanoi(n - 1, auxiliary, target, source);
}

int main() {
    int n; // Number of disks

    // Ask the user for the number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Call the function to solve Tower of Hanoi
    printf("The sequence of moves involved in solving the Tower of Hanoi are:\n");
    towerOfHanoi(n, 'S', 'T', 'A'); // A, B, C are names of rods

    return 0;
}
