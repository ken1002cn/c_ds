#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LinkNode{
	ElementType data;
	struct LinkNode* next;
}LinkNode;

typedef struct LinkQueue{
	LinkNode *front,*rear;
}LinkQueue;

void initQueue(LinkQueue *p){
	//建立头节点
	p->front = (LinkNode*)malloc(sizeof(LinkNode));
	p->rear = p->front;
	p->front->next = NULL;
}
int queueIsEmpty(LinkQueue *p){
	return p->front == p->rear;
}

void enQueue(LinkQueue *p,ElementType x){
	LinkNode *newNode = (LinkNode*)malloc(sizeof(LinkNode));
	newNode->data = x;
	newNode->next = NULL;
	p->rear->next = newNode;
	p->rear = newNode;
}

int deQueue(LinkQueue *p,ElementType *x){
	if(p->front == p->rear){
		printf("空队列");
		return 0;
	}
	LinkNode *temp = p->front->next;
	*x = temp->data;
	p->front->next = temp->next;
	//检查要出队的是不是队尾元素 即最后一个元素
	if(temp == p->rear){
		//重置队尾指针指向头指针
		p->rear = p->front;
	}
	free(temp);
	return 1;
}
