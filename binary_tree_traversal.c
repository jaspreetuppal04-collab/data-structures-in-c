#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Creates a new node with given value
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Preorder traversal: Root -> Left -> Right
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);  // Visit root
        preorder(root->left);       // Traverse left subtree
        preorder(root->right);      // Traverse right subtree
    }
}

// Inorder traversal: Left -> Root -> Right
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);        // Traverse left subtree
        printf("%d ", root->data);  // Visit root
        inorder(root->right);       // Traverse right subtree
    }
}

// Postorder traversal: Left -> Right -> Root
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);      // Traverse left subtree
        postorder(root->right);     // Traverse right subtree
        printf("%d ", root->data);  // Visit root
    }
}

int main() {
    // Build binary tree manually
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Preorder Traversal: ");
    preorder(root);      // Prints nodes in Root-Left-Right order
    printf("\n");

    printf("Inorder Traversal: ");
    inorder(root);       // Prints nodes in Left-Root-Right order
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);     // Prints nodes in Left-Right-Root order
    printf("\n");

    return 0;
}
