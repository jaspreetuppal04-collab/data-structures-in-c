#include <stdio.h>

int main() {
    int adj[5][5] = {0};  // 5x5 adjacency matrix for departments A–E

    // Establish bidirectional (mutual) communication links between departments
    adj[0][1] = adj[1][0] = 1; // A–B connected
    adj[0][2] = adj[2][0] = 1; // A–C connected
    adj[1][2] = adj[2][1] = 1; // B–C connected
    adj[1][3] = adj[3][1] = 1; // B–D connected
    adj[2][3] = adj[3][2] = 1; // C–D connected
    adj[3][4] = adj[4][3] = 1; // D–E connected
    adj[4][0] = adj[0][4] = 1; // E–A connected

    printf("Adjacency Matrix for Departments A–E:\n\n");

    printf("    A B C D E\n");                 // Header for matrix columns
    for (int i = 0; i < 5; i++) {
        printf("%c | ", 'A' + i);              // Print department label (A–E)
        for (int j = 0; j < 5; j++) {
            printf("%d ", adj[i][j]);          // Print 1 if departments are connected, else 0
        }
        printf("\n");                          // New line after each row
    }

    printf("\nGraph type: UNDIRECTED (since communication is mutual)\n"); // Explains matrix symmetry

    return 0;
}
