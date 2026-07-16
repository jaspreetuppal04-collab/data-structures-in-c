#include <stdio.h>    
#include <stdlib.h>  
#include <string.h>   


struct Node {
    char name[50];          
    char phone[20];        
    struct Node* left;      
    struct Node* right;     
};

// Function to create a new node
struct Node* createNode(char name[], char phone[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  // Allocate memory for a new node
    strcpy(newNode->name, name);   // Copy name into node
    strcpy(newNode->phone, phone); // Copy phone number into node
    newNode->left = newNode->right = NULL; // Initialize children as NULL
    return newNode;                 // Return the newly created node
}

// Function to insert a new contact into the BST
struct Node* insert(struct Node* root, char name[], char phone[]) {
    if (root == NULL)               // If tree is empty, create a new node
        return createNode(name, phone);

    if (strcmp(name, root->name) < 0)      // If name is alphabetically smaller, go to left subtree
        root->left = insert(root->left, name, phone);
    else if (strcmp(name, root->name) > 0) // If name is alphabetically larger, go to right subtree
        root->right = insert(root->right, name, phone);
    else                                   // If name already exists
        printf("Contact already exists!\n");

    return root;   // Return the (possibly unchanged) root
}

// Function to search a contact by name
void search(struct Node* root, char name[]) {
    if (root == NULL) {                     // If tree is empty or not found
        printf("Contact not found!\n");
        return;
    }

    if (strcmp(name, root->name) == 0)      // If name matches
        printf("Name: %s, Phone: %s\n", root->name, root->phone);
    else if (strcmp(name, root->name) < 0)  // If name is smaller, search left
        search(root->left, name);
    else                                    // If name is larger, search right
        search(root->right, name);
}

// Function to find the node with minimum value (used during deletion)
struct Node* findMin(struct Node* node) {
    while (node->left != NULL)     // Keep going left until the smallest node is found
        node = node->left;
    return node;                   // Return smallest node
}

// Function to delete a contact by name
struct Node* delete(struct Node* root, char name[]) {
    if (root == NULL)              // If tree is empty
        return root;

    if (strcmp(name, root->name) < 0)        // If name is smaller, go left
        root->left = delete(root->left, name);
    else if (strcmp(name, root->name) > 0)   // If name is larger, go right
        root->right = delete(root->right, name);
    else {                                   // Node to delete found
        if (root->left == NULL) {            // Case 1: No left child
            struct Node* temp = root->right; // Store right child
            free(root);                      // Delete current node
            return temp;                     // Return right child
        } else if (root->right == NULL) {    // Case 2: No right child
            struct Node* temp = root->left;  // Store left child
            free(root);                      // Delete current node
            return temp;                     // Return left child
        }

        // Case 3: Node has two children
        struct Node* temp = findMin(root->right); // Find inorder successor
        strcpy(root->name, temp->name);           // Copy successor's name
        strcpy(root->phone, temp->phone);         // Copy successor's phone
        root->right = delete(root->right, temp->name); // Delete successor node
    }

    return root;  // Return updated root
}

// Function to display contacts in ascending (A-Z) order
void inorder(struct Node* root) {
    if (root != NULL) {                        // If current node is not NULL
        inorder(root->left);                   // Traverse left subtree
        printf("Name: %s, Phone: %s\n", root->name, root->phone); // Print current contact
        inorder(root->right);                  // Traverse right subtree
    }
}

// Function to display contacts in descending (Z-A) order
void reverseInorder(struct Node* root) {
    if (root != NULL) {                        // If current node is not NULL
        reverseInorder(root->right);           // Traverse right subtree
        printf("Name: %s, Phone: %s\n", root->name, root->phone); // Print current contact
        reverseInorder(root->left);            // Traverse left subtree
    }
}

int main() {
    struct Node* root = NULL;  // Initialize root as NULL (empty phonebook)
    int choice;                // Variable for menu choice
    char name[50], phone[20];  // Variables to store user input

    while (1) {  
        printf("\n--- Phone Book Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contact\n");
        printf("4. Display (Ascending)\n");
        printf("5. Display (Descending)\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);   

        switch (choice) {
            case 1:  
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Phone: ");
                scanf("%s", phone);
                root = insert(root, name, phone);  
                break;

            case 2:   
                printf("Enter Name to Delete: ");
                scanf("%s", name);
                root = delete(root, name);      
                break;

            case 3:   
                printf("Enter Name to Search: ");
                scanf("%s", name);
                search(root, name);               
                break;

            case 4:   
                printf("\nContacts in Ascending Order:\n");
                inorder(root);
                break;

            case 5:   
                printf("\nContacts in Descending Order:\n");
                reverseInorder(root);
                break;

            case 6:   
                exit(0);

            default:  
                printf("Invalid choice!\n");
        }
    }
    return 0; 
}
