
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char VOWELS[] = "aeiou";

// 0 -- гласная
// 1 -- согласная
int type( char c )
{
	if( strchr( VOWELS, c ) == 0 )
		return 1;
	else
		return 0;
}

int syllabes( char* verb )
{
	int i,q, s=0;
	q=strlen(verb);
	for(i=0; i<q; i++)
		if(type(verb[i])==0)
			s++;
	return s;
}

char* pr_cont( char* verb )
{
	int len = strlen( verb );
	char last = verb[len-1];
	//printf( "%c\n", last );
	//printf( "%i\n", len );
	int dbl=0;
	
	if( syllabes(verb)==1 )
	{
		if(    type(verb[len-1])==1
		    && type(verb[len-2])==0
			&& type(verb[len-3])==1 )
			dbl = 1;
	}
	else
	{
		
	}
	
	int len2 = len + 3 + 1 + 1;
	char* r = malloc( len2*sizeof(char) );
	strcpy( r, verb );
	if( last=='e' )
	{
		r[len-1] = 0;
		//printf( "r=%s\n", r );
	}
	
	if( dbl )
	{
		//strcat( r, last );
		//strcat( r, r+3 );
		strcat( r, verb+len-1 );
	}
	
	strcat( r, "ing" );
	return r;
}

int main()
{
   char* p = pr_cont("go");
   printf( "%s\n", p );
   p = pr_cont("make");
   printf( "%s\n", p );
   p = pr_cont("do");
   printf( "%s\n", p );
   p = pr_cont("get");
   printf( "%s\n", p );
   p = pr_cont("sing");
   printf( "%s\n", p );
   p = pr_cont("stop");
   printf( "%s\n", p );
}
