

typedef struct
{
	double x;
	double y;
} point;


double random_double( double r )
{
	const int N = 1000;
	int x = rand()%N;
	double a = 2*R/N;
	double b = -R;
	double y = a*x + b;
	return y;
}

point random_point( double r )
{
	point p;
	p.x = random_double( r );
	p.y = random_double( r );
	return p;
}
