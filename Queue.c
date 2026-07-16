#include <stdlib.h>
#include <stdio.h>
#define maxsize 10

int front = -1;
int rear = -1;
int Queue[maxsize];

void insert() {
    int item;
    printf("Enter the item: ");
    scanf("%d", &item);

    if (rear == maxsize - 1) {
        printf("\nOverflow!!!\n");
        return;
    }
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = rear + 1;
    }
    Queue[rear] = item;
    printf("\nValue inserted.");
}

void display() {
    if (rear == -1) {
        printf("\nQueue is empty.\n");
    } else {
        printf("\nPrinting values....\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", Queue[i]);
        }
        printf("\n");
    }
}

void deletev() {
    int item;
    if (front == -1) {
        printf("\nUnderflow!!!\n");
    } else {
        item = Queue[front];
        printf("\nDeleted: %d\n", item);

        if (front == rear) {   
            front = -1;
            rear = -1;
        } else {
            front = front + 1;
        }
    }
}

int main() {
    int choice = 0;  

    while (choice != 4) {
        printf("\n1 Insert new value ");
        printf("\n2 Display all the values ");
        printf("\n3 Delete value ");
        printf("\n4 Exit... ");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                deletev();
                break;

            case 4:
                printf("\nBye...!\n");
                exit(0);   
                break;

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }
}
