#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void quickSort(int arr[],int start,int end){
	if(start<end){
			//第一个元素为枢轴
			int base = arr[start];
			int left = start;
			int right = end;
		while(left<right){
			//right从右边出发，寻找小于base的放到left 如果当前right指向的大于base就往前走
			while(left<right && base <= arr[right]){
				right--;
			}
			//此时要么right指向一个小于base的数 要么他就指向了base 这种情况说明base已经是最小的了
			arr[left] = arr[right];
			//left从左边出发 寻找大于base的数放到left 如果当前left指向小于base则往后走
			while(left<right && base>=arr[left]){
				left++;
			}
			arr[right] = arr[left];
		}
		//此时left=right 插入base
		arr[left] = base;
		//递归排序base的左侧子集 和右侧子集 这就是分治法
		quickSort(arr,start,left-1);
		quickSort(arr,left+1,end);
	}
}

int main(){
	int arr[] = {5,4,3,2,1};
	quickSort(arr,0,4);
	for(int i=0;i<5;i++){
		printf("%d,",arr[i]);
	}
}
