#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* p;
	int	n = 20, i;
	p = malloc(n * sizeof(int));
	p[1] = 1;
	p[2] = 1;
	for(i=3; i<n; i++ )
	  p[i] = p[i-1] +p[i-2];
  	for(i=1; i<n; i++ )
      printf("%i ", p[i]);
    
}
