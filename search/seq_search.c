typedef struct SSTable{
	int elem[10];
	int len;
}SSTable;

//顺序查找
int Seq_Search(SSTable tabel,int key){
	tabel.elem[0] = key; //设置哨兵
	int i;
	for(i=tabel.len;tabel.elem[i]!=key;i--);//注意这里雷点是不能让循环体执行 只是让i跑
	return i;
} 
