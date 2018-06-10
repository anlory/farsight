#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

int main(int argc,char **argv)
{
      FILE *read_fp,*write_fp;
      char str[SIZE];

      if(argc != 3){
	    fprintf(stderr,"Usage:%s <src_path_name> <des_path_name>\n",argv[0]);
	    exit(1);
      }
      read_fp = fopen(argv[1],"r");
      if(read_fp == NULL){
	    perror("fopen");
	    exit(1);
      }
      if( (write_fp = fopen(argv[2],"w")) ==NULL){
	    perror("fopen");
	    exit(1);
      }

      //拷贝文件
#if 1
      while(!feof(read_fp) && !ferror(read_fp)){
	    bzero(str,SIZE);
	    fread(str,1,SIZE,read_fp);
	    printf("%s",str);
	    fwrite(str,1,strlen(str),write_fp);
      }
#else
      while(fgets(str,SIZE,stdin) != NULL)
	    printf("%s(%d)",str,strlen(str));
#endif	    

     return 0;
}
