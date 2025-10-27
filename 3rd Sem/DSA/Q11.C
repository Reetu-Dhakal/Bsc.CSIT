#include <stdio.h>

// Tail recursive function to find the largest element
int findMax(int arr[], int n, int maxVal) {
    if (n == 0)
        return maxVal;  // Base case: return the maximum value found

    if (arr[n - 1] > maxVal)
        maxVal = arr[n - 1];  // Update maxVal if current element is greater

    return findMax(arr, n - 1, maxVal);  // Tail recursion
}

int main() {
    int n, i;

    // Taking user input for array size
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Taking user input for array elements
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int maxElement = findMax(arr, n, arr[n - 1]);  // Start with the last element
    printf("The largest element in the array is: %d\n", maxElement);

    return 0;
}