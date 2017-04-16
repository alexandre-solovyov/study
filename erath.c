
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

const int N = 100000000;
const int P = 4;
char* q;

pthread_mutex_t writem;

typedef struct 
{
	int i;
	int a;
	int b;
} range;

void* erath1( void* arg )
{
	range r = *(range*)arg;
	printf( "Thread %i started\n", r.i );
	//printf( "%i %i %i\n", r.i, r.a, r.b );
	int i, j;
	for( i=r.a; i<=r.b; i++ )
	{
		//if( r.i==0 )
		//	printf( "%i\n", i );
		//pthread_mutex_lock( &writem );
		char c = q[i];
		//pthread_mutex_unlock( &writem );
		if( c != 0 )
		{
			for( j=i*2; j<N; j=j+i )
			{
				//printf( "%i\n", j );
				//pthread_mutex_lock( &writem );
				q[j] = 0;
				//pthread_mutex_unlock( &writem );
			}
		}
	}
	printf( "Thread %i finished\n", r.i );
    return NULL;
}

int gI = 2; 
void* erath2( void* arg )
{
	printf( "Thread started\n" );
	int i = gI, j;
	while( i < N )
	{
		char c = q[i];
		//printf( "%i\n", i );
		if( c != 0 )
		{
			for( j=i*2; j<N; j=j+i )
			{
				//pthread_mutex_lock( &writem );
				q[j] = 0;
				//pthread_mutex_unlock( &writem );
			}
		}
		//pthread_mutex_lock( &writem );
		gI++;
		i = gI;
		//pthread_mutex_unlock( &writem );
	}
	printf( "Thread finished\n" );
	return NULL;
}

int erath_p()
{
	pthread_mutex_init( &writem, NULL );
	
	q = malloc( N );
	memset( q, 1, N );
	q[0] = 0;
	q[1] = 0;
	
	pthread_t TH[P];
	range ind[P];
	int NS = N/P;
	for( int j=0; j<P; j++ )
	{
		ind[j].i = j;
		ind[j].a = NS*j;
	    ind[j].b = NS*(j+1)-1;
		if( j==0 )
			ind[j].a = 2;
		if( j==P-1 )
			ind[j].b = N-1;
	} 
	for(int i=0; i<P; i++)
		pthread_create( &TH[i], NULL, erath1, ind+i );

	for(int i=0; i<P; i++)
	{
		pthread_join( TH[i], NULL );
		printf( "join %i\n", i );
	}

	printf( "count\n" );
	int count = 0;
	for(int i=0; i<N; i++)
		if( q[i]!=0 )
		{
			count++;
			//printf( "%i, ", i );
		}
	free( q );
	return count;
}

int erath_p2()
{
	pthread_mutex_init( &writem, NULL );
	
	q = malloc( N );
	memset( q, 1, N );
	q[0] = 0;
	q[1] = 0;
	
	pthread_t TH[P];
	for(int i=0; i<P; i++)
		pthread_create( &TH[i], NULL, erath2, NULL );

	for(int i=0; i<P; i++)
	{
		pthread_join( TH[i], NULL );
		printf( "join %i\n", i );
	}

	printf( "count\n" );
	int count = 0;
	for(int i=0; i<N; i++)
		if( q[i]!=0 )
		{
			count++;
			//printf( "%i, ", i );
		}
	free( q );
	return count;
}

int erath_s()
{
	char* q = malloc( N );
	memset( q, 1, N );
	q[0] = 0;
	q[1] = 0;
	
	printf( "Search...\n" );
	for(int i=2; i<N; i++)
		if( q[i] != 0 )
		{
			for( int j=i*2; j<N; j=j+i )
				q[j] = 0;
		}

	int count = 0;
	for(int i=0; i<N; i++)
		if( q[i]!=0 )
		{
			count++;
			//printf( "%i, ", i );
		}
	free( q );
	return count;
}

int main()
{
	printf( "How many primes\n" );

	//int count = erath_s();
	//int count = erath_p();
	int count = erath_p2();
	printf( "Number of primes: %i\n", count );
}
