#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *top=0;

void push(){
    int x;
    printf("Enter element to add on top: \n");
    scanf("%d", &x);

    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> next = top;
    top = newnode;
}

void display(){
    struct node *temp = top;
    if(top == NULL){
        printf("Stack is empty!\n");
    }else{
        while(temp != NULL){
            printf("%d", temp->data);
            temp = temp->next;
        }
    }
}

void peek(){
    if(top == NULL){
         printf("Stack is empty!\n");
    }else{
        printf("Top most element is: %d", top->data);
    }
}

void pop(){
    struct node *temp = top;
    if(top == NULL){
        printf("Underflow!!!");
    }else{
        printf("Popped element: %d", top->data);
        top = top->next;
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