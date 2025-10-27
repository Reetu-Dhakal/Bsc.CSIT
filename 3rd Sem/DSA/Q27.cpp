#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Sequential Search Function
int sequentialSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  // Return index if element is found
        }
    }
    return -1;  // Return -1 if element is not found
}

// Binary Search Function (assuming the array is sorted)
int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if key is present at mid
        if (arr[mid] == key) {
            return mid;
        }

        // If key is greater, ignore the left half
        if (arr[mid] < key) {
            left = mid + 1;
        }
        // If key is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }
    return -1;  // Return -1 if element is not found
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to fill the array with random numbers
void fillArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;  // Random numbers between 0 and 999
    }
}

// Function to sort an array using Bubble Sort (for Binary Search)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Main function
int main() {
    srand(time(NULL));  // Seed the random number generator

    int n = 10000;  // Size of the array
    int key = 500;  // Element to search for
    
    // Arrays for comparison
    int unsortedArr[n], sortedArr[n];
    
    // Fill the unsorted array with random numbers
    fillArray(unsortedArr, n);
    
    // Copy the unsorted array to the sorted array
    for (int i = 0; i < n; i++) {
        sortedArr[i] = unsortedArr[i];
    }

    // Sort the sorted array (for Binary Search)
    bubbleSort(sortedArr, n);
    
    // Sequential Search for Unsorted Array
    clock_t start = clock();
    int seqUnsorted = sequentialSearch(unsortedArr, n, key);
    clock_t end = clock();
    double timeSeqUnsorted = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Sequential Search for Sorted Array
    start = clock();
    int seqSorted = sequentialSearch(sortedArr, n, key);
    end = clock();
    double timeSeqSorted = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Binary Search for Sorted Array
    start = clock();
    int binSorted = binarySearch(sortedArr, n, key);
    end = clock();
    double timeBinSorted = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print results
    printf("Sequential Search (Unsorted Array): Element found at index %d\n", seqUnsorted);
    printf("Time taken for Sequential Search (Unsorted Array): %.6f seconds\n", timeSeqUnsorted);
    
    printf("Sequential Search (Sorted Array): Element found at index %d\n", seqSorted);
    printf("Time taken for Sequential Search (Sorted Array): %.6f seconds\n", timeSeqSorted);

    printf("Binary Search (Sorted Array): Element found at index %d\n", binSorted);
    printf("Time taken for Binary Search (Sorted Array): %.6f seconds\n", timeBinSorted);

    return 0;
}