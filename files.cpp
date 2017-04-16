
#include <stdio.h>
#include <string.h>
#include <malloc.h>

void print_help()
{
	printf( "This is program to print messages files.\n" );
	printf( "Arguments:\n" );
	printf( "  files <file>\n" );
	printf( "    <file> -- messages file\n" );
}

void read_file( const char* filename, int mode )
{
	FILE* p = fopen( filename, "r" );
	if( p==NULL )
	{
		printf( "File does not exist\n" );
		return;
	}
	const int n = 128;
	char* line = (char*)malloc(n);
	while(!feof(p))
	{
		char* q = fgets( line, n, p );
		if( q!=NULL )
		{
			int w = strlen(line);
			line[w-2] = 0;
			if( mode==0 )
				read_file( line, 1 );
			else
				printf( "%s\n", line );
		}
	}
	fclose(p);
}

int main( int argc, char** argv )
{
	//for( int i=0; i<argc; i++ )
	//	printf( "%s\n", argv[i] );

	if( argc==2 )
	{
		if( strcmp( argv[1], "--help" )==0 )
  		  print_help();
		else
		  read_file( argv[1], 0 );
	}
	
	return 0;
}
