#include <stdio.h>
#include <time.h>

int main(void)
{
      time_t tm;
      struct tm *tp;

      time(&tm);
      printf("tm = %ld\n",tm);
      printf("%s",ctime(&tm));
      tp = localtime(&tm);
      printf("%d-%d-%d  %d:%d:%d\n",tp->tm_year+1900,tp->tm_mon+1,\
		  tp->tm_mday,tp->tm_hour,tp->tm_min,tp->tm_sec);
      printf("%s",asctime(tp));
      return 0;
}
