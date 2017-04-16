
#include <stdio.h>

int main()
{
	int s[] = { 1, 10, 5, 3, 7, 8, 15, 20, 13 };
	int i, n, m, j, k, t;
	
	n = sizeof(s)/sizeof(int);
	
	for( i=0; i<n; i++ )
	{
		// Ищем самый маленький
		m = s[i];
		k = i;
		for( j=i+1; j<n; j++ )
			if( s[j]<m )
			{
				m = s[j];
				k = j;
			}
		// самый маленький элемент стоит на месте k
		// мы меняем его местами с i-м
		t = s[i];
		s[i] = s[k];
		s[k] = t;
	}
	
	for( i=0; i<n; i++ )
		printf( "%i ", s[i] );
	printf( "\n" );
	
	return 0;
}

