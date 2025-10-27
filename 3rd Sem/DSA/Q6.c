#include <stdio.h>
#define MAXSIZE 5
int queue[MAXSIZE], rear = -1, front = -1;

int isempty() {
    return rear == -1;
}

int isfull() {
    return front == (rear + 1) % MAXSIZE;
}

void enqueue(int data) {
    if (isfull()) {
        printf("Queue is full.\n");
    } else {
        if (isempty()) front = 0;
        rear = (rear + 1) % MAXSIZE;
        queue[rear] = data;
        printf("Data Enqueued\n");
    }
}

void dequeue() {
    if (isempty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Dequeued element: %d\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAXSIZE;
        }
    }
}

void peek() {
    if (isempty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

void display() {
    if (isempty()) {
        printf("Queue is empty.\n");
    } else {
        int i = front;
        printf("Queue contents: ");
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAXSIZE;
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    enqueue(15);
    enqueue(22);
    enqueue(35);
    enqueue(42);
    enqueue(55);
    peek();
    dequeue();
    dequeue();
    enqueue(60);
    display();
    return 0;
}
