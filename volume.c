#include <stdio.h>
#include <math.h>
#define pi 3.14159265
#define EPS 1E-4

double disc(double rad)
{
	return pi * pow(rad, 2);
}

double cone(double r, double h)
{
	return disc(r) * h / 3;
}

double cyl(double r, double h)
{
	return disc(r) * h;
}

double cut_cone(double r1, double r2, double h)
{
	if( fabs(r1-r2)<EPS )
	{
		return cyl(r1, h);
	}
	else
	{
		double h2 = (r1*h) / (r2-r1);
		//S2 - S1
		return cone(r2, h+h2) - cone(r1, h2);
	}
}

double f(double x)
{
	return x*x;
}

//Объявление указателя на функцию
// typedef -- объявить новый тип
// 1-й double -- возвращаемое значение
// * -- нужна, чтобы сказать, что это указатель
// F -- имя типа (мы выбрали сами)
// 2-й double -- аргумент функции
// получился указатель на любую функцию, которая имеет
// ровно 1 аргумент double и возвращает double
typedef double (*F)(double x);

double sum1( F func, double a, double b, double dx )
{
	double x;
	double s = 0;
	for(x=a; x<b; x+=dx)
	{
		s += func(x)*dx;
	}
	return s;
}

double sum2( F func, double a, double b, double dx )
{
	double x;
	double s = 0;
	for(x=a; x<b; x+=dx)
	{
		s += func(x + dx)*dx;
	}
	return s;
}

double area( F func, double a, double b )
{
	double dx = 1;
	double s1, s2;
	do
	{
		s1 = sum1( func, a, b, dx );
		s2 = sum2( func, a, b, dx );
		dx = dx/2;
	}
	while( fabs(s1-s2) > EPS );
	printf("dx=%.6f\n", dx);
	return (s1+s2)/2;
}



// Площадь треугольника по трем сторонам
double triangle1( double a, double b, double c )
{
	return 0; //TODO
}

// Площадь треугольника по координатам трех вершин
double triangle2( double x1, double y1, 
				  double x2, double y2, 
                  double x3, double y3 )
{
	return 0; //TODO
}

// N -- количество точек
// p -- таблица координат ( x1, y1, x2, y2, ... )
double polygon( int N, double* x, double* y )
{
	int i;
	double s = 0;
	for(i=1; i<N-1; i++)
	{
		// треугольник образован точками 0, i, i+1
		s += triangle2(x[0], y[0], x[i], y[i], x[i+1], y[i+1]);
	}
}

int main()
{
	printf("V=%f\n", cone(10, 11));
	printf("V=%f\n", cyl(10, 11));
	printf("V=%f\n", cut_cone(10, 11, 5));
	printf("V=%f\n", cut_cone(11, 10, 5));
	printf("S=%f\n", area( f, 0, 1 ) );
	printf("S=%f\n", area( sin, 0, pi ) );
}
