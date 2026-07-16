#include <stdio.h>
#include <stdlib.h>

#define SIZE 10  // Fixed size of hash table (kept small for demonstration)

struct Node {
    int data;
    struct Node* next;
};

struct Node* hashTable[SIZE];

// Create a new node for linked list chaining
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Hash function: simple modulo operation
int hashFunction(int key) {
    return key % SIZE;  // Ensures key maps within 0–9
}

// Insert an element into the hash table
void insert(int value) {
    int index = hashFunction(value);         // Find index using hash function
    struct Node* newNode = createNode(value);

    // Case 1: Empty bucket — directly insert
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } 
    // Case 2: Collision — add node at the end of the chain
    else {
        struct Node* temp = hashTable[index];
        while (temp->next != NULL)           // Traverse to the last node in chain
            temp = temp->next;
        temp->next = newNode;                // Append new node
    }
}

// Print all buckets and their contents
void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("Bucket %d: ", i);
        struct Node* temp = hashTable[i];
        while (temp != NULL) {               // Traverse linked list in each bucket
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");                    // End of chain
    }
}

int main() {
    int values[20] = {15, 23, 7, 41, 29, 12, 92, 31, 48, 55,
                      63, 17, 9, 5, 87, 26, 34, 45, 68, 77};

    for (int i = 0; i < 20; i++)
        insert(values[i]);                   // Insert all elements into hash table

    printf("Hash Table using Separate Chaining:\n\n");
    display();                               // Show all buckets and collisions

    return 0;
}
