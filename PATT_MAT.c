#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char pat[50];
    char txt[100];
    int flag = 1;

    // Getting input from the user
    printf("Enter the text: ");
    scanf("%s", txt);
    printf("Enter the pattern: ");
    scanf("%s", pat);

    // Calculating the lengths of the pattern and the text
    int lenpat = strlen(pat);  // Correct function to get length of pattern
    int lentxt = strlen(txt);  // Correct function to get length of text

    // Naive Pattern Matching Algorithm
    for (int i = 0; i <= lentxt - lenpat; i++) {  // Iterate up to 'lentxt - lenpat + 1'
        int j;

        // For current index 'i', check for pattern match
        for (j = 0; j < lenpat; j++) {
            if (txt[i + j] != pat[j]) {  // Compare pattern with text at the current position
                break;  // Break if any character doesn't match
            }
        }

        // If pattern matches
        if (j == lenpat) {  // If 'j' reached 'lenpat', it means pattern is found
            printf("Pattern found at index %d\n", i);
            flag = 0;  // Set flag to indicate that pattern was found
        }
    }

    // If pattern is not found in the entire text
    if (flag) {
        printf("Pattern not found.\n");
    }

    return 0;
}
