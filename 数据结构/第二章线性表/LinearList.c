//第二章 顺序表 
//tip1: maybe vitural argument can use entail element
#include<stdio.h>
#include<stdlib.h>
typedef struct LinearList{
	int *data;
	int MaxSize;//最大长度 
	int length;//默认长度 
}LinearList;
//初始化 
void initLinearList(LinearList *ll,int n){
	ll->data = (int *)malloc(sizeof(int)*n);
	ll->length = 0;
	ll->MaxSize = n;
	//数据初始化为0 
	//当然这边也是可以使用for循环去初始化
	memset(ll->data,0,n); 
}
//插入操作
//在ll中的第p位插入一个n 
int ListInsert(LinearList *ll,int p,int n){
	//判断数据的合法性
	int i;
	if(p<1||p>(ll->length+1)){// 1 to length + 1
		return 0;
	} 
	if((ll->length)>=(ll->MaxSize)){
		return 0;
	}
	for(i=(ll->length);p<=i;i--){
		ll->data[i] = ll->data[i-1];	
	}
	ll->data[p-1] = n;
	ll->length = ll->length + 1;
	return 1;
}
//delete method
// arr: target array
// n: deleted postion number 
int LinearDel(LinearList *ll,int n){
	int i,delNumber;
	delNumber = ll->data[n-1];
	if(n<1||n>(ll->length+1)){
		return 0;
	}
	for(i=n;i<ll->length;i++){
		ll->data[i-1] = ll->data[i];
	}
	ll->data[ll->length-1] = 0;
	ll->length = ll->length-1;
	return delNumber;
}
//using value finds identity value in array and returns index.
// ll is traget array
// n are finded number
// if number are not find return -1
int getIndex(LinearList ll,int n){
	int i;
	for(i=0;i<ll.length;i++){
		if(ll.data[i] == n){
			return i+1;
			//the number need added one.
		}
	}
	return -1;
}


void ShowList(int *arr,int n){
	int i=0;
	printf("---------\n");
	for(i=0;i<n;i++){
		printf("%d\n",arr[i]);
	} 
	printf("---------\n");
	
}

//That other method find number by postion dont writer.
//you can use arr[index] or first-address +sizeof(type)*(n-1)

int main(){
	LinearList arr;
	int a;
	initLinearList(&arr,10);
	ListInsert(&arr,1,1);
	ListInsert(&arr,2,2);
	ListInsert(&arr,3,3);
	ListInsert(&arr,1,4);
	ListInsert(&arr,2,5);
	ShowList(arr.data,10);	
	LinearDel(&arr,1);
	ShowList(arr.data,10);
	printf("%d\n",getIndex(arr,5));
	
}