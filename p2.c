
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, a, i;
	int* p;
	int q[] = { 10, 20, 30, 40, 50 };
	
	/*printf( "Введите размер:\n" );
	scanf( "%i", &n );
	
	p = malloc( n*sizeof(int) );
	for(a=0; a<n; a++)
	{
		p[a] = a*a*a;
		//*(p+5) = a*a*a;
	}
	
	for(a=0; a<n; a++)
		printf( "%i ", p[a] );
	
	printf( "\n" );*/
	p = q+2;
	q[2] = 100;
	for(i=0; i<3; i++)
		printf( "%i ", p[i-1] );
		
	//free(p);
}
