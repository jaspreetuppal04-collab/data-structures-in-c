#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

struct node* createnode(int value) {
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        return NULL;  
    } else {
        newnode->data = value;
        newnode->next = NULL;
        return newnode;
    }
}

void insertAtBeg(){
    int value;
    struct node *temp;
    printf("Enter value of new node: ");
    scanf("%d", &value);
    temp = createnode(value);

    if (head == NULL) {
        head = temp;   
    } else {
        temp->next = head;
        head = temp;
    }
}

void insertAtEnd(){
    int value;
    struct node *temp, *ptr;
    printf("Enter value of new node: ");
    scanf("%d", &value);
    temp = createnode(value);
    
    ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next; 
    }
    ptr->next = temp;
}

void display() {
    struct node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nEnter: \n1] Add at beginning \n2] Add at a position \n3] Add at the end \n4] Display \n0] Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertAtBeg();
                break;
            case 2:
                printf("Insert at position not implemented yet.\n");
                break;
            case 3:
                insertAtEnd();
                break;
            case 4:
                display();
                break;
            case 0:
                exit(0);  
            default:
                printf("Wrong choice.\n");
                break;
        }
    }
    return 0;
}
