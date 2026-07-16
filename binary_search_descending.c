#include <stdio.h>

int binarySearchDescending(int arr[], int n, int key) {
    int low = 0, high = n - 1;                  // Define search range

    while (low <= high) {                       // Continue until range is valid
        int mid = (low + high) / 2;             // Find middle index

        if (arr[mid] == key)                    // If key found, return index
            return mid;

        // For descending array, larger elements are on the left
        else if (arr[mid] < key)
            high = mid - 1;                     // Move left (towards larger values)
        else
            low = mid + 1;                      // Move right (towards smaller values)
    }
    return -1;                                  // Key not found
}

int main() {
    int arr[] = {99, 88, 75, 64, 55, 43, 32, 21, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter element to search: ");
    scanf("%d", &key);                          // Take input value to search

    int result = binarySearchDescending(arr, n, key);

    if (result != -1)                           // If valid index returned
        printf("Element %d found at index %d\n", key, result);
    else
        printf("Element %d not found in array\n", key);

    return 0;
}
