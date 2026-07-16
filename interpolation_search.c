#include <stdio.h>

// Function to perform interpolation search
int interpolationSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;  // Set initial search boundaries

    // Continue searching while the key lies between arr[low] and arr[high]
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        
        // Estimate the position of the key using the interpolation formula
        int pos = low + ((double)(key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        // If the key is found at the estimated position
        if (arr[pos] == key)
            return pos;  // Return its index

        // If key is larger, it must be in the right subarray
        if (arr[pos] < key)
            low = pos + 1;

        // If key is smaller, it must be in the left subarray
        else
            high = pos - 1;
    }

    // If element is not found
    return -1;
}

int main() {
    // Sorted array (ascending order)
    int arr[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate number of elements
    int key;

    // Take user input for the element to search
    printf("Enter element to search: ");
    scanf("%d", &key);

    // Call interpolation search function
    int result = interpolationSearch(arr, n, key);

    // Display the result
    if (result != -1)
        printf("Element %d found at index %d\n", key, result);
    else
        printf("Element %d not found in array\n", key);

    return 0;
}
