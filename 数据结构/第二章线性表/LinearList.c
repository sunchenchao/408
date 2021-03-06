//第二章 顺序表->线性表 
//tip1: maybe vitural argument can use entail element
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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
void minDel(LinearList *ll);
void reverseSpaceO1(LinearList *ll);
void delAllx(LinearList	*ll,int n);
int delRange(LinearList *ll,int s,int t);
int delRe(LinearList *ll);
void midChange(LinearList *ll,int mid);
int binarySearch(LinearList *ll,int n);
void moveNum(LinearList *ll,int p);
void reverse(int *arr,int start,int end);
void moveNumStand(LinearList *ll,int p);
void moveNumOther(LinearList *ll,int p);
int  findMidNumber(LinearList *one,LinearList *two);
void selectSort(int *arr,int n);
int mainNumberTime(LinearList *ll);
int notAdventNum(LinearList	*ll);
void threeMin();
int three(int a,int b,int c);
void thecloseNum();
int standAnw();
int main(){
	LinearList arr,arr1;
	int a;
	initLinearList(&arr,10);
	initLinearList(&arr1,10);
	ListInsert(&arr,1,1);
	ListInsert(&arr,2,2);
	ListInsert(&arr,3,3);
	ListInsert(&arr,4,5);
	ListInsert(&arr,5,6);
	ListInsert(&arr,5,7);
	ListInsert(&arr,5,8);
	ListInsert(&arr,5,4);
	
	ListInsert(&arr1,1,2);
	ListInsert(&arr1,2,4);
	ListInsert(&arr1,3,6);
	
	ShowList(arr.data,arr.length);	
	//LinearDel(&arr,1);
	//minDel(&arr);
	//reverseSpaceO1(&arr);
	//delAllx(&arr,3);
	//delRange(&arr,1,4);
	//delRe(&arr);
	//midChange(&arr,4);
	//binarySearch(&arr,8);
	//moveNum(&arr,1);
	//moveNumStand(&arr,1);
	//moveNumOther(&arr,3);
	//printf("(%d)",findMidNumber(&arr,&arr1));
	//selectSort(arr.data,arr.length);
	//printf("%d",mainNumberTime(&arr));
	//printf("%d",notAdventNum(&arr));
	//threeMin();
	//thecloseNum();
	printf("%d",standAnw());
	ShowList(arr.data,arr.length);
	 //printf("%d\n",getIndex(arr,5));
	
	
}

// 综合应用题

// problem 1
void minDel(LinearList *ll){
	int minNumIndex,i;
	for(i=1;i<ll->length;i++){
		if(ll->data[minNumIndex]>ll->data[i]){
			minNumIndex = i;	
		}
	}
	ll->data[minNumIndex] = ll->data[ll->length-1];
	ll->length = ll->length - 1;
	ll->data[ll->length] = 0;
} 
//problem 2
//reverse space:O(1)
void reverseSpaceO1(LinearList *ll){
	int temp,i;
	for(i=0;i<(ll->length)/2;i++){
		temp = ll->data[i];
		ll->data[i] = ll->data[ll->length-1-i];
		ll->data[ll->length-1-i] = temp; 
	}	
}

//problem 3
// you should delete all n in array.
//time complexity O(n)
//space complexity O(1)
void delAllx(LinearList	*ll,int n){
	int i,count=0;
	for(i=0;i<(ll->length);i++){
		if(ll->data[i]!=n){
			ll->data[count] = ll->data[i];
			count++; 
		}	
	}
	ll->length = count; 
} 

//problem 4

// deleteing range form s to t
int delRange(LinearList *ll,int s,int t){
	int i;
	if(s>t){
		return -1;
	}
	if(s<=0||t>ll->length){
		return -1;
	}
	for(i = t-1;i<ll->length;i++){
		ll->data[s-1] = ll->data;
		s++; 
	}
	ll->length = ll->length-(t - s);
	return 1;
}

// problem 6
//  making number is't repeatly
int delRe(LinearList *ll){
	int *arr;
	int i,j,flag,length=0;
	arr = (int *)malloc(sizeof(int)*ll->length);
	for(i=0;i<ll->length;i++){
		flag = 1;
		for(j=0;j<length;j++){
			if(ll->data[i] == arr[j]){
				flag = 0;
				break;
			} 
		}
		if(flag == 1){
			arr[length] = ll->data[i];
			length++;
		}
	}
	free(ll->data); 
	ll->data = arr;		
}
//problem 7
// two to one
// no test
void twoToOne(LinearList *one,LinearList *two){
	int *arr;
	int i;
	arr = (int *)malloc(sizeof(int)*(one->length + two->length));
	one->length =  one->length + two->length;
	one->MaxSize = one->length + two->length;
	for(i=0;i<one->length;i++){
		arr[i] = one->data[i];
	}
	for(i=0;i<two->length;i++){
		arr[i+one->length] = two->data[i];
	}
	free(one->data);
	one->data = arr;
}

