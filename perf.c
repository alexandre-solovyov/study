
#include <time.h>
#include <stdio.h>
#include <math.h>

double current_time()
{
  struct timespec t;
  clock_gettime( CLOCK_REALTIME, &t );
  return t.tv_sec + t.tv_nsec / 1.0e9;
}

double sqrt2( double a )
{
	double x = a;
	for( int i=0; i<10; i++ )
		x = (x + a/x)/2;
	return x;
}

void test1()
{
	double t1 = current_time();
	double s = 0;
	for( int i=0; i<1000000; i++ )
	{
		s = s + sqrt(i);
	}
	double t2 = current_time();
	printf( "Time = %f sec\n", t2-t1 );
}

void test2()
{
	double t1 = current_time();
	double s = 0;
	for( int i=0; i<1000000; i++ )
	{
		s = s + sqrt2(i);
	}
	double t2 = current_time();
	printf( "Time2 = %f sec\n", t2-t1 );
}

int main()
{
	test1();
	test2();
}
