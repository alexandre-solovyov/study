
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>

const int N = 10000;
const int T = 4;
double x[10000];
double y[10000];

typedef struct 
{
	int num;
	int a;
	int b;
} index;

void* Nsin( void* q )
{
	int i, k;
	index w = *(index*)q;
	k = w.num;
	for( i = w.a; i <= w.b; i++ )
		y[i] = sin( x[i] );

	printf( "Thread N%i finished\n", k );
 	return NULL;
}

int main()
{
	int i, c;

	pthread_t TH[T];
	index ind[T];
	
	for(i=0; i<N; i++)
		x[i] = 0.01 * i;
	
	c = N/T;
	for( i=0; i<T; i++ )
	{
		ind[i].a = c*i;
		ind[i].b = c*(i+1)-1;
		ind[i].num = i+1;
		if( i==T-1 )
			ind[i].b = N-1;
		pthread_create( &TH[i], NULL, Nsin, ind+i );
	}
	
	void* res;
	for( i=0; i<T; i++ )
		pthread_join( TH[i], &res );
}
