#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at front
void insertFront(int val) {
    struct Node* newNode = createNode(val);
    if (front == NULL) {
        front = rear = newNode;
    } else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    printf("%d inserted at front.\n", val);
}


// Insert at rear
void insertRear(int val) {
    struct Node* newNode = createNode(val);
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
    printf("%d inserted at rear.\n", val);
}

// Delete from front
void deleteFront() {
    if (front == NULL) {
        printf("Deque is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("%d deleted from front.\n", temp->data);
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        front->prev = NULL;
    }
    free(temp);
}

// Delete from rear
void deleteRear() {
    if (rear == NULL) {
        printf("Deque is empty.\n");
        return;
    }
    struct Node* temp = rear;
    printf("%d deleted from rear.\n", temp->data);
    if (front == rear) {
        front = rear = NULL;
    } else {
        rear = rear->prev;
        rear->next = NULL;
    }
    free(temp);
}

// Display the deque
void display() {
    if (front == NULL) {
        printf("Deque is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("Deque: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Double Ended Queue (Deque) Menu ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &val);
                insertFront(val);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &val);
                insertRear(val);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
