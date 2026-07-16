#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;   // global head pointer

// Create new node
struct node* createNode(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

// Insert at beginning (pos = 0)
void insertAtBeginning(int value) {
    struct node *newnode = createNode(value);
    newnode->next = head;
    head = newnode;
}

// Insert at end
void insertAtEnd(int value) {
    struct node *newnode = createNode(value);
    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Insert at given position (0-based index)
void insertAtPosition(int value, int pos) {
    struct node *newnode = createNode(value);

    if (pos == 0) { // insert at beginning
        newnode->next = head;
        head = newnode;
        return;
    }

    struct node *temp = head;
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newnode);
    } else {
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

// Delete at beginning
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
}

// Delete at end
void deleteAtEnd() {
    struct node *temp, *prevnode;

    if (head == NULL) {   // empty list
        printf("List is empty!\n");
        return;
    }

    temp = head;
    while (temp->next != NULL) {   // traverse till last node
        prevnode = temp;           // keep track of previous node
        temp = temp->next;
    }

    if (temp == head) {            // only one node in the list
        head = NULL;
        free(temp);
    } else {                       // more than one node
        prevnode->next = NULL;     // second last node becomes last
        free(temp);                // free last node
    }
}

// Delete at position (0-based index)
void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (pos == 0) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct node *temp = head;
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range!\n");
    } else {
        struct node *del = temp->next;
        temp->next = del->next;
        free(del);
    }
}

// Sort list (ascending order)
void sortList() {
    if (head == NULL || head->next == NULL) return;

    struct node *i, *j;
    int temp;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Display list
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position (0-based)\n");
        printf("4. Delete at Beginning\n5. Delete at End\n6. Delete at Position (0-based)\n");
        printf("7. Sort List\n8. Display List\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value and position (0-based): ");
                scanf("%d %d", &value, &pos);
                insertAtPosition(value, pos);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter position (0-based): ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 7:
                sortList();
                printf("List sorted!\n");
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
