#include <stdio.h>
#include <unistd.h>

#define N 8

void seq_sort(int a[]);
void show(int a[]);
int main(void)
{
    int a[]={50,36,66,76,95,12,25,36};

    show(a);
    seq_sort(a);
	printf("排序之后的记录为：\n");
    show(a);
    return 0;
}

void seq_sort(int a[])
{
    int i,j;
    int tmp;

    for(i = 1; i < N; i++){
	tmp = a[i]; //将待插入的记录临时存入tmp中
	//在已排好序的记录中寻找tmp位置
	for(j = i-1;(j >= 0) && (a[j] > tmp);j--)
	    a[j+1] = a[j];
	//j+1的位置就是插入tmp的位置
	a[j+1] = tmp;
	printf("第%d次:",i);
	show(a);
	sleep(1);
    }
}
void show(int a[])
{
    int i;
    for(i = 0; i < N; i++)
	printf("%d\t",a[i]);
    printf("\n");
}
