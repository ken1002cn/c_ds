#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//插入排序
void insertSort(int arr[],int len){
	int i,j;
	for(i = 2;i<=len;i++){
		//从小到大排序
		if(arr[i]<arr[i-1]){
			arr[0] = arr[i]; //用0当哨兵位
			for(j=i-1;arr[j]>arr[0];--j){
				//后退挪出位置
				arr[j+1] = arr[j];
			}
			//插入数据
			arr[j+1] = arr[0];
		}
	}	
}
//折半插入排序
void binaryInsertSort(int arr[],int len){
	int i,j,high,low,mid;
	for(i=2;i<=len;i++){
		arr[0] = arr[i]; //用0当哨兵位
		//在有序区间内折半查找
		low = 1;
		high = i-1;
		while(low<=high){
			mid = (low + high)/2;
				if(arr[0]>arr[mid]){
					//向右找
					low = mid+1;
				}else{
					//向左找
					high = mid-1;
				}
		}
	//循环退出时low就是要插入的地方 
	//这里如果i-1小于low的话 那说明low就在那个元素本来的位置上 不需要移动
	//如果i-1大于low的话 那么i-1就放在了i上 而i的元素又被arr[0]存了不会丢失 以此类推一直处理到low那个位置
	for(j=i-1;j>=low;j--){
		//把low到i-1个元素向前挪动
		arr[j+1] = arr[j];
	}
	//在low处插入
	arr[low] = arr[0];
	}	
}

int main(){
	int arr[] = {0,7,12,2,51,100};
//	insertSort(arr,5);
	binaryInsertSort(arr,5);
	for(int i=1;i<=5;i++){
		printf("%d,",arr[i]);
	}
}
