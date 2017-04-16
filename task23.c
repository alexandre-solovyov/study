
#include <math.h>
#include <stdio.h>

void func_value()
{
	const double a=-3, b=3, dx=0.1;
	const int n = (b-a)/dx + 1;
	
	double x, q, y;
	double p[2][n];
	
	int i;
	double min, max;
	for(x=a, i=0; i<n; x=x+dx, i++)
	{
		q = 6*x-x*x;
		y = exp(q);
		p[0][i] = x;
		p[1][i] = y;
		
		if( i==0 )
		{
			min = y;
			max = y;
		}
		else
		{
			if(y>max)
				max=y;
			if(y<min)
				min=y;
		}
	}
	for(i=0; i<n; i++)
	{
		printf( "%.1f %.15f\n", p[0][i], p[1][i] );
	}
	printf("max=%.15f\nmin=%.15f\n", max, min);
}
	
void sort( double* x, int n )
{
	//TODO
	
}
	
void sort2( double** x, int n, int m )
{
	int i;
	for(i=0; i<n; i++)
		sort( x[i], m );
}
	
int main()
{
	func_values();
}
