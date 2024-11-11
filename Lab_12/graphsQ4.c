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

void dfsUtil(Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (Node* temp = graph->adjLists[vertex]; temp; temp = temp->next) {
        if (!visited[temp->vertex]) dfsUtil(graph, temp->vertex, visited);
    }
}

void dfs(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    dfsUtil(graph, startVertex, visited);
    printf("\n");
}

int main() {
    Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);

    printf("DFS traversal starting from vertex 0:\n");
    dfs(graph, 0);
    return 0;
}
