
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* f = fopen( "capitals", "r" );
	char* s, *r;
	char c[] = "Paris";
	
	s = malloc(100);

	while( !feof(f) )
	{
		//printf( "a\n" );
		r = fgets( s, 100, f );
		//printf("r=%s\n", r);
		if( r )
		{
			s[strlen(s)-2] = 0;
			//printf( "s=%s; %i;", s, strlen(s) );
			//printf( "c=%s;\n", c );
			if(!strcmp(c, s))
				printf( "found: %s", s );
		}
	}
	
	fclose( f );
}
