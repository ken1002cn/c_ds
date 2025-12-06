typedef int elementType;
typedef struct SSTable{
	elementType elem[10];
	int TableLen;
}SSTable;

elementType Binary_search(SSTable tabel,elementType key){
	int low = 0, high = tabel.TableLen-1, mid;
	while(low<=high){
		mid = (low + high) / 2;
		if(tabel.elem[mid] == key){
			//找到
			return mid;
		}
		if(tabel.elem[mid]>key){
			//当前查找的比目标大
			high = mid-1;
			continue;
		}
		if(tabel.elem[mid]<key){
			low = mid+1;
			continue;
		}
	}
	return -1;
}
