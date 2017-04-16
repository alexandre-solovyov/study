#include<stdio.h>

int main()
{
	int N=100, a, b, m=0, p, i;
	int A = 1000;

	for(a=0; a<=N; a++)
		if(a%3)
			m=m+a;
	printf("sum = %i\n", m);
	
	printf( "Task 2\n");
	for(a=0; a<=A; a++)
		if(a%2)
		{
			m=a*a*a;
			if(m>=A)
				break;
			printf("%i\n", m);
		}
	
	printf( "Task 3\n");
	p = 10;
	for( i=1; i<=p; i++ )
		if(p%i==0)
			printf( "%i\n", i );
	
	printf( "Task 4\n");	
	for(a=0; a<=N; a++)
	{
		for(b=a; b<=N; b++)
		{
			if(a*a+b*b==N)
				printf("%i %i\n", a, b);
		}
	}
	
	printf( "%10.3f", 113.14159265 );	
}
