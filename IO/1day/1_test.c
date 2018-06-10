#include <stdio.h>
#include <stdlib.h>

int main(void)
{
      FILE *read_fp,*write_fp;
      int sno;
      char name[20];
      float score;
      
      read_fp = fopen("2.txt","r");
      if(read_fp == NULL){
	    perror("fopen");
	    exit(1);
      }
      write_fp = fopen("3.txt","w");
      if(write_fp == NULL){
	    perror("fopen");
	    exit(1);
      }
      //scanf("%d%s%f",&sno,name,&score);
      fscanf(read_fp,"sno=%d\tname=%s\tscore=%f",&sno,name,&score);
      printf("%d\t%s\t%f\n",sno,name,score);
      fprintf(write_fp,"%d\t%s\t%f\n",sno,name,score);
      return 0;
}
