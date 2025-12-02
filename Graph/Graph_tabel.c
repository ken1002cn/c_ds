#include <stdio.h>
#include <stdlib.h>

#define MAXV 100   // 最大顶点数

//边表的节点
typedef struct ArcNode{
	int adjVex; //这条边指向的顶点
	struct ArcNode *next; //指向下一个节点的指针
}ArcNode;

//邻接表描述的图
typedef struct Graph_tabel{
	int vertex_num; //顶点数
	int directed; //是否是有向图 1==是 0==否
	ArcNode *adj[MAXV]; //边表的数组 注意这个数组的下标实际上就是顶点名 0，1，2，3，4
}Graph_tabel;

//图的初始化
void initGraph(Graph_tabel *graph,int vertex_num,int directed){
	graph->vertex_num = vertex_num;
	graph->directed = directed;
	//初始化所有边表为空
	for(int i=0;i<graph->vertex_num;i++){
		graph->adj[i] = NULL;
	}
}
//添加边
void addEdge(Graph_tabel *graph,int vertex_a,int vertex_b){
	if(vertex_a < 0 || vertex_a >= graph->vertex_num || vertex_b < 0 || vertex_b >= graph->vertex_num){
		printf("vertex out of boundary");
		return;
	}
	 //创建一个新的边节点
	ArcNode *node = (ArcNode*)malloc(sizeof(ArcNode));
	node->adjVex = vertex_b;
	node->next = graph->adj[vertex_a];
	//头插法
	graph->adj[vertex_a] = node;
	//如果是无向图还要给另一边也加上边节点
	if(graph->directed == 0){
		ArcNode *node2 = (ArcNode*)malloc(sizeof(ArcNode));
		node2->adjVex = vertex_a;
		node2->next = graph->adj[vertex_b];
		//头插法
		graph->adj[vertex_b] = node2;
	}
}
