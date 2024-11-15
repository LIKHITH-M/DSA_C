// 6) Design, Develop and implement C program for the following operations on doubly 
// linked list.
// a. Create doubly linked list of N nodes with integer data by adding each node at the front.
// b. Delete the node of a given data if it is found, otherwise display appropriate message.
// c. Insert a node to the left of the node whose key value is read as input.
// d. Display the contents of the list.


#include <stdio.h>
#include<stdlib.h>

// Define a structure for the node of the doubly linked list
typedef struct student
{
    int data;
    struct student *next, *prev;  // Pointers to the next and previous nodes
}NODE;

// Function to allocate memory for a new node and initialize it
NODE* getnode( )
{
    NODE *x;
    x=(NODE*)malloc(sizeof(NODE));  // Allocate memory for the new node
    printf("\n Enter Data of Node to be Inserted: ");
    scanf("%d",&x->data);  // Input the data for the new node
    x->next=x->prev=NULL;  // Initialize next and prev pointers as NULL
    return x;
}

// Function to insert a new node at the front of the doubly linked list
NODE* insert_front(NODE* first)
{
    NODE *temp;
    if(first==NULL)  // If the list is empty, insert the first node
    {
        temp=getnode();
        first=temp;
    }
    else
    {
        temp=getnode();  // Create a new node
        temp->next=first;  // Point new node's next to the first node
        first->prev=temp;  // Update first node's previous pointer
        first=temp;  // Make the new node the first node
    }
    return first;  // Return the updated list
}

// Function to insert a new node to the left of a given node
NODE* insert_left(NODE* first)
{
    NODE *temp, *cur, *pre;
    int data;
    if(first==NULL)  // If the list is empty, just insert the first node
    {
        temp=getnode();
        first=temp;
    }
    else
    {
        printf("Enter the node data to which left part new node to be inserted: ");
        scanf("%d",&data);
        temp=getnode();  // Create a new node
        cur=first;
        while(cur->data != data && cur != NULL)  // Traverse the list to find the node with the given data
        {
            pre=cur;
            cur=cur->next;
        }
if (cur == NULL) {
    printf("Node with data %d not found.\n", data);
    return first;
}
else{
        pre->next=temp;  // Link previous node's next to the new node
        temp->prev=pre;  // Update new node's previous pointer
        temp->next=cur;  // Link new node's next to the current node
        cur->prev=temp;  // Update current node's previous pointer
    }}
    return first;  // Return the updated list
}

// Function to delete a node with the given data
NODE* delete_node(NODE* first)
{
    NODE *cur;
    int data;
    cur=first;
    printf("Enter the data of the NODE to be deleted: ");
    scanf("%d",&data);
    if(first==NULL)  // If the list is empty, display message
    {
        printf("\n List is empty\n");
    }
    else if(first->data==data)  // If the node to be deleted is the first node
    {
        first=first->next;  // Update first node to the next node
        free(cur);  // Free the memory of the deleted node
    }
    else
    {
        while(cur!=NULL)  // Traverse the list to find the node with the given data
        {
            if(cur->data==data)
                break;
            cur=cur->next;
        }
        if(cur!=NULL)  // If the node with the given data is found
        {
            if(cur->next!=NULL)  // If it's not the last node
            {
                (cur->next)->prev=cur->prev;  // Update next node's previous pointer
                (cur->prev)->next=cur->next;  // Update previous node's next pointer
                free(cur);  // Free the memory of the deleted node
            }
            else  // If it's the last node
            {
                (cur->prev)->next=NULL;  // Set previous node's next pointer to NULL
                free(cur);  // Free the memory of the deleted node
            }
        }
        else
        {
            printf("No such node is present in the list\n");  // Node with given data not found
        }
    }
    return first;  // Return the updated list
}

// Function to display the contents of the doubly linked list
NODE* display(NODE* first)
{
    NODE *cur;
    if(first == NULL)  // If the list is empty, display message
        printf("No nodes present\n");
    else
    {
        cur=first;
        while(cur!=NULL)  // Traverse the list and print each node's data
        {
            printf("-->%d", cur->data);
            cur = cur->next;
        }
    }
    return first;  // Return the list
}

int main()
{
    NODE *first;
    first=NULL;
    int ch;
    while(1)
    {
        printf("\n1.InsertFront\t 2. InsertLeft\t 3.Delete\t 4.Display\t 5.exit\n");
        printf("Enter Your Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:first=insert_front(first);  // Call insert_front function
            break;
            case 2:first=insert_left(first);  // Call insert_left function
            break;
            case 3:first=delete_node(first);  // Call delete_node function
            break;
            case 4:first=display(first);  // Call display function
            break;
            case 5:exit(0);  // Exit the program
            break;
            default: printf("\n Invalid choice\n");  // Handle invalid input
            break;
        }
    }
    return 0;
}
