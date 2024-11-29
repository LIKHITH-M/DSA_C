// 6) Design, Develop and implement C program for the following operations on doubly 
// linked list.
// a. Create doubly linked list of N nodes with integer data by adding each node at the front.
// b. Delete the node of a given data if it is found, otherwise display appropriate message.
// c. Insert a node to the left of the node whose key value is read as input.
// d. Display the contents of the list.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next, *prev;
} NODE;

NODE* getnode() {
    NODE *x = (NODE*)malloc(sizeof(NODE));
    printf("\nEnter Data: ");
    scanf("%d", &x->data);
    x->next = x->prev = NULL;
    return x;
}

NODE* insert_front(NODE *first) {
    NODE *temp = getnode();
    if (first) first->prev = temp;
    temp->next = first;
    return temp;
}

NODE* insert_left(NODE *first) {
    if (!first) return getnode();
    int data;
    printf("Enter the data to insert left of: ");
    scanf("%d", &data);
    NODE *temp = getnode(), *cur = first;
    while (cur && cur->data != data) cur = cur->next;
    if (cur) {
        temp->next = cur;
        temp->prev = cur->prev;
        if (cur->prev) cur->prev->next = temp;
        else first = temp;
        cur->prev = temp;
    } else {
        printf("Node not found.\n");
        free(temp);
    }
    return first;
}

NODE* delete_node(NODE *first) {
    if (!first) {
        printf("List is empty.\n");
        return NULL;
    }
    int data;
    printf("Enter data to delete: ");
    scanf("%d", &data);
    NODE *cur = first;
    while (cur && cur->data != data) cur = cur->next;
    if (cur) {
        if (cur->prev) cur->prev->next = cur->next;
        else first = cur->next;
        if (cur->next) cur->next->prev = cur->prev;
        free(cur);
    } else {
        printf("Node not found.\n");
    }
    return first;
}

void display(NODE *first) {
    if (!first) printf("List is empty.\n");
    else for (NODE *cur = first; cur; cur = cur->next) printf("-->%d", cur->data);
    printf("\n");
}

int main() {
    NODE *first = NULL;
    int ch;
    while (1) {
        printf("\n1.InsertFront 2.InsertLeft 3.Delete 4.Display 5.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: first = insert_front(first); break;
            case 2: first = insert_left(first); break;
            case 3: first = delete_node(first); break;
            case 4: display(first); break;
            case 5: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
