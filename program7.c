// 7. Design, Develop and Implement a menu driven Program in C for the following 
// operations on Binary Search Tree (BST) of Integers.
// a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
// b. Traverse the BST in In-order, preorder, post-Order
// c. Search the BST for a given element (KEY) and report the appropriate message
// d. Display the height of binary trees
// e. Exit

#include<stdio.h>
#include<stdlib.h>

// Defining the structure for each node in the BST
typedef struct node
{
    int item; // Stores the value of the node
    struct node *llink, *rlink; // Left and right links (children)
} NODE;

// Function to allocate memory for a new node and read its value
NODE* getnode()
{
    NODE* x;
    x = (NODE*)malloc(sizeof(NODE)); // Dynamically allocate memory for a new node
    scanf("%d", &x->item); // Input the value for the node
    x->llink = x->rlink = NULL; // Initialize left and right child pointers as NULL
    return x; // Return the newly created node
}

// Function to insert a new node into the BST
NODE* insert(NODE* root)
{
    NODE *temp, *cur, *prev;
    temp = getnode(); // Create a new node

    // If the tree is empty, make the new node the root
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        prev = NULL;
        cur = root;

        // Traverse the tree to find the appropriate position for the new node
        while (cur != NULL)
        {
            prev = cur;
            if (temp->item > cur->item) // If new node's value is greater, move to the right
                cur = cur->rlink;
            else // If smaller, move to the left
                cur = cur->llink;
        }

        // Insert the new node either to the left or right of the parent
        if (temp->item > prev->item)
            prev->rlink = temp;
        else
            prev->llink = temp;
    }
    return root; // Return the root of the updated tree
}

// Function to search for an item in the BST
void search(NODE *root)
{
    int item;
    NODE *cur = root;

    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }

    printf("Enter the item to be searched: ");
    scanf("%d", &item); // Input the item to search for

    // Traverse the tree to search for the item
    while (cur != NULL)
    {
        if (cur->item == item) // If the item is found
        {
            printf("Item found\n");
            return;
        }

        // Move to the right or left subtree based on comparison
        if (cur->item < item)
            cur = cur->rlink;
        else
            cur = cur->llink;
    }

    // If traversal finishes and item not found
    printf("Item Not found\n");
}

// Function for Preorder Traversal (Root -> Left -> Right)
void preorder(NODE *root)
{
    if (root == NULL) return; // Base condition
    printf("%d\t", root->item); // Print the current node's value
    preorder(root->llink); // Traverse the left subtree
    preorder(root->rlink); // Traverse the right subtree
}

// Function for Postorder Traversal (Left -> Right -> Root)
void postorder(NODE *root)
{
    if (root == NULL) return; // Base condition
    postorder(root->llink); // Traverse the left subtree
    postorder(root->rlink); // Traverse the right subtree
    printf("%d\t", root->item); // Print the current node's value
}

// Function for Inorder Traversal (Left -> Root -> Right)
void inorder(NODE *root)
{
    if (root == NULL) return; // Base condition
    inorder(root->llink); // Traverse the left subtree
    printf("%d\t", root->item); // Print the current node's value
    inorder(root->rlink); // Traverse the right subtree
}

// Function to calculate the height of the tree
int find_height(NODE *root)
{
    if (root == NULL)
    {
        return -1; // Base case: empty tree has height -1
    }
    else
    {
        // Recursively find the height of the left and right subtrees
        int lheight = find_height(root->llink);
        int rheight = find_height(root->rlink);

        // The height of the current node is the maximum of the two subtree heights, plus one
        if (lheight > rheight)
            return (lheight + 1);
        else 
            return (rheight + 1);
    }
}

// Main function with menu-driven program
int main()
{
    int ch, i, n, ht;
    NODE *root = NULL; // Initialize root as NULL

    while (1)
    {
        // Display the menu and get the user's choice
        printf("\n 1.Create\t 2.Traverse\t 3.Search\t 4.Height\t 5.Exit\n"); 
        printf("Enter your choice: ");
        scanf("%d", &ch);

        // Perform operation based on user choice
        switch (ch)
        {
            case 1: // Creating the BST
                printf("Enter the number of nodes to be inserted: ");
                scanf("%d", &n); // Input the number of nodes to insert
                printf("Enter the tree nodes\n");
                for (i = 0; i < n; i++)
                {
                    root = insert(root); // Insert nodes one by one
                }
                break;

            case 2: // Traversing the BST in Preorder, Inorder, Postorder
                printf("\n Preorder Traversal: ");
                preorder(root);
                printf("\n Inorder Traversal: ");
                inorder(root);
                printf("\n Postorder Traversal: ");
                postorder(root);
                break;

            case 3: // Searching for an element in the BST
                search(root);
                break;

            case 4: // Calculating and displaying the height of the tree
                ht = find_height(root);
                printf("\n Height of the tree = %d\n", ht);
                break;

            case 5: // Exit the program
                exit(0);

            default: // Handle invalid input
                printf("\n Invalid Choice\n");
                break; 
        }
    }
    return 0;
}
