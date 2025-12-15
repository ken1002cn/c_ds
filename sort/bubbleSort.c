#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void bubbleSort(int arr[],int len){
	int i,j,temp;
	for(i=0;i<len-1;i++){
		for(j=0;j<len-i-1;j++){
			if(arr[j]>arr[j+1]){
				//½»»»
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
int main(){
	int arr[] = {5,4,3,2,1};
	bubbleSort(arr,5);
	for(int i=0;i<5;i++){
		printf("%d,",arr[i]);
	}
}
