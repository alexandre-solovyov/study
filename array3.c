
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int n = 20, i;
	int* p;
	
	p = malloc( n*sizeof(int) );
	for( i=0; i<n; i++)
	{
		p[i] = 2*i;
		printf( "%i ", p[i] );
	}
	printf( "\n" );
	
	p = realloc( p, 2*n*sizeof(int) );
	for( i=0; i<n; i++ )
		printf( "%i ", p[i] );
	printf( "\n" );
	
	free(p);
}
