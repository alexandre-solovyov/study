
#include <math.h>
#include <stdio.h>

void find( int n )
{
	for( int a=0; a<=n; a++)
		for( int b=0; b<=n; b++)
		{
			if( a*a + b*b == n )
				printf( "%i %i\n", a, b );
		}
}

void find2( int n )
{
	int ns = (int)floor(sqrt( n ));
	
	for( int a=0; a<=ns; a++)
		for( int b=0; b<=ns; b++)
		{
			if( a*a + b*b == n )
				printf( "%i %i\n", a, b );
		}
}

void find3( int n )
{
	int ns = (int)floor(sqrt( n/2 ));
	
	for( int a=0; a<=ns; a++)
	{
		int b = (int)sqrt(n - a*a);
		if( a*a + b*b == n )
		{
			printf( "%i %i\n", a, b );
			printf( "%i %i\n", b, a );
		}
	}
}

int main()
{
	//find ( 100000 );
	//find2( 10000000 );
	//find3( 100000 );
}
