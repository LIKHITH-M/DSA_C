// 1) Design, Develop and Implement a Program in C for the following operations on 
// Strings
// a. Read a main String (STR), a Pattern String (PAT) and a Replace String (REP)
// b. Perform Pattern Matching Operation: Find and Replace all occurrences of PAT in STR 
// with REP if PAT exists in STR. Report suitable messages in case PAT does not exist in STR.
// c. Pattern Matching Algorithm: Brute Force
// d. Support the program with functions for each of the above operations. Don't use Built in functions
// e. Check the following test cases.
// Test Case 1: STR = “VVCE MYSURU”, PAT=” MYSURU”, REP=” KARNATAKA”, OUTPUT=” 
// VVCE KARNATAKA”
// Test Case 2: STR = “COMPUTER SCIENCE”, PAT=” COMPUTER”, REP=” BASIC”, 
// OUTPUT=” BASIC SCIENCE”

#include <stdio.h>
#include <stdlib.h>

char str[100], pat[50], rep[50], ans[100];
int i, j, c, m, k, flag = 0;

void stringmatch() {
    i = m = c = j = 0; // Initialize all variables
    while (str[c] != '\0') {
        if (str[c] == pat[i]) {
            i++;
            m++;
            if (pat[i] == '\0') {
                flag = 1;
                for (k = 0; rep[k] != '\0'; k++, j++)
                    ans[j] = rep[k];
                i = 0; // Reset pattern index
                c = m; // Update the current index
            }
        } else {
            ans[j] = str[c]; // Store the current character in ans
            j++;
            c++;
            m = c; // Move to the next character in str
        }
    }
    ans[j] = '\0'; // Null terminate the resultant string
}

int main() {
    printf("Enter a main string \n");
    fgets(str, sizeof(str), stdin); // Use fgets instead of gets
    printf("Enter a pattern string \n");
    fgets(pat, sizeof(pat), stdin); // Use fgets instead of gets
    printf("Enter a replace string \n");
    fgets(rep, sizeof(rep), stdin); // Use fgets instead of gets

    stringmatch();
    if (flag == 1)
        printf("The resultant string is\n%s", ans);
    else
        printf("Pattern string NOT found\n");

    return 0; // Return an integer from main
}
