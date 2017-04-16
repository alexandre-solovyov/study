
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i;
	srand(time(0));
	for( i=0; i<10; i++ )
		printf( "%i\n", rand()%100 );
}
