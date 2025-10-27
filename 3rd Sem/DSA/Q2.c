#include <stdio.h>
#define MAXSIZE 10

int stack[MAXSIZE]; // Stack array to store elements
int top = -1;       // Variable to track the top of the stack

// Function to check if the stack is empty
int isempty() {
    return (top == -1); // Returns 1 if empty, 0 otherwise
}

// Function to check if the stack is full
int isfull() {
    return (top == MAXSIZE - 1); // Returns 1 if full, 0 otherwise
}

// Function to display the top element of the stack
void peek() {
    if (isempty())
        printf("Stack is empty. No element to peek.\n");
    else
        printf("Element at top: %d\n", stack[top]);
}

// Function to remove (pop) the top element from the stack
void pop() {
    if (isempty())
        printf("Stack is empty. Cannot pop.\n");
    else {
        int data = stack[top]; // Store the top element
        top--;                 // Decrement the top pointer
        printf("Popped element: %d\n", data);
    }
}

// Function to add (push) an element to the stack
void push(int data) {
    if (isfull())
        printf("Stack is full. Cannot push %d.\n", data);
    else {
        top++;           // Increment the top pointer
        stack[top] = data; // Add the element to the stack
        printf("Pushed element: %d\n", data);
    }
}

// Function to display all elements in the stack
void display() {
    if (isempty())
        printf("Stack is empty.\n");
    else {
        printf("Stack :\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\t", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    // Demonstrate stack operations#include <stdio.h>
#define MAXSIZE 10

int stack[MAXSIZE]; // Stack array to store elements
int top = -1;       // Variable to track the top of the stack

// Function to check if the stack is empty
int isempty() {
    return (top == -1); // Returns 1 if empty, 0 otherwise
}

// Function to check if the stack is full
int isfull() {
    return (top == MAXSIZE - 1); // Returns 1 if full, 0 otherwise
}

// Function to display the top element of the stack
void peek() {
    if (isempty())
        printf("Stack is empty. No element to peek.\n");
    else
        printf("Element at top: %d\n", stack[top]);
}

// Function to remove (pop) the top element from the stack
void pop() {
    if (isempty())
        printf("Stack is empty. Cannot pop.\n");
    else {
        int data = stack[top]; // Store the top element
        top--;                 // Decrement the top pointer
        printf("Popped element: %d\n", data);
    }
}

// Function to add (push) an element to the stack
void push(int data) {
    if (isfull())
        printf("Stack is full. Cannot push %d.\n", data);
    else {
        top++;           // Increment the top pointer
        stack[top] = data; // Add the element to the stack
        printf("Pushed element: %d\n", data);
    }
}

// Function to display all elements in the stack
void display() {
    if (isempty())
        printf("Stack is empty.\n");
    else {
        printf("Stack :\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\t", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    // Demonstrate stack operations
    push(36); // Push 36 onto the stack
    push(56); // Push 56 onto the stack
    push(28); // Push 28 onto the stack
    push(6);  // Push 6 onto the stack
    push(16); // Push 16 onto the stack

    display(); // Display the stack

    peek(); // Peek at the top element

    pop();  // Pop the top element
    pop();  // Pop the top element

    peek(); // Peek at the new top element

    display(); // Display the updated stack

    return 0; // End of program
}
    push(38); // Push 36 onto the stack
    push(51); // Push 56 onto the stack
    push(24); // Push 28 onto the stack
    push(9);  // Push 6 onto the stack
    push(21); // Push 16 onto the stack

    display(); // Display the stack

    peek(); // Peek at the top element

    pop();  // Pop the top element
    pop();  // Pop the top element

    peek(); // Peek at the new top element

    display(); // Display the updated stack

    return 0; // End of program
}