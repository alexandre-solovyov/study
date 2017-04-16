
#include <stdio.h>

int main()
{
  int a = 2;
  int b = 10;
  int q = 1;
  int s = 0;
  int i;
  
  for( i=0; i<=b; i++, q=q*2 )
  {
	  if( i<a )
		  continue;
	  s = s + q;
  }
  
  printf( "%i", s );
}
