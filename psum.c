
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

const int N = 10000;
const int T = 4;
double* arr;

void* sum( void* q )
{
	double s = 0;
	int* d = (int*)q;
	int a = d[0];
	int b = d[1];
	for( int i=a; i<=b; i++)
		s += arr[i];

	//printf( "Thr: %i, %i, %f\n", a, b, s );
	
	double* res = malloc( sizeof(double) );
	*res = s;
	return res;
}

int main()
{
	arr = malloc( N*sizeof(double) );
	
	for( int i=0; i<N; i++)
		arr[i] = i+1;

	int s = N/T;
	pthread_t TH[T];
	int d[2*T];
	for( int i=0; i<T; i++ )
	{
		d[2*i] = s*i;
		if( i==T-1 )
			d[2*i+1] = N-1;
		else
			d[2*i+1] = d[2*i]+s-1;
		pthread_create( &TH[i], NULL, sum, d+2*i );
	}

	double summ = 0;
	for( int i=0; i<T; i++)
	{
		void* res;
		pthread_join( TH[i], &res );
		summ = summ + *(double*)res;
	}
	
	printf( "Summ = %.1f\n", summ );
	
	free( arr );
}

