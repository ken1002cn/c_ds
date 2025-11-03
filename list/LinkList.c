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
void pushBack(SListNode *p,int element){
	if(p==NULL){
		return;
	}
	SListNode* newNode = createNode(element);
	SListNode* cur = p;
	while(cur->next){
		cur = cur->next;
	}
	cur->next = newNode;
}
int getLen(SListNode* p){
	int len = 0;
	while(p->next){
		p = p->next;
		len++;
	}
	return len;
}
int getElem(SListNode* p,int index){
	SListNode* cur = p->next;
	int j = 1;
	while(cur && j<=index){
		if(j == index){
			return cur->data;
		}
		j++;
		cur = cur->next;
	}
	 return -1;
}

int LocatElem(SListNode* p,int element){
	SListNode* cur = p->next;
	while(cur){
		if(cur->data == element){
			return cur->data;
		}
		cur = cur->next;
	}
	return -1;
}

int ListInsert(SListNode* p,int index,int element){
	SListNode* cur = p;
	int i = 0;
	while(cur && i<index){
		if(i == index-1){ //找到要插入位置的前驱了
			SListNode* newNode = createNode(element);
			if(cur->next == NULL){
				//直接插入
				cur->next = newNode;
				return 1;
			}else{
				newNode->next = cur->next;
				cur->next = newNode;
				return 1;
			}
		}
		cur = cur->next;
		i++;
	}
	return -1;
}
int deleteNode(SListNode* p,int index){
	SListNode* cur = p;
	int i = 0;
	while(cur && i<index){
		if(i == index-1){ //找到要删除位置的前驱了
			if(cur->next == NULL){
				//前驱后面没东西了 说明越界了 跳出循环
				break;
			}
				SListNode* q = cur->next;
				cur->next = q->next;
				free(q);
				return 1;
		}
		cur = cur->next;
		i++;
	}
	return -1;
}

