#include<stdio.h>
#define true 1
#define false -1
#define MAXSIZE 20
typedef struct MyString{
	char ch[MAXSIZE];
	int lenght;
}MyString;

//串的暴力匹配
int Index(MyString main,MyString target){
	int i = 0, j = 0;
	while(i<main.lenght && j<target.lenght){
		if(main.ch[i] == target.ch[j]){
			//继续匹配
			i++;
			j++;
		}else{
			//主串索引回到初始+1的位置 注:i-j初始位置 j-j+1 初始位置进一
			i = i - j + 1;
			j = 0; //j从头开始匹配
		}
	}
	if(j==target.lenght){//j走到了比目标串还长的地方 说明是遍历完了还没遇到不同
		return i - target.lenght; //i-目标串的长度 就是他在主串里的起始处
	}
	return -1;//没找到
}
//KMP算法 S 主串 T模式串 next数组
int kmpIndex(MyString S,MyString T,int next[]){
	int i = 1, j = 1;
	while(i<=S.lenght && j<=T.lenght){
		if(j==0 || S.ch[i] ==T.ch[j]){
			//继续比较
			++i;
			++j;
		}
		else{
			//模式串移动
			j = next[j];
		}
	}
	if(j>T.lenght){
		return i - T.lenght;
	}
	return 0;
}
