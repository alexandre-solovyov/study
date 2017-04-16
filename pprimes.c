
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

const int N = 100;
int primes[] = { 2, 3, 5, 7 };
const int S = sizeof(primes)/sizeof(int);
const int T = 4;

typedef struct 
{
	int num;
	int a;
	int b;
} index;

int is_prime( int x )
{
	for(int i=0; i<S; i++)
	{
		if( x==primes[i] )
			return 1;
	    if( x%primes[i]==0 )
			return 0;
	}
	return 1;
}

void* Nprimes( void* q )
{
	int i, k;
	index w = *(index*)q;
	k = w.num;
	
	//printf( "Thread N%i started\n", k );
	usleep( 10000 );
	for( i = w.a; i <= w.b; i++ )
		if( is_prime( i ) )
			printf( "%i: %i\n", k, i );

	//printf( "Thread N%i finished\n", k );
 	return NULL;
}

int main()
{
	//for( int i=2; i<=N; i++ )
	//	if( is_prime( i ) )
	//		printf( "%i, ", i );
	//printf( "\n" );
	
	int i;
	pthread_t TH[T];
	index ind[T];
	
	int c = N/T;
	for( i=0; i<T; i++ )
	{
		ind[i].a = c*i;
		ind[i].b = c*(i+1)-1;
		ind[i].num = i+1;
		if( i==0 )
			ind[i].a = 2;
		if( i==T-1 )
			ind[i].b = N;
		pthread_create( &TH[i], NULL, Nprimes, ind+i );
	}	
	
	void* res;
	for( i=0; i<T; i++ )
		pthread_join( TH[i], &res );
	
}
