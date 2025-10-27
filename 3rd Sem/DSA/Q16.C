#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Stack structure
struct Stack {
    struct Node* top;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Initialize stack
void initStack(struct Stack* stack) {
    stack->top = NULL;
}

// Check if stack is empty
int isStackEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Check if stack is full (memory allocation failure)
int isStackFull() {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        return 1; // Memory allocation failed, stack is full
    }
    free(temp);
    return 0;
}

// Push element onto stack
void push(struct Stack* stack, int value) {
    if (isStackFull()) {
        printf("Stack is full! Memory allocation failed.\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed to stack\n", value);
}

// Pop element from stack
int pop(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Print stack elements
void printStack(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = stack->top;
    printf("Stack: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Initialize queue
void initQueue(struct Queue* queue) {
    queue->front = queue->rear = NULL;
}

// Check if queue is empty
int isQueueEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Check if queue is full (memory allocation failure)
int isQueueFull() {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        return 1; // Memory allocation failed, queue is full
    }
    free(temp);
    return 0;
}

// Enqueue element
void enqueue(struct Queue* queue, int value) {
    if (isQueueFull()) {
        printf("Queue is full! Memory allocation failed.\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (queue->rear) {
        queue->rear->next = newNode;
    } else {
        queue->front = newNode;
    }
    queue->rear = newNode;
    printf("%d enqueued to queue\n", value);
}

// Dequeue element
int dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

// Print queue elements
void printQueue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = queue->front;
    printf("Queue: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Stack stack;
    struct Queue queue;

    initStack(&stack);
    initQueue(&queue);

    printf("\nStack Operations:\n");
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    printStack(&stack);
    printf("Popped element: %d\n", pop(&stack));
    printStack(&stack);

    printf("\nQueue Operations:\n");
    enqueue(&queue, 15);
    enqueue(&queue, 25);
    enqueue(&queue, 35);
    printQueue(&queue);
    printf("Dequeued element: %d\n", dequeue(&queue));
    printQueue(&queue);
       getchar();
    getchar();

    return 0;
}
