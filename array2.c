
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print( int* p, int len )
{
	int i;
	for( i=0; i<len; i++ )
		printf( "%i ", p[i] );
	printf( "\n" );
}

int max( int* p, int len )
{
	int i, m=p[0];
	for(i=0; i<len; i++)
		if(m < p[i])
			m=p[i];
	return m;
}

int sq( int x )
{
	return x*x;
}

float tr(float x, float y, float z)
{
	float p=(x+y+z)/2;
	return sqrt(p*(p-x)*(p-y)*(p-z));
}


float tr1(float a, float b, float h)
{
	float s;
	s = (a+b)/2 * h;
	return s;
}

int fact( int n )
{
	int i, k=1;
	for(i=1;i <= n; i++)
		k *= i;
	return k;
}

int fact2( int n )
{
	if( n<=0 )
		return 1;
	return fact2(n-1)*n;
}




int main()
{
	int a[5] = { 1, 3, 5, 10, 15 };
	int b[6] = { 3, 7, 10, 20, 30, 40 };
	int *c = malloc(10*sizeof(int));
	int j;
	for(j=0; j<10; j++)
		c[j] = 2*j+1;
	print( a, 5 );
	print( b, 6 );
	print( c, 10 );
	printf( "max=%i\n", max(a, 5) );
	printf( "max=%i\n", max(b, 6) );
	printf( "max=%i\n", max(c, 10) );
	sq(10);
	printf( "s=%f\n", tr(3, 4, 5) );
	printf( "fact=%i\n", fact(5));
	printf( "fact=%i\n", fact2(5));
	return 0;
}
