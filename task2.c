
#include <stdio.h>
#include <math.h>

float f( float x )
{
	return pow(x,2)*7 + 3/x - pow(x, 4.0/5.0) + 8/pow(x,3);
}

int main()
{
	float min;
	float max;
	float a = 0.55;
	float b = 1.55;
	float step = 0.05;
	float x, y;
	
	min = f(a);
	max = min;
	for(x=a; x<=b; x+=step)
	{
		y = f(x);
		printf( "%10.3f  %10.3f\n", x, y );
		if(min>y)
			min=y;
		if(max<y)
			max=y;
		
	}
	printf( "min=%f max=%f\n", min, max );
	return 0;
}
