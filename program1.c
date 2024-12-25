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
#include <string.h>

void stringmatch(const char *str, const char *pat, const char *rep, char *ans) {
    int i = 0, j = 0, c = 0, k;

    while (str[c] != '\0') {
        if (str[c] == pat[i]) {
            i++;
            if (pat[i] == '\0') { // Complete match found
                for (k = 0; rep[k] != '\0'; k++) {
                    ans[j++] = rep[k];
                }
                i = 0; // Reset pattern index
                c++;   // Move to the next character in the string
            } else {
                c++;
            }
        } else {
            // No match, reset pattern index and add current character to ans
            if (i > 0) {
                int l;
                for (l = 0; l < i; l++) {
                    ans[j++] = pat[l];
                }
                i = 0; // Reset pattern index
            }
            ans[j++] = str[c++];
        }
    }

    // Add remaining unmatched part of the pattern
    while (i > 0 && pat[--i] != '\0') {
        ans[j++] = pat[i];
    }

    ans[j] = '\0'; // Null terminate the resultant string
}

int main() {
    const char str[] = "ababcabc";
    const char pat[] = "abc";
    const char rep[] = "123";
    char ans[100]; // Make sure ans is large enough to hold the result

    stringmatch(str, pat, rep, ans);
    printf("Result: %s\n", ans);

    return 0;
}
