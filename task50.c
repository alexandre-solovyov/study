
#include <math.h>
#include <stdio.h>

double angle( double x1, double y1,
              double x2, double y2,
			  double x3, double y3 )
{
	double bax = x1 - x2;
	double bay = y1 - y2;
	double bcx = x3 - x2;
	double bcy = y3 - y2;
	
	double q = bax*bcy - bcx*bay;
	if( q==0 )
		printf( "On the line\n");
	
	double ba = sqrt( bax*bax + bay*bay );
	double bc = sqrt( bcx*bcx + bcy*bcy );
	double p = bax*bcx + bay*bcy;
	if( ba==0 || bc==0 )
	{
		printf( "Angle cannot be calculated\n" );
		printf( "On the line\n");
		return 0;
	}
	
	double cos_b = p / ( ba*bc );
	double b = acos(cos_b);
	b = b/M_PI*180;
	return b;
}

int main()
{
	printf( "%f\n", angle( 0, 0, 5, 10, 20, 10 ) );
	printf( "%f\n", angle( 0, 0, 1, 3, 3, 9 ) );
	printf( "%f\n", angle( 1, 1, 1, 1, 3, 5 ) );
}
