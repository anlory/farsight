#include <stdio.h>

#define N 8

void quick_sort(int,int,int a[]);
int quick_pass(int i,int j,int a[]);
void show(int a[]);
int main(void)
{
    int a[]={50,36,66,76,36,12,25,95};

    show(a);
    quick_sort(0,N-1,a);
    show(a);
    return 0;
}

//每一趟找基准的过程
int quick_pass(int i,int j,int a[])
{
    int tmp;
    tmp = a[i];
    while(i < j){
	while(i < j && a[j] >= tmp)
	    j--;
	if(i < j)
	    a[i] = a[j];
	while(i < j && a[i] <= tmp)
	    i++;
	if(i < j)
	    a[j] = a[i];
    }
    a[i] = tmp;
    return i;
}

//快速排序
void quick_sort(int low,int high,int a[])
{
    int mid;
    if(low < high){
	mid = quick_pass(low,high,a); //找基准,返回基准的下标
	quick_sort(low,mid-1,a);
	quick_sort(mid+1,high,a);
    }
}
void show(int a[])
{
    int i;
    for(i = 0; i < N; i++)
	printf("%d\t",a[i]);
    printf("\n");
}
