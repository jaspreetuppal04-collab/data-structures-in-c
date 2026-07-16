#include <stdio.h>

int main() {
    int arr[10] = {12, 45, 23, 51, 19, 8, 33, 76, 27, 55};
    int n = 10;
    int key, found = 0;

    printf("Enter element to search: ");
    scanf("%d", &key);                      // Take input number to search for

    for (int i = 0; i < n; i++) {           // Traverse each element in array
        if (arr[i] == key) {                // Compare current element with key
            printf("Element %d found at index %d\n", key, i);
            found = 1;                      // Mark as found
            break;                          // Stop searching once found
        }
    }

    if (!found)                             // If still 0, element not present
        printf("Element %d not found in array\n", key);

    return 0;
}
