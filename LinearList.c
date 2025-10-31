#include<stdio.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define maxsize 100
typedef int status;
typedef int elemType;
//线性表结构
typedef struct LinearList{
	int data[maxsize];
	int length;
}LinearList;

//创建线性表
status initList(LinearList *list){
	int temp;
	list->length=0;
	for(int i=0;i<maxsize;i++){
		printf("请输入第%d个元素的值,输入-1退出\n",i+1);
		scanf("%d",&temp);
		if(temp==-1){
			printf("成功退出线性表构建");
			return OK;
		}
		list->data[i] = temp;
		list->length++;
	}
	return OK;
}

status getLenght(LinearList *list){
	return list->length;
}
//除了操作数组外，一切位置都是逻辑位置
status insertList(LinearList *list,int i, elemType element){
	if(i < 1 || i>list->length + 1){
		printf("数据插入位置不合法\n");
		return ERROR;
	}
	if(list->length>=maxsize){
		printf("数据超过表最大限制\n");
		return ERROR;
	}
	for(int j = list->length-1;j>=i-1;j--){
		list->data[j+1] = list->data[j];
	}
	list->data[i-1] = element;
	list->length++;
	printf("插入成功\n");
	return OK;
}

status printList(LinearList *list){
	for(int i=0;i<list->length;i++){
		printf("第%d个数据是%d\n",i+1,list->data[i]);
	}
	return OK;
}

status deleteByIndex(LinearList *list,int index){
	if(index>list->length||index<1){
		printf("数据删除位置不合法\n");
		return ERROR;
	}
	if(index!=list->length){
		for(int i=index-1;i<list->length-1;i++){
			list->data[i] = list->data[i+1];
		}
	}
	//如果是最后一个元素 直接length--就能处理
	list->length--;
	return OK;
}
//按逻辑位置取值
int getElem(LinearList *list,int index){
	return list->data[index-1];
}
//按值查找逻辑位置
int locateElem(LinearList *list,int element){
	for(int i=0;i<list->length;i++){
		if(list->data[i]==element){
			return i+1;
		}
	}
	printf("未找到%d",element);
	return -1;
}
//清空线性表
status clearList(LinearList *list){
	list->length = 0;
	return OK;
}
