#include <stdio.h>

#define N  12

void show_search(int a[]);
int search_bin(int key,int a[]);
int main(void)
{
	int a[] = {3,12,18,20,32,55,60,68,80,86,90,100};
	int  ret,key;
	show_search(a);
	while(1){
		printf("请输入关键字key:");
		scanf("%d",&key);
		ret = search_bin(key,a);
		if(ret == -1)
			printf("要查找的关键字%d不在顺序表中!\n",key);
		else{
			printf("要查找的关键字%d在顺序表的第%d个位置!\n",key,ret);
		}
	}
	return 0;
}

int search_bin(int key,int a[])
{
	int low,high,mid;

	low = 0;
	high = N-1;
	while(low <= high){
		mid = (low + high)/ 2;
		if(a[mid] == key)
			return mid;
		else if(a[mid] > key)
			high = mid -1;
		else
			low = mid + 1;
	}
	return -1;
}

void show_search(int a[])
{
	int i;
	for(i = 0; i < N; i++)
		printf("%d\t",a[i]);
	printf("\n");
}
