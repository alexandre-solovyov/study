
#include <stdio.h>

int a[] = { 1, 2, 3, 4, 5 };
int b[][2] = { {1, 2}, {3, 4}, {5, 6} };

int main()
{
	int i;
	for( i=0; i<100; i=i+1 )
	{
		if( i%2==0 )
			continue;
		printf( "%i,", i);
	}
	
	switch( i )
	{
		case 0:
		break;
		case 1:
		break;
		case 20:
		break;
	}
	
	
	return 0;
}
