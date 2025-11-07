#include<stdio.h>
#define true 1
#define false -1
#define MAXSIZE 20
typedef int flag;
//顺序栈
typedef struct SqStack{
	int data[MAXSIZE];
	int top;//栈顶指针
}SqStack;

SqStack InitStack(SqStack* p){
	p->top = -1;
}

flag StackEmpty(SqStack* p){
	return p->top == -1;
}

flag push(SqStack* p,int element){
	if(p->top == MAXSIZE-1){
		printf("栈满");
		return false;
	}
	p->data[++p->top] = element;
	return true;
}
flag pop(SqStack* p,int* e){
	if(p->top == -1){
		printf("栈空");
		return false;
	}
	*e = p->data[p->top];
	p->top--;
	return true;
}

flag getTop(SqStack* q,int* e){
	if(q->top == -1){
			printf("栈空");
			return false;
	}
	*e = q->data[q->top];
	return true;
}
