#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// 邻接表的结点
typedef struct Node {
	int vertex;
	struct Node* next;
} Node;

// 图结构
typedef struct Graph {
	int numVertices;
	Node* adjLists[MAX];   // 每个顶点的邻接表头指针 实际上这里就是节点数组里每个节点对应的边表
	int visited[MAX];      // 访问标记
} Graph;

// 创建图
Graph* createGraph(int vertices) {
	Graph* graph = malloc(sizeof(Graph));
	graph->numVertices = vertices;
	
	for (int i = 0; i < vertices; i++) {
		graph->adjLists[i] = NULL;
		graph->visited[i] = 0;
	}
	return graph;
}

// 创建邻接表节点
Node* createNode(int v) {
	Node* newNode = malloc(sizeof(Node));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}

// 添加边（无向图）
void addEdge(Graph* graph, int src, int dest) {
	// 添加 src -> dest
	Node* node = createNode(dest);
	node->next = graph->adjLists[src];
	graph->adjLists[src] = node;
	
	// 无向图还要加 dest -> src
	node = createNode(src);
	node->next = graph->adjLists[dest];
	graph->adjLists[dest] = node;
}

// DFS 实现
void DFS(Graph* graph, int vertex) {
	//访问起始节点
	graph->visited[vertex] = 1;
	printf("%d ", vertex);
	//拿到起始节点的链表头
	Node* temp = graph->adjLists[vertex];
	while (temp != NULL) {
		int adj = temp->vertex;
		//如果没被访问 则递归下去
		if (!graph->visited[adj]) {
			DFS(graph, adj);
		}
		temp = temp->next;
	}
}

int main() {
	Graph* graph = createGraph(5);
	
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	
	printf("DFS starting from vertex 0:\n");
	DFS(graph, 0);
	
	return 0;
}

