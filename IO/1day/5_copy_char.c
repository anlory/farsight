#include <stdio.h>
#include <stdlib.h>

//int main(void)
int main(int argc,char **argv)
{
      FILE *read_fp,*write_fp;
      char ch; 
      //打开文件
      if(argc != 3){
	    fprintf(stderr,"Usage:%s <src_file> <des_file>\n",argv[0]);
	    exit(1);
      }
      read_fp = fopen(argv[1],"r");
      if(read_fp == NULL){
	    perror("fopen");
	    exit(1);
      }
      write_fp = fopen(argv[2],"w");
      if(write_fp == NULL){
	    perror("fopen");
	    exit(1);
      }
      //拷贝文件
      while((ch = fgetc(read_fp)) != EOF){
	    putchar(ch);
	    fputc(ch,write_fp);
      }
      //关闭文件
      fclose(read_fp);
      fclose(write_fp);
      return 0;
}
