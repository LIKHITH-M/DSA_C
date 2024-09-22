#include <stdio.h>

// Custom function to calculate the length of a string
int string_length(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Custom function to copy one string into another
void string_copy(char *destination, char *source) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';  // Null-terminate the copied string
}

// Custom function to concatenate two strings
void string_concat(char *destination, char *source) {
    int i = 0, j = 0;

    // Find the end of the destination string
    while (destination[i] != '\0') {
        i++;
    }

    // Append the source string
    while (source[j] != '\0') {
        destination[i] = source[j];
        i++;
        j++;
    }
    destination[i] = '\0';  // Null-terminate the concatenated string
}

// Custom function to compare two strings
int string_compare(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

// Custom function to reverse a string
void string_reverse(char *str) {
    int length = string_length(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

// Custom function to convert a string to uppercase
void string_to_upper(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}

// Custom function to convert a string to lowercase
void string_to_lower(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

// Custom function to find the first occurrence of a character in a string
char* string_find_char(char *str, char c) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            return &str[i];
        }
    }
    return NULL;  // Return NULL if character is not found
}

// Custom function to find the first occurrence of a substring in a string
char* string_find_substring(char *str, char *substr) {
    int i, j;
    int strLen = string_length(str);
    int substrLen = string_length(substr);

    for (i = 0; i <= strLen - substrLen; i++) {
        for (j = 0; j < substrLen; j++) {
            if (str[i + j] != substr[j]) {
                break;
            }
        }
        if (j == substrLen) {
            return &str[i];
        }
    }
    return NULL;  // Return NULL if substring is not found
}

int main() {
    char str1[100] = "Hello, World!";
    char str2[100] = "Programming in C";
    char str3[100];
    char str4[100] = "World";

    printf("str1 : %s\nstr2 : %s\nstr2 : %s\nstr4 : %s\n",str1,str2,str3,str4);
    
    // 1. string_length - Get length of a string
    printf("Length of str1: %d\n", string_length(str1));

    // 2. string_copy - Copy one string into another
    string_copy(str3, str1);
    printf("After copying, str3: %s\n", str3);

    // 3. string_concat - Concatenate two strings
    string_concat(str3, " is fun!");
    printf("After concatenation, str3: %s\n", str3);

    // 4. string_compare - Compare two strings
    int result = string_compare(str1, str2);
    if (result == 0)
        printf("str1 and str2 are equal.\n");
    else if (result > 0)
        printf("str1 is greater than str2.\n");
    else
        printf("str1 is less than str2.\n");

    // 5. string_find_char - Find a character in a string
    char *ch = string_find_char(str1, 'o');
    if (ch != NULL)
        printf("First occurrence of 'o' in str1: %s\n", ch);
    else
        printf("'o' not found in str1.\n");

    // 6. string_find_substring - Find a substring in a string
    char *sub = string_find_substring(str1, str4);
    if (sub != NULL)
        printf("Substring '%s' found in str1: %s\n", str4, sub);
    else
        printf("Substring '%s' not found in str1.\n", str4);

    // 7. string_reverse - Reverse a string
    string_reverse(str1);
    printf("After reversing, str1: %s\n", str1);

    // Reversing back to original for further operations
    string_reverse(str1);

    // 8. string_to_upper - Convert string to uppercase
    string_to_upper(str1);
    printf("After converting to uppercase, str1: %s\n", str1);

    // 9. string_to_lower - Convert string to lowercase
    string_to_lower(str1);
    printf("After converting to lowercase, str1: %s\n", str1);

    return 0;
}
