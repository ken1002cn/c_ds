#include <stdio.h>
#include <stdlib.h>
typedef struct SListNode
{
	int data;
	struct SListNode* next;//存放下一个结点的地址
 
}SListNode;

// 初始化有头结点的单链表
SListNode* initSList(){
	SListNode* head = (SListNode*)malloc(sizeof(SListNode));
	head->next = NULL;
	return head;
}

//打印链表
void SListPrint(SListNode* phead)
{
	SListNode* cur = phead->next;//一般不直接移动头指针，而是创建一个指针变量来移动 这里跳过了头节点
	while (cur)//当指针为空时结束循环
	{
		printf("%d->", cur->data);//打印该结点的数据
		cur = cur->next;//将指针指向下一个结点
	}
	printf("NULL\n");
}

SListNode* createNode(int data){
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->data = data;
	node->next = NULL;
	return node;
}
