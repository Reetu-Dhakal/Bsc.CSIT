#include <stdio.h>
#define MAX 100

typedef struct {
    int data;
    int priority;
} Element;

Element queue[MAX];
int size = 0;

void enqueue(int value, int priority) {
    if (size == MAX) {
        printf("Priority queue is full!\n");
    } else {
        queue[size].data = value;
        queue[size].priority = priority;
        int i = size++;
        while (i > 0 && queue[(i - 1) / 2].priority < queue[i].priority) {
            Element temp = queue[i];
            queue[i] = queue[(i - 1) / 2];
            queue[(i - 1) / 2] = temp;
            i = (i - 1) / 2;
        }
        printf("Data Enqueued: %d with priority: %d\n", value, priority);
    }
}

void dequeue() {
    if (size == 0) {
        printf("Priority queue is empty!\n");
    } else {
        printf("Dequeued: %d with priority: %d\n", queue[0].data, queue[0].priority);
        queue[0] = queue[--size];
        int i = 0;
        while (2 * i + 1 < size) {
            int maxChild = 2 * i + 1;
            if (2 * i + 2 < size && queue[2 * i + 2].priority > queue[maxChild].priority) {
                maxChild = 2 * i + 2;
            }
            if (queue[i].priority >= queue[maxChild].priority) break;
            Element temp = queue[i];
            queue[i] = queue[maxChild];
            queue[maxChild] = temp;
            i = maxChild;
        }
    }
}

void display() {
    if (size == 0) {
        printf("Priority queue is empty!\n");
    } else {
        printf("Priority queue contents:\n");
        for (int i = 0; i < size; i++) {
            printf("Value: %d, Priority: %d\n", queue[i].data, queue[i].priority);
        }
    }
}

int main() {
    enqueue(12, 1);
    enqueue(22, 7);
    enqueue(32, 4);
    enqueue(42, 3);
    enqueue(52, 6);
    display();
    dequeue();
    dequeue();
    display();
    return 0;
}
