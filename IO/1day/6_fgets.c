#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

int main(int argc,char **argv)
{
      FILE *read_fp;
      char str[SIZE];

      if(argc != 2){
	    fprintf(stderr,"Usage:%s <path_name>\n",argv[0]);
	    exit(1);
      }
      read_fp = fopen(argv[1],"r");
      if(read_fp == NULL){
	    perror("fopen");
	    exit(1);
      }

      //读文件
#if 0
      while(fgets(str,SIZE,read_fp) != NULL)
	    printf("%s",str);
#else
      while(fgets(str,SIZE,stdin) != NULL)
	    printf("%s(%d)",str,strlen(str));
#endif	    

     return 0;
}
