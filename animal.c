
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>

const int PERIOD = 100000;
const int N = 5;
const int MIN_SATIETY = 50;

typedef struct
{
	double age;
	double satiety;
	double health;
} animal;

int getkey()
{
    int character;
    struct termios orig_term_attr;
    struct termios new_term_attr;

    /* set the terminal to raw mode */
    tcgetattr(fileno(stdin), &orig_term_attr);
    memcpy(&new_term_attr, &orig_term_attr, sizeof(struct termios));
    new_term_attr.c_lflag &= ~(ECHO|ICANON);
    new_term_attr.c_cc[VTIME] = 0;
    new_term_attr.c_cc[VMIN] = 0;
    tcsetattr(fileno(stdin), TCSANOW, &new_term_attr);

    /* read a character from the stdin stream without blocking */
    /*   returns EOF (-1) if no character is available */
    character = fgetc(stdin);

    /* restore the original terminal attributes */
    tcsetattr(fileno(stdin), TCSANOW, &orig_term_attr);

    return character;
}

void init( animal* a )
{
	a->age = 0;        // возраст в годах
	a->satiety = 100;  // сытость в процентах
	a->health = 100;   // здоровье в процентах
}

int next( animal* a, char* command )
{
	if( strcmp( command, "feed" ) == 0 )
	{
		a->satiety = 100;
	}

	if( strcmp( command, "walk" ) == 0 )
	{
		a->health += 10;
		if( a->health > 100 )
			a->health = 100;
	}

	a->age += 0.0001;
	a->satiety -= 0.1;
	
	if( a->satiety<MIN_SATIETY )
		a->health -= 0.1;

	if ( a->satiety <= 0 || a->health <= 0 )
	{
		printf( "\n\nDEAD!!!\n" );
		return -1;
	}
	
	return 0;
}

void print_data( int n, int max, double value, double min, char* info )
{
	printf( "[" );
	for( int i=0; i<max; i++ )
		if( i<=n )
			printf( "=" );
		else
			printf( " " );
	printf( "] %.1f%% ", value );

	if( value < min )
		printf( " [%s] ", info );
	
	
	fflush( stdout );
}

void print( animal* a )
{
	printf( "\r" );
	print_data( a->satiety/N, 100/N, a->satiety, MIN_SATIETY, "HUNGRY" );
	print_data( a->health/N, 100/N, a->health, MIN_SATIETY, "ILL" );
	printf( "     " );
}

int main()
{
	printf( "Animal test\n" );
	animal a;
	init( &a );
	while( 1 )
	{
		print( &a );
		int s = next( &a, "" );
		if( s )
			return s;
		
		//char c = getch();
		char c = getkey();
		if( c=='f' )
			next( &a, "feed" );
		if( c=='w' )
			next( &a, "walk" );
		if( c=='e' )
			return 0;
		
		usleep( PERIOD );
	}
	
	return 0;
}
