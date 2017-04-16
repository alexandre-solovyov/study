
#include <stdio.h>

int nod( int a, int b )
{
	while(a>0 && b>0)
	{
		//printf( "%i %i ", a, b );
	if(a>b)
		a = a%b;
	else
		b = b%a;	
	}
	if(a==0)
		return b;
	else
		return a;
}

int nod2( int a, int b )
{
	while(1)
	{
		//printf( "%i %i ", a, b );
	if(a>b)
		a = a%b;
	else
		b = b%a;
	if( a==0 || b==0 )
		break;
	}
	if(a==0)
		return b;
	else
		return a;
}

int main( int argc, char** argv )
{
  int s, i;
  
  /*for( s = 0, i = 1; i <= 500; i++ )
  {
    s = s + i;
	//printf( "%i ", i );
  }*/
  
  s = 0; i = 1;
  while( i <= 500 )
  {
	s = s + i;
	i++;
  }
	  
  printf( "\n" );
  printf( "%i\n", s );
  
  
  printf( "%i\n", nod(15, 10));
  printf( "%i\n", nod2(15, 10));

  sum(a,prod(b,c)
  
  return 0;
}
