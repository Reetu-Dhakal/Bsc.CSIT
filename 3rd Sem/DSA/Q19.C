#include <stdio.h>

// Function to implement Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements that are greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int customerIDs[] = {92, 84, 99, 82, 96, 86};
    int n = sizeof(customerIDs) / sizeof(customerIDs[0]);

    insertionSort(customerIDs, n);

    printf("Sorted Customer IDs:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", customerIDs[i]);
    }
       getchar();
    getchar();

    return 0;
}
