
#include <stdio.h>
#include <stdbool.h>

// 基础配置
#define MAX_VERTICES 100  // 最大顶点数
#define INF 999999        // 无边标识
#define QUEUE_SIZE 100    // BFS专用队列大小

// 1. BFS依赖的队列结构（仅为BFS服务）
typedef struct {
    int data[QUEUE_SIZE];
    int front, rear;
} Queue;

// 队列初始化
void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

// 入队（BFS核心步骤之一）
bool enQueue(Queue *q, int val) {
    if ((q->rear + 1) % QUEUE_SIZE == q->front) return false; // 队列满
    q->data[q->rear] = val;
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    return true;
}

// 出队（BFS核心步骤之一）
bool deQueue(Queue *q, int *val) {
    if (q->front == q->rear) return false; // 队列空
    *val = q->data[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE;
    return true;
}

// 2. BFS依赖的图结构（邻接矩阵）
typedef struct {
    char vertex[MAX_VERTICES];   // 顶点（0,1,2...）
    int matrix[MAX_VERTICES][MAX_VERTICES]; // 邻接矩阵
    int vertex_num; // 实际顶点数
} Graph;

// 图初始化（为BFS准备数据）
void initGraph(Graph *g, int n) {
    g->vertex_num = n;
    // 初始化顶点
    for (int i = 0; i < n; i++) g->vertex[i] = '0' + i;
    // 初始化无边
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g->matrix[i][j] = INF;
}

// 添加无向边（为BFS准备测试数据）
void addEdge(Graph *g, int v1, int v2) {
    if (v1 >= 0 && v1 < g->vertex_num && v2 >= 0 && v2 < g->vertex_num) {
        g->matrix[v1][v2] = 1; // 简化：边权固定为1
        g->matrix[v2][v1] = 1;
    }
}

// 🔴 单独的广度优先遍历（BFS）核心函数
void BFS(Graph *g, int start, bool visited[]) {
    Queue q;
    initQueue(&q);
    
    // 1. 访问起始顶点，标记已访问，入队
    printf("%c ", g->vertex[start]);
    visited[start] = true;
    enQueue(&q, start);
    
    // 2. 队列非空时，循环出队、访问邻接点
    while (q.front != q.rear) {
        int current;
        deQueue(&q, &current); // 出队当前顶点
        
        // 遍历所有邻接点
        for (int i = 0; i < g->vertex_num; i++) {
            if (g->matrix[current][i] != INF && !visited[i]) {
                printf("%c ", g->vertex[i]); // 访问邻接点
                visited[i] = true;           // 标记已访问
                enQueue(&q, i);              // 邻接点入队
            }
        }
    }
}

// 主函数（仅测试BFS）
int main() {
    Graph g;
    initGraph(&g, 5); // 5个顶点的图
    
    // 添加测试边（和DFS用同一图结构，方便对比）
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 2, 4);
    
    // 初始化访问标记（默认未访问）
    bool visited[MAX_VERTICES] = {false};
    
    // 执行BFS（从顶点0开始）
    printf("广度优先遍历结果：");
    BFS(&g, 0, visited);
    
    printf("\n");
    return 0;
}