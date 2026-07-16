#include <stdio.h>

#define MAX 5
int adj[MAX][MAX] = {
    // A  B  C  D  E
    {0, 1, 1, 0, 1}, // A
    {1, 0, 1, 1, 0}, // B
    {1, 1, 0, 1, 0}, // C
    {0, 1, 1, 0, 1}, // D
    {1, 0, 0, 1, 0}  // E
};
int visited[MAX];

// ---------- DFS ----------
void DFS(int start) {
    visited[start] = 1;                     // Mark current node as visited
    printf("%c ", 'A' + start);             // Print current node (A–E)

    for (int i = 0; i < MAX; i++) {
        // Visit all connected and unvisited nodes recursively
        if (adj[start][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

// ---------- BFS ----------
void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < MAX; i++)
        visited[i] = 0;                     // Reset visited array before BFS

    visited[start] = 1;                     // Mark start node as visited
    queue[rear++] = start;                  // Enqueue start node

    while (front < rear) {                  // Continue until queue is empty
        int node = queue[front++];          // Dequeue front node
        printf("%c ", 'A' + node);          // Print current node

        for (int i = 0; i < MAX; i++) {
            // If a node is connected and unvisited, enqueue it
            if (adj[node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

// ---------- Shortest Path from A to D using BFS ----------
void shortestPath(int start, int end) {
    int queue[MAX], parent[MAX];
    int front = 0, rear = 0;

    for (int i = 0; i < MAX; i++) {
        visited[i] = 0;
        parent[i] = -1;                     // Initialize parent for path tracking
    }

    visited[start] = 1;
    queue[rear++] = start;                  // Enqueue start node

    // Perform BFS to find shortest path
    while (front < rear) {
        int node = queue[front++];

        if (node == end)                    // Stop if destination is reached
            break;

        for (int i = 0; i < MAX; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                parent[i] = node;           // Store parent for backtracking path
                queue[rear++] = i;
            }
        }
    }

    printf("\nShortest Path from %c to %c: ", 'A' + start, 'A' + end);
    int path[MAX], count = 0;
    int temp = end;

    // Backtrack using parent array to reconstruct the path
    while (temp != -1) {
        path[count++] = temp;
        temp = parent[temp];
    }

    // Print path in correct order (A → D)
    for (int i = count - 1; i >= 0; i--)
        printf("%c ", 'A' + path[i]);
}

int main() {
    printf("Depth First Search (DFS) from A:\n");
    for (int i = 0; i < MAX; i++) visited[i] = 0;  // Reset visited before DFS
    DFS(0);                                        // Start DFS from A

    printf("\n\nBreadth First Search (BFS) from A:\n");
    BFS(0);                                        // Start BFS from A

    shortestPath(0, 3);                            // Find shortest path from A → D

    return 0;
}
