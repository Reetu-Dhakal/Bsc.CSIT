#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000003 // Size of the hash table (prime number for better distribution)

// Node for chaining (linked list)
typedef struct Node {
    int key;
    struct Node* next;
} Node;

// Hash Table
typedef struct HashTable {
    int *table;  // For Linear & Quadratic Probing
    Node **chain; // For Chaining
} HashTable;

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Linear Probing
void linearProbingInsert(HashTable *ht, int key) {
    int index = hash(key);
    while (ht->table[index] != -1) {
        index = (index + 1) % SIZE;
    }
    ht->table[index] = key;
}

// Quadratic Probing
void quadraticProbingInsert(HashTable *ht, int key) {
    int index = hash(key);
    int i = 1;
    while (ht->table[index] != -1) {
        index = (index + i * i) % SIZE;
        i++;
    }
    ht->table[index] = key;
}

// Chaining (using linked list)
void chainingInsert(HashTable *ht, int key) {
    int index = hash(key);
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = ht->chain[index];
    ht->chain[index] = newNode;
}

// Linear Probing search
int linearProbingSearch(HashTable *ht, int key) {
    int index = hash(key);
    int startIndex = index;
    while (ht->table[index] != -1) {
        if (ht->table[index] == key) return 1;
        index = (index + 1) % SIZE;
        if (index == startIndex) break; // Loop back to start
    }
    return 0;
}

// Quadratic Probing search
int quadraticProbingSearch(HashTable *ht, int key) {
    int index = hash(key);
    int i = 1;
    while (ht->table[index] != -1) {
        if (ht->table[index] == key) return 1;
        index = (index + i * i) % SIZE;
        i++;
    }
    return 0;
}

// Chaining search
int chainingSearch(HashTable *ht, int key) {
    int index = hash(key);
    Node *current = ht->chain[index];
    while (current) {
        if (current->key == key) return 1;
        current = current->next;
    }
    return 0;
}

// Function to compare execution time
void compareExecutionTimes(int *keys, int n) {
    clock_t start, end;
    double cpu_time_used;

    // Linear Probing
    HashTable htLinear;
    htLinear.table = (int*)malloc(sizeof(int) * SIZE);
    for (int i = 0; i < SIZE; i++) htLinear.table[i] = -1;

    start = clock();
    for (int i = 0; i < n; i++) {
        linearProbingInsert(&htLinear, keys[i]);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Linear Probing time: %f seconds\n", cpu_time_used);

    // Quadratic Probing
    HashTable htQuadratic;
    htQuadratic.table = (int*)malloc(sizeof(int) * SIZE);
    for (int i = 0; i < SIZE; i++) htQuadratic.table[i] = -1;

    start = clock();
    for (int i = 0; i < n; i++) {
        quadraticProbingInsert(&htQuadratic, keys[i]);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Quadratic Probing time: %f seconds\n", cpu_time_used);

    // Chaining
    HashTable htChaining;
    htChaining.chain = (Node**)malloc(sizeof(Node*) * SIZE);
    for (int i = 0; i < SIZE; i++) htChaining.chain[i] = NULL;

    start = clock();
    for (int i = 0; i < n; i++) {
        chainingInsert(&htChaining, keys[i]);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Chaining time: %f seconds\n", cpu_time_used);

    // Cleanup
    free(htLinear.table);
    free(htQuadratic.table);
    for (int i = 0; i < SIZE; i++) {
        Node *current = htChaining.chain[i];
        while (current) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(htChaining.chain);
}

int main() {
    int n = 100000; // Size of dataset
    int *keys = (int*)malloc(sizeof(int) * n);

    // Generate random keys for the dataset
    srand(time(0));
    for (int i = 0; i < n; i++) {
        keys[i] = rand() % (SIZE * 2);  // Generate random keys
    }

    compareExecutionTimes(keys, n);

    free(keys);
    return 0;
}
