
#include <stdio.h>

#define clear() printf("\033[H\033[J")
#define cursor(x,y) printf("\033[%d;%dH", (x), (y))

void table( int n )
{
	if( n==1 )
	{
		cursor( 1, 5*1 );
		printf( "1" );
		return;
	}
	table( n-1 );
	for( int i=1; i<=n; i++ )
	{
		cursor( n, 5*i );
		printf( "%i", n*i );
		cursor( i, 5*n );
		printf( "%i", n*i );
	}
}

int main()
{
	clear();
	table(10);
	return 0;
}
