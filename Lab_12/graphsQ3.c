#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

typedef struct Queue {
    int items[MAX_VERTICES];
    int front, rear;
} Queue;

Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) graph->adjLists[i] = NULL;
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = dest; newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = malloc(sizeof(Node));
    newNode->vertex = src; newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

Queue* createQueue() {
    Queue* queue = malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->rear == -1;
}

void enqueue(Queue* queue, int value) {
    if (queue->rear == MAX_VERTICES - 1) return;
    if (queue->front == -1) queue->front = 0;
    queue->items[++queue->rear] = value;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) return -1;
    int item = queue->items[queue->front];
    if (queue->front >= queue->rear) queue->front = queue->rear = -1;
    else queue->front++;
    return item;
}

void bfs(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    Queue* queue = createQueue();
    visited[startVertex] = 1; enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);
        for (Node* temp = graph->adjLists[currentVertex]; temp; temp = temp->next) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1; enqueue(queue, adjVertex);
            }
        }
    }
    printf("\n");
}

int main() {
    Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);

    printf("BFS traversal starting from vertex 0:\n");
    bfs(graph, 0);
    return 0;
}
