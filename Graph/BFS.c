#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// 邻接表节点
typedef struct Node {
	int vertex;
	struct Node* next;
} Node;

// 图结构
typedef struct Graph {
	int numVertices;
	Node* adjLists[MAX];
	int visited[MAX];
} Graph;

// 队列结构
typedef struct Queue {
	int items[MAX];
	int front;
	int rear;
} Queue;


// 创建队列
Queue* createQueue() {
	Queue* q = malloc(sizeof(Queue));
	q->front = -1;
	q->rear = -1;
	return q;
}

int isEmpty(Queue* q) {
	return q->rear == -1;
}

void enqueue(Queue* q, int value) {
	if (q->rear == MAX - 1) return; // 满队列检查
	
	if (q->front == -1) q->front = 0;
	
	q->rear++;
	q->items[q->rear] = value;
}

int dequeue(Queue* q) {
	int item;
	if (isEmpty(q)) return -1;
	
	item = q->items[q->front];
	q->front++;
	
	// 清空队列的判断
	if (q->front > q->rear) {
		q->front = q->rear = -1;
	}
	return item;
}


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

// 创建邻接表结点
Node* createNode(int v) {
	Node* newNode = malloc(sizeof(Node));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}

// 添加边（无向图）
void addEdge(Graph* graph, int src, int dest) {
	Node* node = createNode(dest);
	node->next = graph->adjLists[src];
	graph->adjLists[src] = node;
	
	node = createNode(src);
	node->next = graph->adjLists[dest];
	graph->adjLists[dest] = node;
}


// BFS 实现
void BFS(Graph* graph, int startVertex) {
	Queue* q = createQueue();
	
	// 起点入队
	graph->visited[startVertex] = 1;
	enqueue(q, startVertex);
	
	while (!isEmpty(q)) {
		//出队 访问它
		int current = dequeue(q);
		printf("%d ", current);
		
		Node* temp = graph->adjLists[current];
		//遍历它的边表 让他们入队	
		while (temp != NULL) {
			int adj = temp->vertex;
			
			if (!graph->visited[adj]) {
				graph->visited[adj] = 1;
				enqueue(q, adj);
			}
			temp = temp->next;
		}
	}
}

int main() {
	Graph* graph = createGraph(5);
	
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	
	printf("BFS starting from vertex 0:\n");
	BFS(graph, 0);
	
	return 0;
}

