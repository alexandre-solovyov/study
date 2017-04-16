
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* p;
	char* name;
	int age;
	int age0 = 1990;
	
	//printf( "test" );
	
	p = fopen("humans", "r"); 
	//printf( "%i", p );
	name = malloc(100);
	
	//printf( "b" );
	while(!feof(p))
	{
		//printf( "a" );
		if( fscanf( p, "%s %i", name, &age )==2 && age>=age0 )
			printf( "%s %i\n", name, age );
	}
	
	
	fclose(p);
	free(name);
}
