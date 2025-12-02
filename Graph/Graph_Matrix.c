#include <stdio.h>
#include <stdlib.h>

#define MAXV 100   // 最大顶点数

//邻接矩阵表示图
typedef struct Graph_Matrix{
	int vertex_num; //顶点数
	int directed;  //是否有向 1有向 0无向
	int adj[MAXV][MAXV]; //邻接矩阵
}Graph_Matrix;

void init_Graph_Matrix(Graph_Matrix *graph,int vertex_num, int directed){
	graph->vertex_num = vertex_num;
	graph->directed = directed;
	//初始化邻接矩阵
	for(int i=0;i<graph->vertex_num;i++){
		for(int j=0;i<=graph->vertex_num;i++){
			graph->adj[i][j] = 0;
		}
	}
}

void addEdge(Graph_Matrix *graph,int vertex_a,int vertex_b, int weight){
	if(vertex_a < 0 || vertex_a >= graph->vertex_num || vertex_b < 0 || vertex_b >= graph->vertex_num){
		printf("vertex out of boundary");	
		return;
	}
	//添加边
	graph->adj[vertex_a][vertex_b] = weight;
	//如果是无向图 要添加一条对应的边
	if(graph->directed == 0){
		graph->adj[vertex_b][vertex_a] = weight;
	}
	
}
