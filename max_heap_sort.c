#include <stdio.h>  


void heapify(int arr[], int n, int i) {
    int largest = i;       // Assume current index 'i' is the largest
    int left = 2 * i + 1;  // Calculate index of left child
    int right = 2 * i + 2; // Calculate index of right child

    // If left child exists and is greater than current largest
    if (left < n && arr[left] > arr[largest])
        largest = left;    // Update largest to left child's index

    // If right child exists and is greater than current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;   // Update largest to right child's index

    // If largest is not the root index
    if (largest != i) {
        int temp = arr[i];         // Store current element in temp
        arr[i] = arr[largest];     // Swap root with the largest child
        arr[largest] = temp;       // Complete the swap

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Step 1: Build a max heap from the input array
    for (int i = n / 2 - 1; i >= 0; i--)  // Start from last non-leaf node
        heapify(arr, n, i);               // Heapify each subtree

    // Step 2: One by one extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];   // Move current root (max element) to end
        arr[0] = arr[i];     // Place last element at root position
        arr[i] = temp;       // Complete the swap

        heapify(arr, i, 0);  // Heapify the reduced heap (excluding sorted part)
    }
}

// Function to print array elements
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)   // Loop through all elements
        printf("%d ", arr[i]);    // Print each element
    printf("\n");                 // New line after printing all elements
}

// Main function
int main() {
    int arr[50], n;   // Declare array and variable for number of elements

    printf("Enter number of elements: ");
    scanf("%d", &n);  // Take array size input

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)   // Loop to take array input
        scanf("%d", &arr[i]);

    heapSort(arr, n);  // Call heap sort function to sort the array

    printf("Sorted array in ascending order:\n");
    printArray(arr, n);  // Display the sorted array

    return 0;  // End of program
}
