#include<stdio.h>
#define true 1
#define false -1
#define MAXSIZE 20
typedef int ElementType;
typedef int flag;
//顺序栈
typedef struct SqStack{
	ElementType data[MAXSIZE];
	int top;//栈顶指针
}SqStack;

SqStack initStack(){
	SqStack s;
	s.top = -1;
	return s;
}

flag stackEmpty(SqStack* p){
	return p->top == -1;
}

flag push(SqStack* p,ElementType element){
	if(p->top == MAXSIZE-1){
		printf("栈满");
		return false;
	}
	p->data[++p->top] = element;
	return true;
}
flag pop(SqStack* p,ElementType* e){
	if(p->top == -1){
		printf("栈空");
		return false;
	}
	*e = p->data[p->top];
	p->top--;
	return true;
}
//边表的节点
typedef struct ArcNode{
	int adjVex; //这条边指向的顶点
	struct ArcNode *next; //指向下一个节点的指针
}ArcNode;

//邻接表描述的图
typedef struct Graph_tabel{
	int vertex_num; //顶点数
	int directed; //是否是有向图 1==是 0==否
	ArcNode *adj[MAXSIZE]; //边表的数组 注意这个数组的下标实际上就是顶点名 0，1，2，3，4
}Graph_tabel;

flag topologicalSort(Graph_tabel Graph){
	//初始化辅助栈用于存储入度为0的节点
	SqStack stack = initStack();
	int indegree[MAXSIZE]; //存储对应节点的入度
	int sequence[MAXSIZE];
	//记录所有节点的度
	for(int i=0;i<Graph.vertex_num;i++){
		for(ArcNode* p=Graph.adj[i];p!=NULL;p = p->next){
			indegree[p->adjVex]++; //入度！ 如是i++那就是出度了
		}
	}
	//将所有0度节点入栈
	for(int i=0;i<Graph.vertex_num;i++){
		if(indegree[i] == 0){
			push(&stack,i);
		}
	}
	int count = 0; //记录排序的顺序
	//栈不空 说明还有度为0的节点
	while(!stackEmpty(&stack)){
		int temp;
		//栈顶元素出栈
		pop(&stack,&temp);
		//访问这个元素
		sequence[count++] = temp;
		//去掉这个节点所有的边 即让所有与他相邻的节点度减1
		for(ArcNode* p=Graph.adj[temp];p!=NULL;p = p->next){ //让p等于这个元素的第一个边 然后逐步推进
			indegree[p->adjVex]--; //度减一
			if(indegree[p->adjVex]==0){
				//如果减1了他的度变成0 则入栈
				push(&stack,p->adjVex);
			}
		}
	}
	if(count<Graph.vertex_num){
		//没有遍历到所有节点 说明没有进行足够的入栈操作 因为没有节点的度为0 说明存在环路
		return false;
	}else{
		printf("拓扑排序成功");
		for(int i=0;i<=count;i++){
			printf("%d",sequence[i]);
		}
		return true;
	}
}