// problem 08
void midChange(LinearList *ll,int mid){
	int *arr;
	int i;
	arr = (int *)malloc(sizeof(int)*ll->length);
	for(i=0;i<mid;i++){
		arr[i] = ll->data[mid+i];
	}
	for(i=mid;i<ll->length;i++){
		arr[i] = ll->data[i-mid];
	}
	free(ll->data);
	ll->data = arr;
}

//problem 9
//Binary Search
//这个题目有个问题 如果是最后一个找到没有后继元素怎么办？ 
int binarySearch(LinearList *ll,int n){
	int mid,left,right,temp,i;
	left = 0;
	right = ll->length - 1;
	while(left<=right){
		mid = (left+right)/2;
		if(ll->data[mid]==n){
			temp = ll->data[mid];
			ll->data[mid] = ll->data[mid+1];
			ll->data[mid+1] = temp;
			
			return mid;
		}else if(ll->data[mid]>n){
			right = mid - 1;	
		}else{
			left = mid +1;
		}
	}
	for(i=0;i<ll->length;i++){
		if(n<ll->data[i]){
			ListInsert(ll,i+1,n);
			break;	
		}
	}
	return -1;
}
// problem 11
// time complexity O(n) space complexity O(1)
// 就是有点麻烦了 
void moveNum(LinearList *ll,int p){
	int i,j,count,temp;
	for(i=0;i<ll->length-p;i++){
		if(i<p){
			temp = ll->data[i];
			ll->data[i] =  ll->data[ll->length-p+i];
			ll->data[ll->length-p+i] = temp;	
		}else{
			for(j=0;j<p;j++){
				temp = ll->data[i-j];
				ll->data[i-j] = ll->data[i-j-1];
				ll->data[i-j-1] = temp; 
				
			}	
		}
	}
}
// standad answer
// AB -> BA   (A的逆+B的逆)的逆  ：这个就是一个算法
//利用到离散数学 
// start 输入的范围会影响你的写法
//我是从1开始
//答案按0开始 
//time complexity O(n) 
//space complexity O(1) 
void reverse(int *arr,int start,int end){
	int i,temp;
	start--;
	end--;
	for(i=0;i<(end - start+1)/2;i++){
		temp = arr[start+i];
		arr[start+i] = arr[end-i];
		arr[end-i] = temp;		
	}
} 
void moveNumStand(LinearList *ll,int p){
	reverse(ll->data,1,p);
	reverse(ll->data,p+1,ll->length);
	reverse(ll->data,1,ll->length);		
}
// 其他方法的实现 
void moveNumOther(LinearList *ll,int p){
	int *arr;
	int i,count=0;
	arr = (int *)malloc(sizeof(int)*p);
	for(i=0;i<p;i++){
		arr[i] = ll->data[i];
	}
	for(i=p;i<ll->length;i++){
		 ll->data[count++]=ll->data[i] ;
	}
	for(i=0;i<p;i++){
		ll->data[count++] =arr[i] ;
	}
}
// problem 11
//time complexity O(n)  
//space complexity O(1) 
int  findMidNumber(LinearList *one,LinearList *two){
	int i,mid,oneIndex=0,twoIndex=0,midNum;
	mid = (one->length+two->length)/2;
	for(i=0;i<mid;i++){
		if(oneIndex>one->length){
			midNum = two->data[twoIndex];
			twoIndex++;
		}else if(twoIndex>two->length){
			midNum = one->data[oneIndex];
			oneIndex++;	
		}else if(one->data[oneIndex]>two->data[twoIndex]){
			midNum = two->data[twoIndex];
			twoIndex++;
		}else{
			midNum = one->data[oneIndex];
			oneIndex++;
		}
	}
	return midNum;	
} 

