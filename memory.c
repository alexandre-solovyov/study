
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int x;
	int* p = malloc(100);
	printf( "%u\n", p );
	printf( "%u\n", &x );
	free(p);
	
	return 0;
}
