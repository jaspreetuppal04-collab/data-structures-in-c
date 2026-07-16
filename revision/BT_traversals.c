#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node *createNode(int value){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = value;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

//ROOT->L->R
void preorder(struct node *root){     
    if(root != NULL){
        printf("%d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

//L->ROOT->R
void inorder(struct node *root){     
    if(root != NULL){
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}

//L->R->ROOT
void postorder(struct node *root){     
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->data);
    }
}

int main(){

    struct node *root = createNode(1);
    root -> left = createNode(2);
    root -> right = createNode(3);
    root -> left -> left = createNode(4);
    root -> left -> right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Preorder Traversal: \n");
    preorder(root);
    printf("\n");

    printf("Inorder Traversal: \n");
    inorder(root);
    printf("\n");

    printf("postorder Traversal: \n");
    postorder(root);
    printf("\n");

}