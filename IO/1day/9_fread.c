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
      FILE *read_fp;
     //打开文件
      if(argc != 2){
	    fprintf(stderr,"Usage:%s <file>\n",argv[0]);
	    exit(1);
      }
      read_fp = fopen(argv[1],"r");
      if(read_fp == NULL){
	    perror("fopen");
	    exit(1);
      }
      //从文件中读数据
      STU st[5];
      int i;
      fread(st,sizeof(STU),3,read_fp);
      for(i = 0; i < 3; i++)
	    printf("%d\t%s\t%f\n",st[i].sno,st[i].name,st[i].score);
      //关闭文件
      fclose(read_fp);
      return 0;
}
