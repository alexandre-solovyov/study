



#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <pthread.h>

const int P = 4;
const int N = 100;
double V[N*3];
double L[N];


typedef struct 
{
	int a;
	int b;
} index;


void* lleng(void* arg)
{
	index s = *(index*)arg;
    for( int i=s.a; i<=s.b; i++ )
    {
		double x, y, z;
		x = V[3*i];
		y = V[3*i+1];
		z = V[3*i+2];
		double len = sqrt( x*x + y*y + z*z );
		L[i] = len;
    }
    return NULL;
}

int main()
{
	pthread_t TH[P];
	index ind[P];
	int NS = N/P;
	for( int j=0; j<P; j++ )
	{
		ind[j].a = NS*j;
	    ind[j].b = NS*(j+1)-1;
		if( j==P-1 )
			ind[j].b = N-1;
	} 
	for(int i=0; i<P; i++)
	{
		pthread_create( &TH[P], NULL, llong, ind+i );
	}

	void* res;
	for(int i=0; i<P; i++)
		pthread_join( TH[P], &res );
	return 0;

}