// problem 12 
// 再计算 
void selectSort(int *arr,int n){
	int i,j,maxIndex,temp;
	for(i=0;i<n-1;i++){
		maxIndex = i;
		for(j=i+1;j<n;j++){
			if(arr[maxIndex]>arr[j]){
				maxIndex = j;
			}	
		}
		if(i!=maxIndex){
			temp = arr[i];
			arr[i] = arr[maxIndex];
			arr[maxIndex] = temp; 
		}
	}
} 
int mainNumberTime(LinearList *ll){
	int maxNum,nowNum,maxCount=0,nowCount=0,num,i;
	int *arr;
	arr = (int *)malloc(sizeof(int)*ll->length);
	selectSort(ll->data,ll->length);
	nowNum = ll->data[0];
	nowCount = 1;
	for(i=1;i<ll->length;i++){
		if(ll->data[i]==nowNum){
			nowCount++;
			if(nowCount>maxCount){
				maxCount = nowCount;
				maxNum = nowNum;
			}
		}else{
			nowCount = 1;
			nowNum =  ll->data[i];
		}	
	}
	if(maxCount>ll->length/2){
		return maxNum;
	}else{
		return -1;
	}
		
} 
//proble 13
int notAdventNum(LinearList	*ll){
	int i,num=1;
	selectSort(ll->data,ll->length);
	for(i=0;i<ll->length;i++){
		if(ll->data[i]>0){
			if((ll->data[i+1]-ll->data[i])>1){
				return ll->data[i]+1;
			} 
		}
	}
	return ll->data[ll->length-1]+1;
}
//standand anwser 
//tip：题目中只要求时间复杂度
int standAnw(){
	int arr[] = {
		1,2,3,4
	},*arr1,len,i;
	
	len = sizeof(arr)/sizeof(int);
	arr1 = (int *)malloc(sizeof(int)*len);
	memset(arr1,0,len);
	for(i=0;i<len;i++){
		if(arr[i]>0&&arr[i]<=len){
			arr1[arr[i]-1] = 1;	
		}
	}
	for(i=0;i<len;i++){
		if(arr1[i]==0){
			return i+1;
		}
	}
	return len + 1;
}



 
// problem 14 
// the worest method
void threeMin(){
	int s1[]={
	-1,0,9	
	},s2[]={
		-25,-10,10,11
	},s3[]={
		2,9,17,30,41
	},min,i,j,k,temp,a,b,c;
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			for(k=0;k<5;k++){
				if(i+j+k==0){
					a = s1[i];
					b = s2[j];
					c = s3[k]; 
					min = fabs(s1[i]-s2[j])+fabs(s2[j]-s3[k])+fabs(s3[k]-s1[i]);
				}else{
					temp = fabs(s1[i]-s2[j])+fabs(s2[j]-s3[k])+fabs(s3[k]-s1[i]);
					if(temp<min){
						a = s1[i];
						b = s2[j];
						c = s3[k]; 
						min = temp;
					}
				}
				
			}
		}
	}
	printf("%d,%d,%d,%d",a,b,c,min);
	
} 

// standand answer
// 控制三个数中最小的数向后+1位 然后去对比之间的差值 
// 也可以找三个数组中最接近的三个数    
int three(int a,int b,int c){
	if(a<b){
		if(a<c){
			return 1;
		}else{
			return 3;
		}	
	}else{
		if(b<c){
			return 2;
		}else{
			return 3;
		}
	}
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              	 
void thecloseNum(){
	int s1[]={
	-1,0,9	
	},s2[]={
		-25,-10,10,11
	},s3[]={
		2,9,17,30,41
	},i,alen,blen,clen,a,b,c,aa,bb,cc,acount=0,bcount=0,ccount=0,min,temp;
	alen = sizeof(s1)/sizeof(int);
	blen = sizeof(s2)/sizeof(int);
	clen = sizeof(s3)/sizeof(int);
	aa=a = s1[0];
	bb=b = s2[0];
	cc=c = s3[0];	
	min = fabs(a-b) + fabs(b-c) + fabs(c-a);
	while(acount<alen&&bcount<blen&&ccount<clen){
		//printf("-%d*",three(a,b,c));
		//printf("%d %d %d-",a,b,c);
		if(three(a,b,c)==1){
			a = s1[++acount];
			temp = fabs(a-b) + fabs(b-c) + fabs(c-a);
			if(min>temp){
				min = temp;
				aa = a;
				bb=b;
				cc=c;
			}
		}else if(three(a,b,c)==2){
			b = s2[++bcount];
			temp = fabs(a-b) + fabs(b-c) + fabs(c-a);
			if(min>temp){
				min = temp;
				aa = a;
				bb=b;
				cc=c;
			}
		}else{
			c = s3[++ccount];
			temp = fabs(a-b) + fabs(b-c) + fabs(c-a);
			if(min>temp){
				min = temp;
				aa = a;
				bb=b;
				cc=c;
			}
		}
	}
	printf("%d,%d,%d,%d",aa,bb,cc,min);
		
}
 

 