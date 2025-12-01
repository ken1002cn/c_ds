#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 50

int DST_Set[SIZE];
//初始化并查集
void Initial(int S[]){
	for(int i=0;i<SIZE;i++){
		S[i] = -1;
	}
}

int find(int S[], int x){
	while(S[x]>=0){
		x = S[x];
	}
	return x;
}

void Union(int S[],int root1,int root2){
	if(root1 == root2){
		return;
	}
	//将root2指向root1的根
	S[root2] = root1;
}
