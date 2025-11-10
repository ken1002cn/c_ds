#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50
typedef int ElementType;
typedef struct SqQueue{
	ElementType data[MaxSize];
	int front,rear;
}SqQueue;

void initQueue(SqQueue *p){
	p->rear = 0;
	p->front = 0;
}

int QueueisEmpty(SqQueue *p){
	return p->front == p->rear;
}

int Enqueue(SqQueue *p,ElementType x){
	//判断是否队满	
	if((p->rear+1) % MaxSize ==p->front){
		return 0;
	}
	p->data[p->rear] = x;
	p->rear = (p->rear+1) % MaxSize;
	return 1;
}

int DeQueue(SqQueue *p,ElementType *x){
	//判断是否队空
	if(p->rear == p->front){
		return 0;
	}
	*x = p->data[p->front];
	p->front = (p->front+1) % MaxSize;
	return 1;
}




