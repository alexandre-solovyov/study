
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
	
void sort( double* x, int n )
{
	int i, j;
	double m;
	for(i=0; i<n-1; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(x[i] < x[j])
			{
				m = x[i];
			    x[i]=x[j];
				x[j]= m;
			}	
		}
	}
}
	
double** sort2( double** A, int N, int M )
{
	int i;
	
	double** B = malloc( N*sizeof(double*) );
	for( i=0; i<N; i++)
	{
		B[i] = malloc( M*sizeof(double) );
		memcpy( B[i], A[i], sizeof(double)*M );
	}
	for(i=0; i<N; i++)
		sort( B[i], M );
	return B;
}

void print( double** x, int n, int m )
{
	int i, j;
	double a;
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			printf("%4.1f ", x[i][j] );
		}
		printf( "\n" );
	}
}

int f( int x )
{
	return x*x;
}

void f2( int* x )
{
	*x = 10;
}

int main()
{
	const int N=10, M=6;
	int i, j;
	double** A = malloc( N*sizeof(double*) );
	double** B;
	srand(time(0));
	for( i=0; i<N; i++)
	{
		A[i] = malloc( M*sizeof(double) );
		for( j=0; j<M; j++ )
			A[i][j] = rand()%100;
	}
	
	print( A, N, M );
	B = sort2( A, N, M );
	printf( "\n" );
	print( B, N, M );
	return 0;
}
