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

//以下为练习题
void task01(LinearList *list){
	if(list->length==0){
		printf("表为空");
		return;
	}
	int min = 0;
	for(int i=1;i<list->length;i++){
		if(list->data[i]<list->data[min]){
			min = i;
		}
	}
	if(min!=list->length-1){
		list->data[min] = list->data[list->length-1];
	}
	list->length--;
}

void task02(LinearList *list){
	if(list->length==0){
		printf("表为空");
		return;
	}
	int temp;
	for(int i=0;i<list->length/2;i++){
		temp = list->data[i];
		list->data[i] = list->data[list->length-1-i];
		list->data[list->length-1-i] = temp;
	}
}
void task03(LinearList *list,int x){
	if(list->length==0){
		printf("表为空");
		return;
	}
	int k = 0; //设x是不等于x的元素数量
	for(int i=0;i<list->length;i++){
		if(list->data[i]!=x){
			list->data[k] = list->data[i];
			k++;
		}
	}
	list->length = k;
}
void task04(LinearList *list,int s,int t){
	if(list->length==0){
		printf("表为空");
		return;
	}
	if(s>=t){
			printf("上下限位置不合法");
			return;
	}
	int k = 0; //是不需要被删除的元素数量
	for(int i=0;i<list->length;i++){
		if(list->data[i]<s || list->data[i]>t){
			list->data[k++] = list->data[i];
		}
	}
	list->length = k;
}
//设有序表
void task05(LinearList *list){
	if(list->length==0){
		printf("表为空");
		return;
	}
	int i,j;
	for(i=0,j=1;j<list->length;j++){
		if(list->data[i]!=list->data[j]){
			list->data[++i] = list->data[j];
		}
	}
	list->length = i+1;
}

void task06(LinearList *A,LinearList *B,LinearList *C){
	int i=0,j=0,k=0;
	while(i<A->length && j<B->length){
		if(A->data[i]>=B->data[j]){
			C->data[k++] = A->data[i++];
		}else{
			C->data[k++] = B->data[j++];
		}
	}
	while(i<A->length){
		C->data[k++] = A->data[i++];
	}
	while(j<B->length){
			C->data[k++] = B->data[j++];
		}
	C->length = k;
}

void task07_1Reverse(int arr[],int left, int right){
	int temp;
	while(left<right){
		temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		left++;
		right--;
	}
	}
void task07(int arr[],int m,int n){
	task07_1Reverse(arr,0,m+n-1);//所有元素先倒转
	task07_1Reverse(arr,0,m-1);//倒转前m个元素
	task07_1Reverse(arr,m,m+n-1);//倒转m-n之间的元素
}
int task08_binary_search(int arr[],int length,int x){
	int left=0,right = length-1;
	while(left<=right){
		int mid = (left+right)/2;
		if(arr[mid]==x){
			return mid;
		}
		if(arr[mid]>x){
			right = mid -1;
		}else{
			left = mid+1;
		}
	}
	return left;
}
void task08_exchange(int arr[],int pos){
	int temp;
	temp = arr[pos];
	arr[pos] = arr[pos+1];
	arr[pos+1] = temp;
}

void task08_insert(int arr[],int element,int pos,int length){
	if(pos != length){
			for(int i=length-1;i>=pos;i--){
						arr[i+1] = arr[i];
					}
	}
	arr[pos] = element;
}
void task08(int arr[],int length,int x){
	int pos = task08_binary_search(arr,length,x);
	//如果arr[pos] == x 说明找到了 反之是需要插入的下标
	if(pos!=length){//防止访问越界 因为可能是需要插入的情况，此时length=pos
		if(arr[pos]==x && pos!=length-1){//最后一个不用交换
			task08_exchange(arr,pos);
		}
	}
	if(arr[pos]!=x){
		//没找到这个数 插入他并保持有序
		task08_insert(arr,x,pos,length);
		length++;
	}
}
