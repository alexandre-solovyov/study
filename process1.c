
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void run_pr()
{
	int r = fork();
	if( r==0 )
	{
		printf( "I am a child process\n" );
	}
	else if( r==-1 )
	{
		printf( "Error\n" );
	}
	else
	{
		printf( "I am the master process\n" );
		printf( "Child PID = %i\n", r );
	}	
}

int main()
{
	//system( "ls -1" );
	//system( "ls|grep g" );
	//system( "date" );
	
	//execl( "/usr/bin/ls", "ls", "-l", NULL );

    //for( int i=0; i<5; i++)	
	//	run_pr();

	char fname[1000];

    FILE* f = popen( "ls -1", "r" );
	int i=1;
	while( !feof(f) )
	{
		fgets( fname, 1000, f );
		printf( "%i: %s", i, fname );
		i++;
	}
	fclose(f);
}

