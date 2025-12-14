#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int matrix[MAX_VERTICES][MAX_VERTICES];
    int vertex_num; 
} AdjMatrixGraph;


void initGraph(AdjMatrixGraph *graph, int vertex_num) {
    graph->vertex_num = vertex_num;
    for (int i = 0; i < vertex_num; i++) {
        for (int j = 0; j < vertex_num; j++) {
            graph->matrix[i][j] = 0;
        }
    }
}


void addEdge(AdjMatrixGraph *graph, int v1, int v2, int weight) {
    if (v1 >= 0 && v1 < graph->vertex_num && v2 >= 0 && v2 < graph->vertex_num) {
        graph->matrix[v1][v2] = weight;
        graph->matrix[v2][v1] = weight;
    }
}
void printMatrix(AdjMatrixGraph *graph) {
    printf("\n");
    for (int i = 0; i < graph->vertex_num; i++) {
        for (int j = 0; j < graph->vertex_num; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}


int main() {
    AdjMatrixGraph graph;
    initGraph(&graph, 5);
    addEdge(&graph, 0, 1, 1);
    addEdge(&graph, 0, 2, 1);
    addEdge(&graph, 1, 3, 1);
    addEdge(&graph, 2, 4, 1);
    printMatrix(&graph);
    return 0;
}
