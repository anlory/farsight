#include <stdio.h>
#include <stdlib.h>

int main(void)
{
      //char str[] = "1001 wangwu 98.7";
      //char str[100];
      char str[] = "10:20";
      int sno = 1006;
      char name[20] = "Lily";
      float score = 92.4;
      int h,m;
      
#if 0
      //sscanf(str,"%d%s%f",&sno,name,&score);
      //sprintf(str,"sno = %d  name = %s score = %f",sno,name,score);
      //sprintf(str,"%d  %s %f",sno,name,score);
      //printf("%s\n",str);
      //printf("%d\t%s\t%f\n",sno,name,score);
     // fprintf(write_fp,"%d\t%s\t%f\n",sno,name,score);
#else
      sscanf(str,"%d:%d",&h,&m);
      printf("%d\t%d\n",h,m);
      printf("%d\n",h*100+m);
#endif
      return 0;
}
