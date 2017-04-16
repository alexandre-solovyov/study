
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str1[] = "Hello,";
	char str2[] = "world! My name ";
	char* s = malloc( 100 );
	char* s2 = malloc( 100 );
	char* s3 = malloc( 100 );
	char* s4 = malloc( 100 );
	char* s5 = malloc( 100 );
	char* p;
	char t;
	
	//s = str1;
	strcpy( s, str1 );
	strcat( s, str2 );
	if( strcmp( s, str1 )==0 )
	{
		printf( "Strings are equal\n");
	}
	
	printf( "%s\n", s );
	s[10] = 0;
	printf( "%s\n", s );
	printf( "%i\n", strlen(s) );
	printf( "%c\n", s[4] );
	
	
	strcpy( s2, "Today is Sunday; tomorrow is Monday" );
	printf( "%s\n", s2 );
	
	p = strstr( s2, "Sunday1" );
	if( p==NULL )
	{
		printf("Строка не найдена\n");
		exit(0);
	}
		
		
	printf( "%i\n", p-s2 );
	t = p[6];
	p[6] = 0;
	printf( "p=%s\n", p );
	printf( "s2=%s\n", s2 );
	printf( "p+7=%s\n", p+7 );

	strcpy( s3, s2 );
	p[6] = t;
	printf( "s3=%s\n", s3 );
	printf( "s2=%s\n", s2 );
	

    memcpy( s4, s2, p+6-s2 );
	s4[p+6-s2] = 0;
	printf( "s4=%s\n", s4 );
	printf( "s2=%s\n", s2 );

	strcpy( s5, "Hello,\0world!"+2 );
	printf( "s5=%s\n", s5 );
	
	
	printf( "%i\n", strlen(s2+5) );
	
	return 0;
}
