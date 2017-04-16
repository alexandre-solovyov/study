
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int* p;
	int N=1000, i,K;
	p = malloc(N * sizeof(int));
	p[0] = 0;
	p[1] = 0;
	for( i=2; i<N; i++ )
		p[i] = i;
	
	for( i=2; i<N; i++ )
		if( p[i] != 0 )
		{
			for(K=2*i; K<N; K+=i)
				p[K] = 0;
				
			//for(K=0; K<N; K++)
			//  if( K>i && K%i==0 )
		}
	
	for( i=2; i<N; i++ )
		if( p[i] != 0)
			printf("%i,",p[i]);
		
	free(p);
}
