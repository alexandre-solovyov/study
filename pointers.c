
#include <stdio.h>
#include <stdlib.h>

int main()
{	
  int n = 10, i;
  int* ptr1;
  
  printf( "%i\n", sizeof(int));
  printf( "%i\n", sizeof(float));
  printf( "%i\n", sizeof(double));
  
  ptr1 = malloc( n * sizeof(int) );
  for( i=0; i<n; i++ )
	  ptr1[i] = (i+1)*(i+1);
  
  printf( "addr = %u\n", ptr1 );
  printf( "addr 0-th item = %u\n", &ptr1[0] );
  printf( "value 0-th item = %u\n", ptr1[0] );
  printf( "addr 1-th item = %u\n", &ptr1[1] );
  printf( "value 1-th item = %u\n", ptr1[1] );
  printf( "addr 2-th item = %u\n", &ptr1[2] );
  printf( "value 2-th item = %u\n", ptr1[2] );
  printf( "addr 3-th item = %u\n", &ptr1[3] );
  printf( "value 3-th item = %u\n", ptr1[3] );
  printf( "addr + 1 = %u\n", ptr1+1 );
  
  return 0;
}
