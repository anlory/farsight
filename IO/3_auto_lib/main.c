#include <stdio.h>
int fun(int);

int main(void)
{
      int n;
      printf("请输入n:");
      scanf("%d",&n);
      printf("n! = %d\n",fun(n));
      return 0;
}
