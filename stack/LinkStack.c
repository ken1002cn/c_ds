#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElemType int   //结点内数据类型

//链栈的结点
typedef struct StackNode
{
	ElemType data;          //数据域
	struct StackNode *next; //指针域
}StackNode;

void initStack(StackNode **p){
	*p = NULL;
}

//入栈
void Push(StackNode **p, ElemType x)
{
	//为栈结点分配空间
	StackNode *newNode = (StackNode*)malloc(sizeof(StackNode));
	newNode->data = x;
	newNode->next = *p; // 空栈时 *p 是 NULL，完全没问题
	*p = newNode;
}

ElemType pop(StackNode **p){
	if(*p==NULL){
		return -1;
	}
	StackNode *temp = (*p);
	ElemType data = temp->data;
	*p = (*p)->next;
	free(temp);
	return data;
}

void listStack(StackNode *p){
	if(p==NULL){
		printf("栈空");
		return;
	}
	StackNode *cur = p;
	while(cur){
		printf("%d",cur->data);
		cur = cur->next;
	}
}

bool IsEmpty(StackNode *p){
	return p==NULL;
}


