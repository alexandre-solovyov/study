
#include <stdio.h>
#include <math.h>

int main()
{
  double x1, x2, d, a = 0, b = -2, c = -3;

  if( a==0 )
  {
	 // bx + c = 0
	 if( b==0 )
	 {
		 // c = 0
		 if( c==0 )
			 // 0 = 0
			 printf( "Все числа являются корнями\n" );
		 else
			 // 1 = 0
			 printf( "Нет корней\n" );
	 }
	 else
	 {
		 x1 = -c/b;
		 printf( "x = %f\n", x1);
	 }
  }
  else
  {
	d= b*b - 4*a*c;
	if(d>=0)
	{
		x1 = (-b + sqrt(d))/(2*a);
		x2 = (-b - sqrt(d))/(2*a);
		printf("%f %f\r\n", x1, x2);
	}
	else
	{
		printf( "Действительных корней нет\n" );
	}	
  }

  return 0;
}
