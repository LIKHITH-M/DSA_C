// 9) Design, Develop and Implement a Program in C for the following operations on 
// Graph (G) of Cities 
// a. Create a Graph of N cities using Adjacency Matrix. 
// b. Print all the nodes reachable from a given starting node in a digraph using the DFS / BFS 
// method 

//DFS

#include <stdio.h>

int stack[10];          // Stack for DFS traversal
int top = -1;           // Initialize top of stack to -1 (empty stack)
int adj[10][10];        // Adjacency matrix to represent the graph
int vis[10] = {0};      // Array to keep track of visited nodes

void main() 
{ 
    int n, s, u, v, i, j; 
    int found = 0;           // Flag to indicate if an unvisited adjacent node is found

    printf("\n Enter the number of vertices: "); 
    scanf("%d", &n);         // Read the number of vertices

    printf("\n Enter the adjacency matrix:\n"); 
    for (i = 0; i < n; i++) 
    { 
        for (j = 0; j < n; j++) 
        { 
            scanf("%d", &adj[i][j]);   // Read adjacency matrix elements
        } 
    } 

    printf("\n Enter the source vertex: "); 
    scanf("%d", &s);          // Read the source vertex for DFS

    stack[++top] = s;         // Push the source vertex onto the stack
    vis[s] = 1;               // Mark the source vertex as visited
    printf("source %d:", s);  // Print the source vertex

    while (top != -1)         // Loop until the stack is empty
    { 
        found = 0;            // Reset the found flag
        u = stack[top];       // Peek the top of the stack (current vertex)

        // Loop through all vertices to find an unvisited adjacent vertex
        for (v = 0; v < n && found == 0; v++) 
        { 
            if (adj[u][v] == 1 && vis[v] == 0)   // Check for unvisited adjacent node
            { 
                printf("->%d", v);              // Print the found vertex
                stack[++top] = v;               // Push the found vertex onto the stack
                vis[v] = 1;                     // Mark the found vertex as visited
                found = 1;                      // Set found flag to indicate success
            } 
        } 

        if (found == 0)         // If no unvisited adjacent vertex is found
        { 
            top--;             // Pop the stack (backtrack)
        }  
    } 
}

//BFS

#include <stdio.h>

int q[10];                   // Queue for BFS traversal
int r = -1, f = 0;           // Queue rear and front indices
int adj[10][10];             // Adjacency matrix to represent the graph
int vis[10] = {0};           // Array to keep track of visited nodes

void main() 
{ 
    int n, i, j, s, v, u; 

    printf("\n Enter the number of vertices: "); 
    scanf("%d", &n);         // Read the number of vertices

    printf("\n Enter the adjacency matrix:\n "); 
    for (i = 0; i < n; i++) 
    { 
        for (j = 0; j < n; j++) 
        { 
            scanf("%d", &adj[i][j]);   // Read adjacency matrix elements
        } 
    } 

    printf("\n Enter the source vertex: "); 
    scanf("%d", &s);          // Read the source vertex for BFS

    q[++r] = s;               // Enqueue the source vertex
    vis[s] = 1;               // Mark the source vertex as visited
    printf("%d: ", s);        // Print the source vertex

    while (f <= r)            // Loop until the queue is empty
    {  
        u = q[f++];           // Dequeue the front element from the queue

        // Loop through all vertices to find unvisited adjacent vertices
        for (v = 0; v < n; v++)  
        { 
            if (adj[u][v] == 1 && vis[v] == 0)  // Check for unvisited adjacent vertex
            {  
                printf("->%d", v);             // Print the found vertex
                vis[v] = 1;                    // Mark the found vertex as visited
                q[++r] = v;                    // Enqueue the found vertex
            } 
        } 
    } 
}
