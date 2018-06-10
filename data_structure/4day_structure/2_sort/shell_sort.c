#include <stdio.h>
#include <unistd.h>

#define N 10

void shell_sort(int a[]);
void show(int a[]);
int main(void)
{
    int a[]={50,36,66,76,95,12,25,36,24,8};

    show(a);
    shell_sort(a);
    show(a);
    return 0;
}

void shell_sort(int a[])
{
    int i,j;
    int tmp,d;
    for(d = N/2; d>0; d /= 2){
	//一趟排序
	for(i = d; i < N; i++){
	    tmp = a[i];
	    for(j = i-d;(j >= 0) && (a[j] > tmp);j -= d)
		a[j+d] = a[j];
	    a[j+d] = tmp;
	}
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
