#include <stdio.h>

#define N 8

void bin_sort(int a[]);
void show(int a[]);
int main(void)
{
    int a[]={50,36,66,76,95,12,25,36};

    show(a);
    bin_sort(a);
    show(a);
    return 0;
}


//折半插入排序
void bin_sort(int a[])
{
    int i,j,low,high,mid;
    int tmp;

    for(i = 1; i < N; i++){
	tmp = a[i];
	//用折半查找算法寻找插入位置
	for(low = 0,high = i-1;low <= high;){
	    mid = (low + high)/2;
	    if(tmp <= a[mid])
		high = mid -1;
	    else
		low = mid + 1;
	}
	//将从low开始的记录依次向后移动一个位置
	for(j = i; j > low ;j--)
	    a[j] = a[j-1];
	//将tmp插入到low的位置
	a[low] = tmp;

    }
}


void show(int a[])
{
    int i;
    for(i = 0; i < N; i++)
	printf("%d\t",a[i]);
    printf("\n");
}
