#include <stdio.h>
#include <time.h>

// -------- SELECTION SORT --------
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swap
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// -------- QUICK SORT --------
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// -------- MAIN FUNCTION --------
int main() {
    int arr1[] = {64, 25, 12, 22, 11};
    int arr2[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    printf("Original Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr1[i]);
    printf("\n");

    clock_t start, end;

    // Selection Sort
    start = clock();
    selectionSort(arr1, n);
    end = clock();

    printf("\nSelection Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr1[i]);
    printf("\nTime Complexity: O(n^2)");
    printf("\nExecution Time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Quick Sort
    start = clock();
    quickSort(arr2, 0, n - 1);
    end = clock();

    printf("\nQuick Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr2[i]);
    printf("\nTime Complexity: Average O(n log n), Worst O(n^2)");
    printf("\nExecution Time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
