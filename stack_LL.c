#include <stdio.h>
#include <stdlib.h>   // for malloc(), free(), exit()

struct node{
    int data;
    struct node *next;
};
struct node *top = 0;

void push(){
    int x;
    printf("Enter the value: \n");
    scanf("%d", &x);

    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> next = top;
    top = newnode;
}

void display() {
    struct node *temp = top;  // start from top
    if (top == NULL) {
        printf("Stack empty\n");
    } else {
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void peek(){
    if(top == NULL){
        printf("Stack empty: \n");
    }else{
        printf("The top element is: %d", top->data);
    }
}

void pop(){
    struct node *temp;
    temp = top;
    if(top == NULL){
        printf("Underflow \n");
    }else{
        printf("Popped element: %d", top->data);
        top = top -> next;
        free(temp);
    }
}

int main(){
    int value = 0;
    printf("Enter task to perform: \n");
     while (value != 5) {
        printf("\nChoose one from the below options...\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit...");
        printf("Enter your choice: ");
        scanf("%d", &value);

        switch (value) {
             case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
               printf("Exiting....\n");
                exit(0);   
            default:
                printf("Please enter a valid choice.\n");
        }
    }
}