#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const int LEN = 100;
char** cities = NULL;  // Массив строк-городов
int*   used   = NULL;  // Массив статусов (использовался ли город)
int nb_cities = 0;     // Кол-во строк-городов

int check( char* a, char* b )
{
	int q = strlen(a);
	if( q > 0 )
		return a[q-1] == b[0];
	else
		return 1;
}

void append( char* city, int u )
{
	nb_cities++;
	cities = realloc( cities, sizeof(char*)*nb_cities );
	used = realloc( used, sizeof(int)*nb_cities );
	cities[nb_cities-1] = malloc(LEN);
	strcpy( cities[nb_cities-1], city );
	used[nb_cities-1] = u;
}

void print()
{
	int i;
	printf( "--------------\n" );
	for(i=0; i<nb_cities; i++)
		printf("%s\n", cities[i]);
	printf( "--------------\n" );
}

int read( char* fname )
{
	FILE* p = fopen( fname, "r");
	if( p==NULL )
		return 0;
	
	char* q = malloc(LEN), *r;
	while(!feof(p))
	{
		r = fgets(q, LEN, p);
		if( r )
		{
			q[strlen(q)-2] = 0;
			append( q, 0 );
		}
	}
	fclose( p );
	free( q );
	return 1;
}

int write( char* fname )
{
	FILE* p;
	p = fopen(fname, "w");
	if( p==NULL )
		return 0;
		
	int i;
	for(i=0; i<nb_cities; i++)
		fprintf(p, "%s\r\n", cities[i]);
	fclose(p);
	return 1;
}

int find( char* city )
{
	int i;
	for(i=0; i<nb_cities; i++)
		if( strcmp(city, cities[i])==0 )
			return i;
	return -1;
}

void use( char* city )  // Пометить город как использованный
{
	int i = find(city);
	if( i>=0 )
		used[i] = 1;
	else
		append( city, 1 );
}

char* random_city( char* last )
{
	int* p = malloc( sizeof(int) * nb_cities );
	int i, j;
	
	for( i=0; i<nb_cities; i++ )	
		p[i] = -1;
	
	j = 0;
	for( i=0; i<nb_cities; i++ )
		if( !used[i] && check( last, cities[i] ) )
		{
			p[j] = i;
			j++;
		}
	
	char* result;
	if( j==0 )
		result = 0;
	else
	{
		i = rand()%j;
		i = p[i];
		result = cities[i];
	}
	
	free(p);
	return result;
}

char* user_city( char* last )
{
	char* city = malloc(LEN);
	strcpy( city, "" );
	while( strcmp(city, "") == 0 )
	{
		printf("Введите город:\n");
		scanf("%s", city);
		//printf( "%s", city );
		//printf( "%i", check( last, city ) );
		//printf( "%i", strcmp(city, ""));
		if( !check( last, city ) )
		{
			printf( "Город недопустим\n" );
			strcpy( city, "" );
		}
	}
	return city;
}

void game()
{
	char* last = malloc(LEN);
	strcpy( last, "" );
	
	while( 1 )
	{
		char* u = user_city( last );
		if( strcmp(u, "-")==0 )
		{
			printf( "Компьютер выиграл\n" );
			return;
		}
		use( u );
		strcpy( last, u );
		char* c = random_city( last );
		if( c==0 )
		{
			printf( "Я не знаю, вы выиграли\n" );
			return;
		}
		else
		{
			printf( "Computer: %s\n", c );
			strcpy( last, c );
		}
	}
}

int main()
{
	srand(time(0));
	read("cities.data");
	//print();
	//printf( "%s\n", random_city("p"));
	game();
	write("cities.data");
	return 0;
}
