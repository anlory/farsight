#include <stdio.h>
#include <stdlib.h>

int main(void)
{
      FILE *read_fp;
      char ch;

      read_fp = fopen("1.txt","r");
      if(read_fp == NULL){
	    perror("fopen");
	    exit(1);
      }
#if 0
      while((ch = fgetc(read_fp)) != EOF)
	    fputc(ch,stdout);
#else
      while((ch = fgetc(stdin)) != EOF)
	    fputc(ch,stdout);
#endif
#if 0
      write_fp = fopen("3.txt","w");
      if(write_fp == NULL){
	    perror("fopen");
	    exit(1);
      }
#endif
      return 0;
}
