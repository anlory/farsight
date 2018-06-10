#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stu{
      int sno;
      char name[20];
      float score;
}STU;

int main(int argc,char **argv)
{
      FILE *write_fp;
      //打开文件
      if(argc != 2){
	    fprintf(stderr,"Usage:%s <file>\n",argv[0]);
	    exit(1);
      }
      write_fp = fopen(argv[1],"w");
      if(write_fp == NULL){
	    perror("fopen");
	    exit(1);
      }
      //向文件中写数据
#if 0
      char str[] = "farsight";
      fwrite(str,2,3,write_fp);

      int a[] = {1,2,3,4,5};
      fwrite(a,sizeof(int),5,write_fp);
#else
      STU st[] = {{1001,"zhangsan",96.7},{1002,"lisi",98.2},{1003,"wangwu",91.7}};
      fwrite(st,sizeof(STU),3,write_fp);
#endif
      //关闭文件
      fclose(write_fp);
      return 0;
}
