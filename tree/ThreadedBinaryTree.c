#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int elementType;

//线索二叉树节点
typedef struct ThreadNode{
	elementType data;
	struct ThreadNode *lchild,*rchild;
	int ltag,rtag;//左右线索
}ThreadNode;

ThreadNode *pre = NULL;

void visit(ThreadNode *q){
	//如果左孩子为空 存储他的前驱
	if(q->lchild == NULL){
		q->lchild = pre;
		q->ltag = 1;
	}
	//如果前驱没有右孩子 给前驱的右孩子设置成线索指向本节点
	if(pre!=NULL && pre->rchild == NULL){
		pre->rchild = q;
		pre->rtag = 1;
	}
	pre = q;
}

//中序线索化二叉树
void InThread(ThreadNode *T){
	if(T!=NULL){
		InThread(T->lchild);
		visit(T);
		InThread(T->rchild);
	}
}
//主函数
void CreateInThread(ThreadNode *T){
	pre = NULL;
	if(T!=NULL){
		InThread(T);
		pre->rtag =1; //中序遍历的结尾必然没有右孩子 也没有后继
	}
}
