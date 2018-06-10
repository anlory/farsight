#include  <stdio.h>

int fun(int n){
      if( n == 0 || n == 1)
	    return 1;
      else
	    return n*fun(n-1);
}
