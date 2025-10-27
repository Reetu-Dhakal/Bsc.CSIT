#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices

// Graph structure using adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

// Queue structure for BFS
struct Queue {
    int items[MAX];
    int front, rear;
};

// Function to create a queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Enqueue function
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1)
        printf("\nQueue is full");
    else {
        if (q->front == -1) 
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Dequeue function
int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("\nQueue is empty");
        return -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {  // Reset queue if empty
            q->front = q->rear = -1;
        }
        return item;
    }
}

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (For undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Breadth-First Search function
void BFS(struct Graph* graph, int startVertex) {
    struct Queue* queue = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(queue, startVertex);

    printf("Breadth-First Search traversal starting from vertex %d:\n", startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }
}

// Driver function
int main() {
    int vertices = 6;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);

    BFS(graph, 0);

    return 0;
}
