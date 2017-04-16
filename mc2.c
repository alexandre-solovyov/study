#include <stdio.h>
#include <stdlib.h>
#include <time.h>


double R = 2;
int N = 1000;


typedef struct
{
	double x;
	double y;
} point;


double random_double( double r )
{

	int x = rand()%N;
	double a = 2*R/N;
	double b = -R;
	double y = a*x + b;
	return y;
	printf("%d", y);
}

point random_point( double r )
{
	point p;
	p.x = random_double( r );
	p.y = random_double( r );
	return p;
}




int main ()
{
	int all = 100000;
  int inside;
  double area = 4*R*R;
  double area2 = 3.14159265 * R*R;
	for(int j = 0; j <= all; j++)
  {
		point p = random_point(R); 
    if(p.x*p.x + p.y*p.y <= R*R)
    	inside++;
  }
  
  double S; 
  S = area * inside / all;
  printf("Exact: %.3f\n", area2);  
  printf("Approx: %.3f\n", S);  
  return S;
}