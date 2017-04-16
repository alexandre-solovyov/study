#include<stdlib.h>
#include<stdio.h>

int main()
{
	int a, b, c, n, i;
	int *y, *z;
	
	a = 6;  // in the 1st array
	b = 9;  // in the 2nd array
	c = 3;  // common elements
	n = a+b-c;
	y = malloc( n * sizeof(int) );
	z = y + (a-c);
	
	for(i=0; i<a; i++)
	{
		y[i] = 2*i + 1;
		printf("%i ", y[i]);
	}
	
	printf("\n");

	for(i=0; i<b; i++)
	{
		//printf("%i ", z[i]);   //   *(z+i)
		printf("%i ", *(z+i));   //   *(z+i)
	}

	free(y);
	return 0;
}
