// 5) Design, Develop and implement c program using singly linked list for the following 
// scenario
// a. There are two linked list A and B containing the following data: A: 3,7,10,15,16,09,22,17,32 
// and B: 16,02,09,13,37,08,10,01,28
// b. Create a linked list C that contains only those elements that are common in linked list A 
// and B
// c. Create a linked list D which contains all elements of A as well as B ensures that there is no 
// repetition of elements.
#include <stdio.h>
#include <stdlib.h> // Include standard library for memory allocation

// Define a structure for a node in the linked list
typedef struct node {
    int data;             // Integer data
    struct node *link;   // Pointer to the next node
} NODE;

// Global pointers for the linked lists
NODE *LLone, *LLtwo, *unionLL, *interLL; 

// Function to insert a new node at the beginning of the linked list
NODE* insert(NODE **first, int num) {
    NODE* newNode = (NODE*) malloc(sizeof(NODE)); // Allocate memory for a new node
    newNode->data = num;                           // Set the data of the new node
    newNode->link = *first;                        // Point new node to the current head of the list
    *first = newNode;                              // Update the head to point to the new node
    return *first;                                 // Return the new head of the list
}

// Function to search for a specific value in the linked list
int search(NODE *first, int num) {
    while (first != NULL) {                        // Traverse the list until the end
        if (first->data == num) {                 // If the data matches the number
            return 1;                             // Return 1 (true) if found
        }
        first = first->link;                       // Move to the next node
    }
    return 0;                                     // Return 0 (false) if not found
}

// Function to find the union of two linked lists
NODE* findunion(NODE *LLone, NODE *LLtwo) {
    unionLL = NULL;                               // Initialize the union list as empty
    NODE *temp = LLone;                           // Temporary pointer for traversing the first list

    // Traverse the first linked list and insert each element into the union list
    while(temp != NULL) {
        insert(&unionLL, temp->data);            // Insert current node's data into union list
        temp = temp->link;                        // Move to the next node
    }

    // Traverse the second linked list
    while(LLtwo != NULL) {
        // Check if the current element of LLtwo exists in LLone
        if(!search(LLone, LLtwo->data)) {        // If not found in the first list
            insert(&unionLL, LLtwo->data);       // Insert it into the union list
        }
        LLtwo = LLtwo->link;                      // Move to the next node
    }
    return unionLL;                              // Return the union linked list
}

// Function to find the intersection of two linked lists
NODE* intersection(NODE *LLone, NODE *LLtwo) {
    interLL = NULL;                               // Initialize the intersection list as empty

    // Traverse the first linked list
    while(LLone != NULL) {
        // Check if the current element of LLone exists in LLtwo
        if(search(LLtwo, LLone->data)) {         // If found in the second list
            insert(&interLL, LLone->data);       // Insert it into the intersection list
        }
        LLone = LLone->link;                      // Move to the next node
    }
    return interLL;                              // Return the intersection linked list
}

// Function to print the linked list
void printList(NODE *cur) {
    while (cur != NULL) {                        // Traverse the list until the end
        printf("-->%d", cur->data);              // Print the current node's data
        cur = cur->link;                         // Move to the next node
    }
}

// Main function to execute the program
void main() {
    int i, LLonecount, LLtwocount, temp;         // Variables for counts and temporary storage
    printf("\n Enter number of nodes in first Linked List: ");
    scanf("%d", &LLonecount);                    // Read the count of nodes for the first list
    printf("\n Enter data of first linked list: ");
    // Loop to read the data for the first linked list
    for(i = 0; i < LLonecount; i++) {
        scanf("%d", &temp);                      // Read each node's data
        insert(&LLone, temp);                    // Insert the data into the first linked list
    }
    printList(LLone);                            // Print the first linked list

    printf("\n Enter number of nodes in second Linked List: ");
    scanf("%d", &LLtwocount);                    // Read the count of nodes for the second list
    printf("\n Enter data of second linked list: ");
    // Loop to read the data for the second linked list
    for(i = 0; i < LLtwocount; i++) {
        scanf("%d", &temp);                      // Read each node's data
        insert(&LLtwo, temp);                    // Insert the data into the second linked list
    }
    printList(LLtwo);                            // Print the second linked list

    // Find and print the union and intersection of the two lists
    findunion(LLone, LLtwo);                     // Create the union linked list
    intersection(LLone, LLtwo);                  // Create the intersection linked list

    printf("\nUnion Linked List\n");
    printList(unionLL);                          // Print the union linked list

    printf("\nIntersection Linked List\n");
    printList(interLL);                          // Print the intersection linked list
}
