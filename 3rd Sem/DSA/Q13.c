#include <stdio.h>

#define MAX_SIZE 100  // Define the maximum size of the list

int list[MAX_SIZE];  // Array to store the list
int size = 0;        // Current size of the list

// Function to display the list
void display() {
    if (size == 0) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

// Function to insert an element at a specified position
void insertAt(int pos, int value) {
    if (size >= MAX_SIZE) {
        printf("List is full. Cannot insert more elements.\n");
        return;
    }
    if (pos < 0 || pos > size) {
        printf("Invalid position! Must be between 0 and %d.\n", size);
        return;
    }
    // Shift elements to the right
    for (int i = size; i > pos; i--) {
        list[i] = list[i - 1];
    }
    list[pos] = value;
    size++;
    printf("Inserted %d at position %d.\n", value, pos);
}

// Function to delete an element from a specified position
void deleteAt(int pos) {
    if (size == 0) {
        printf("List is empty. Cannot delete elements.\n");
        return;
    }
    if (pos < 0 || pos >= size) {
        printf("Invalid position! Must be between 0 and %d.\n", size - 1);
        return;
    }
    printf("Deleted %d from position %d.\n", list[pos], pos);
    // Shift elements to the left
    for (int i = pos; i < size - 1; i++) {
        list[i] = list[i + 1];
    }
    size--;
}


int main() {
    // Sample operations
    insertAt(0, 10);  // Insert at the beginning
    insertAt(1, 20);  // Insert at the end (position 1, since only one element exists)
    insertAt(1, 15);  // Insert at position 1 (middle)
    display();

    deleteAt(0);  // Delete from the beginning
    display();

    deleteAt(size - 1);  // Delete from the end
    display();

    insertAt(1, 25);  // Insert at position 1
    display();

    deleteAt(1);  // Delete from position 1
    display();

    return 0;
}
