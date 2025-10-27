#include <stdio.h>
#define MAX 500
int queue[MAX], front = -1, rear = -1;

void enqueue(int size) {
    if (rear == size - 1) {
        printf("Queue is full!\n");
    } else {
        if (front == -1) front = 0;
        printf("Enter value to enqueue: ");
        scanf("%d", &queue[++rear]);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Dequeued value: %d\n", queue[front++]);
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue contents: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int size, choice;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(size); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
