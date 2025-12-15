#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//shell排序
void shellSort(int arr[],int len){
	int i,j,step;
	for(step = len/2;step>=1;step = step/2){
		for(i=step+1;i<=len;i++){ 
			if(arr[i]<arr[i-step]){
				//需要移动元素
				arr[0] = arr[i];//暂存arr[i]
				//在由step构成的小集合里移动元素
				for(j=i-step;j>0 && arr[0]<arr[j];j=j-step){ //只有j的位置大于0且j大于那个要移动的元素才执行
					//逐步后移 找到插入点
					arr[j+step] = arr[j];
				}
				//插入那个暂存的元素(退出循环后实际上在插入位置又减了一回step 所以要加回去)
				arr[j+step] = arr[0];
			}
		}
	}	
}

//shell排序 无哨兵版
void shellSortB(int arr[],int len){
	int i,j,step,temp;
	for(step = len/2;step>=1;step = step/2){
		for(i=step;i<len;i++){ 
			if(arr[i]<arr[i-step]){
				//需要移动元素
				temp = arr[i];//暂存arr[i]
				//在由step构成的小集合里移动元素
				for(j=i-step;j>=0 && temp<arr[j];j=j-step){
					//逐步后移 找到插入点
					arr[j+step] = arr[j];
				}
				//插入那个暂存的元素(退出循环后实际上在插入位置又减了一回step 所以要加回去)
				arr[j+step] = temp;
			}
		}
	}	
}
int main(){
	int arr[] = {0,7,12,2,51,100};
	shellSort(arr,5);
	for(int i=1;i<=5;i++){
		printf("%d,",arr[i]);
	}
}
