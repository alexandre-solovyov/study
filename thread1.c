
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void* hello( void* arg )
{
	printf( "Start\n" );
	int q = *(int*)arg;
	printf( "%i\n", q );
	usleep( 1000000 * q );
	printf( "Finish\n" );
	return 0;
}

void* test( void* c )
{
	double n;
	double x = *(double*)c;
	n = x*x;
}

int main()
{
  printf( "In master thread\n" );
  pthread_t t1, t2, t3, t4;
  void* res;
  
  srand( time( 0 ) );

  int q1 = rand()%10;
  pthread_create( &t1, NULL, hello, &q1 );
  int q2 = rand()%10;
  pthread_create( &t2, NULL, hello, &q2 );
  int q3 = rand()%10;
  pthread_create( &t3, NULL, hello, &q3 );
  double q = 11;
  pthread_create( &t4, NULL, test, &q );
  pthread_join( t1, &res );
  pthread_join( t2, &res );
  pthread_join( t3, &res );
  pthread_join( t4, &res );
  
  
  return 0;
}
