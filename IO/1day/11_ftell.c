#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

int main(int argc,char **argv)
{
      FILE *read_fp;
      long len;

      if(argc != 2){
	    fprintf(stderr,"Usage:%s <path_name>\n",argv[0]);
	    exit(1);
      }
      if( (read_fp = fopen(argv[1],"r")) == NULL){
	    perror("fopen");
	    exit(1);
      }
      
      //读文件
#if 0
      for(i = 0; i < 3; i++){
	    ch = fgetc(read_fp);
	    putchar(ch);
      }
#else
      fseek(read_fp,-3,SEEK_END);
      printf("%c",fgetc(read_fp));
      len = ftell(read_fp);
      printf("len = %ld\n",len);
#endif
      return 0;
}
