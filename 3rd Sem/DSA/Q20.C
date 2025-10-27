#include <stdio.h>

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); 
    }
    printf("\n");
}

// Function to implement Shell Sort and count iterations
void ShellSort(int arr[], int n, int *steps) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                (*steps)++; // Counting iterations
            }
            arr[j] = temp;
        }
    }
}

// Function to implement Bubble Sort and count iterations
void BubbleSort(int arr[], int n, int *steps) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            (*steps)++; // Counting iterations
        }
    }
}

int main() {
    int arr[] = {64, 98, 47, 62, 84, 36, 102, 25, 59, 70}; // List of student scores
    int n = sizeof(arr) / sizeof(arr[0]);

    // Creating copies of the array for fair comparison
    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++) {
        arr1[i] = arr[i];
        arr2[i] = arr[i];
    }

    printf("Original Array:\n");
    printArray(arr, n);

    int shellSteps = 0, bubbleSteps = 0; 

    // Sorting using Shell Sort
    ShellSort(arr1, n, &shellSteps);
    printf("\nSorted Array using Shell Sort:\n");
    printArray(arr1, n);
    
    // Sorting using Bubble Sort
    BubbleSort(arr2, n, &bubbleSteps);
    printf("\nSorted Array using Bubble Sort:\n");
    printArray(arr2, n);

    // Comparing execution steps
    printf("\nExecution Step Comparison:\n");
    printf("\nShell Sort Steps: %d\n", shellSteps);
    printf("Bubble Sort Steps: %d\n", bubbleSteps);
    getchar();
    getchar();

    return 0;
}
