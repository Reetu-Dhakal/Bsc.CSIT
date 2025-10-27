#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at the beginning
void insertBeginning(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = val;
    newNode->next = head;
    head = newNode;
}

// Insert at the end
void insertEnd(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Insert at a specified position
void insertPosition(int val, int pos) {
    if (pos == 1 || head == NULL) {
        insertBeginning(val);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = val;

    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from the beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);
}

// Delete from the end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

// Delete from a specified position
void deletePosition(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1) {
        deleteBeginning();
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Display the linked list
void display() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    insertBeginning(10);
    insertEnd(20);
    insertPosition(15, 2);
    display();  // Output: 10 -> 15 -> 20 -> NULL

    deleteBeginning();
    display();  // Output: 15 -> 20 -> NULL

    deleteEnd();
    display();  // Output: 15 -> NULL

    insertEnd(30);
    insertEnd(40);
    insertEnd(50);
    display();  // Output: 15 -> 30 -> 40 -> 50 -> NULL

    deletePosition(2);
    display();  // Output: 15 -> 40 -> 50 -> NULL

    return 0;
}
