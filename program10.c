
/* 10. Given a File of N employee records with a set K of Keys(4-digit) which uniquely determine the 
 records in file F. Assume that file F is maintained in memory by a Hash Table(HT) of m memory 
 locations with L as the set of memory addresses (2-digit) of locations in HT. Let the keys in K and 
 addresses in L are Integers. Design and develop a Program in C that uses Hash function H: K →L as 
 H(K)=K mod m (remainder method), and implement hashing technique to map a given key K 
 to the address space L. Resolve the collision (if any) using linear probing. */



#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

#define SIZE 10 // Define the size of the hash table

// Structure to hold employee information
typedef struct { 
    int id; // Employee ID
    char name[20]; // Employee name
} EMPLOYEE; 

EMPLOYEE e[SIZE]; // Declare an array of EMPLOYEE structures for the hash table

// Function to initialize the hash table
void initialize_table() { 
    for(int i=0; i<SIZE; i++) { 
        e[i].id=0; // Set the ID of each employee to 0 to indicate it's empty
    } 
} 

// Function to insert an employee into the hash table
void insert_table() { 
    int i, id, index, hvalue; 
    char name[26]; // Temporary storage for employee name
    printf("Enter the employee id and name: "); 
    scanf("%d %s", &id, name); // Read employee ID and name from user input

    hvalue = id % SIZE; // Calculate the hash value using modulus
    for(i = 0; i < SIZE; i++) { 
        index = (hvalue + i) % SIZE; // Linear probing for collision resolution
        if(e[index].id == 0) { // Check if the slot is empty
            e[index].id = id; // Insert the employee ID
            strcpy(e[index].name, name); // Copy the name into the hash table
            break; 
        } 
    } 
    if(i == SIZE) { // If the table is full
        printf("Hash table full\n"); 
    } 
} 

// Function to display the contents of the hash table
void display_table() { 
    printf("H\t Id\t Name\n"); // Print table headers
    for(int i = 0; i < SIZE; i++) { 
        printf("%d\t %d\t %s\n", i, e[i].id, e[i].name); // Print each entry in the hash table
    } 
} 

// Main function to run the program
void main() { 
    int ch = 0; // Initialize choice variable
    initialize_table(); // Initialize the hash table  

    // Loop for user interaction until exit
    while(ch < 4) { 
        printf("1:Insert\t 2:Display\t 3:Exit\n"); 
        printf("Enter the choice:"); 
        scanf("%d", &ch); // Read user choice
        switch(ch) { 
            case 1: 
                insert_table(); // Call function to insert employee
                break; 
            case 2: 
                display_table(); // Call function to display employees
                break; 
            case 3: 
                exit(0); // Exit the program
                break; 
            default: // Handle invalid choice
                printf("Enter valid choice\n"); 
                break; 
        } 
    } 
}
