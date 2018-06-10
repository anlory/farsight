#include <stdio.h>

#define N 8

void bubble_sort(int a[]);
void show(int a[]);
int main(void)
{
    int a[]={50,36,66,76,95,12,25,36};

    show(a);
    bubble_sort(a);
    show(a);
    return 0;
}

void bubble_sort(int a[])
{
    int i,j;
    int tmp,flag;
    for(i = 0; i < N-1; i++){
	flag = 1;
	for(j = 0; j< N-1-i; j++)
	    if(a[j] > a[j+1]){
		tmp = a[j];
		a[j] = a[j+1];
		a[j+1] = tmp;
		flag = 0;
	    }
	if(flag)
	    break;
    }
}
void show(int a[])
{
    int i;
    for(i = 0; i < N; i++)
	printf("%d\t",a[i]);
    printf("\n");
}
