
#include <stdio.h>
#include <stdlib.h>

/*

void sum( float** a, int p, int q, float k )
// Сложить строку номер p со строкой номер q умноженной на k и
// положить результат в строку номер p
{
	
}

float det( float **a, int n )
{
	int i;
	float k;
	for(i=0; i<n; i++)
		// Ищем ненулевой элемент в первом столбце
		if( a[i][0] != 0 )
		{
			// Нашли
			// Пробегаем по всем строкам, кроме i
			for(j=0; j<n; j++)
				if( i!=j )
				{
					k = a[j][0] / a[i][0];
					sum( a, j, i, -k );
				}
			swap( a, i, n-1 );
			return det( a, n-1 );
		}
		
	return 0;
}

*/

float det( float** a )   // только 2x2
{
	return a[0][0] * a[1][1] - a[0][1] * a[1][0];
}

void solve( float** a, float* b, float* xy )    // только 2x2
{
	float dx, dy, d;
	float* F[] = { 0, 0 };
	
	d = det( a );
	
	F[0] = b;
	F[1] = a[1];
	dx = det( F );

	F[0] = a[0];
	F[1] = b;
	dy = det( F );
	
	if( d!=0 )
	{
		xy[0] = dx/d;
		xy[1] = dy/d;
		return;
	}
}

void intersect( float xa, float ya, float xb, float yb,
                float xc, float yc, float xd, float yd )
{
	float** a = malloc(2*sizeof(float));
	float b[2], tu[2], t, u, xx, yy;
	int i;
	for(i=0; i<2; i++)
		a[i] = malloc(2*sizeof(float));
	
	a[0][0] = xb-xa;
	a[0][1] = yb-ya;
	a[1][0] = xc-xd;
	a[1][1] = yc-yd;
	b[0] = xc-xa;
	b[1] = yc-ya;
	
	solve( a, b, tu );
	
	t = tu[0];
	u = tu[1];
	
	xx = xa*(1-t) + xb*t;
	yy = ya*(1-t) + yb*t;
}


void main()
{
	float** a = malloc(2*sizeof(float));
	int i;
	for(i=0; i<2; i++)
		a[i] = malloc(2*sizeof(float));
	
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 2;
	a[1][1] = 1;
	float b[] = { 4, 5 };
	float xy[2];
	
	solve( a, b, xy );
	
	printf( "%f %f\n", xy[0], xy[1]);
}
