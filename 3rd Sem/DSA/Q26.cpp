#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform Shell Sort
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n = 10; // Size of array
    int arr[n];
    
    // Seed random number generator
    srand(time(0));
    
    // Generate an array of random numbers
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Sort the array using Shell Sort
    shellSort(arr, n);
    
    // Print the sorted array
    printf("Sorted array using Shell Sort: ");
    printArray(arr, n);
    
    return 0;
}
