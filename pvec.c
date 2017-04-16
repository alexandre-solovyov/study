
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int N = 3;

double* a;
double* b;
double* c;
int ind[3] = {0, 1, 2};
pthread_t TH[3];

void* summ(void* arg)
{
	int i = *(int*)arg;
	c[i] = a[i] + b[i];
	return NULL;
}

void add( double* a1, double* b1, double* c1 )
// Вычислить сумму векторов c = a + b
{
	//for(i=0;i<N;i++)
	//	c[i] = a[i] + b[i];

    a = a1;
	b = b1;
	c = c1;
	
	int i;
	for(i=0; i<N; i++)
		pthread_create( &TH[i], NULL, summ, ind+i );

	for(i=0; i<N; i++)
		pthread_join( TH[i], NULL );
}


void* square(void* arg)
{
	int i = *(int*)arg;
	double* p = malloc(sizeof(double));
	*p = a[i] * a[i];
	return p;
}


double len( double* a1 )
// Вычислить длину вектора a1
{
	
	int i;
	for(i=0; i<N; i++)
		pthread_create( &TH[i], NULL, square, ind+i );

	void* res;
	double s = 0;
	for(i=0; i<N; i++)
	{
		pthread_join( TH[i], &res );
		s = s + *(double*)res;
	}
	
	return sqrt(s);
}

int main()
{
	double* a = malloc( 3 * sizeof( double ) );
	double* b = malloc( 3 * sizeof( double ) );
	double* c = malloc( 3 * sizeof( double ) );
	
	a[0] = 1;
	a[1] = 5;
	a[2] = -3;

    b[0] = 3;
	b[1] = 4;
	b[2] = 10;

	add( a, b, c );
	for( int i=0; i<N; i++ )
		printf( "%.1f ", c[i] );
	printf( "\n" );
	
	printf( "len = %f\n", len(a) );
}
