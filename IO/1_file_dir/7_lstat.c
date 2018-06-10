#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>



int main(int argc,char **argv)
{
      struct stat st;

      if(argc != 2){
	    fprintf(stderr,"Usage:%s <pathname>\n",argv[0]);
	    exit(1);
      }
      //获取文件属性
      if(lstat(argv[1],&st) < 0){
	    perror("lstat");
	    exit(1);
      }
      //打印文件的类型
      if(S_ISREG(st.st_mode))
	    printf("-");
      else if(S_ISDIR(st.st_mode))
	    printf("d");
      else if(S_ISCHR(st.st_mode))
	    printf("c");
      else if(S_ISBLK(st.st_mode))
	    printf("b");
      else if(S_ISFIFO(st.st_mode))
	    printf("p");
      else if(S_ISSOCK(st.st_mode))
	    printf("s");
      else 
	    printf("l");
      //打印文件的权限
      char str[] = "xwr-";
      int i;
      for(i = 8; i >= 0; i--){
	    if(st.st_mode & 1<<i)
		  printf("%c",str[i%3]);
	    else
		  printf("%c",str[3]);
      }
      printf("  ");
      //打印用户名和组名
      struct passwd *pw;
      struct group *gr;
      pw = getpwuid(st.st_uid);
      gr = getgrgid(st.st_gid);
      printf("%s %s\t",pw->pw_name,gr->gr_name);
      //打印文件的大小
      printf("%ld\n",st.st_size);
      return 0;
}
