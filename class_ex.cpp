
#include <stdio.h>
#include <math.h>

class Number
{
public:
  double module() { return -1; }
};


class Integer : public Number // наследование
{
public:
  double module()
  {
	return fabs(q);
  }
  
  int get() { return q; }
  void set( int u )
  {
	  if( u>100 )
		q = 100;
	  else
		q = u;
  }

private:
  int q;
};


class Real : public Number // наследование
{
public:
  double module()
  {
	return fabs(q);
  }
  
private:
  double q;
};

class Gaussian : public Number // наследование
{
public:
  double module()
  {
	return sqrt( a*a + b*b );
  }
  
private:
  int a, b;
};

class Complex : public Number // наследование
{
public:
  Complex( double x, double y ) { a = x; b = y; }

  double module()
  {
	return sqrt( a*a + b*b );
  }
  
private:
  double a, b;
};

int main()
{
	Number n;
	
	Integer i;
	i.set(-10);
	printf( "%f\n", i.module() );
	
	Complex c( 1, 2 );
	printf( "%f\n", c.module() );

	return 0;
}
