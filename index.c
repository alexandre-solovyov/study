
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int LEN = 128;

typedef struct 
{
	char* word;     // Слово в таблице индексов
	int*  indices;  // Индексы в тексте, где слово встречается
	int   count;    // Кол-во индексов
	
} info;


info* INDEX = 0;
int   INDEX_SIZE = 0;


// Добавить слово, которое встретилось первый раз
void add_word( char* new_word, int new_index )
{
	INDEX_SIZE++;
	INDEX = realloc( INDEX, INDEX_SIZE * sizeof(info) );
	INDEX[INDEX_SIZE-1].word = strdup( new_word );
	INDEX[INDEX_SIZE-1].indices = malloc( 1 * sizeof(int) );
	INDEX[INDEX_SIZE-1].indices[0] = new_index;
	INDEX[INDEX_SIZE-1].count = 1;
}

// Найти слово
int find_word( char* word )
{
	for(int i=0; i<INDEX_SIZE; i++)
		if( strcmp(word, INDEX[i].word)==0 )
			return i;
		
	return -1;
}

// Добавить слово, которое встретилось уже не первый раз (2-й, 3-й и т.д.)
void add_index( char* word, int new_index )
{
	int i = find_word( word );
	if( i<0 )
	{
		add_word( word, new_index );
		return;
	}
	
	INDEX[i].count++;
	INDEX[i].indices = realloc(INDEX[i].indices, sizeof(int)*INDEX[i].count);
	INDEX[i].indices[INDEX[i].count-1] = new_index;
}

int get_max_freq()
{
	int max = 0;
	int arg = -1;
	for(int i=0; i<INDEX_SIZE; i++)
	{
		int freq = INDEX[i].count;
		if(max < freq)
		{
			max = freq;
			arg = i;
		}
	}
	
	printf( "the most relevant: %s\n", INDEX[arg].word );
	return max;
}

// Релевантность по частоте = частота данного слова / максимальную частоту слов
double relevant_index( char* word )
{
	int i = find_word( word );
	if( i<0 )
		return 0.0;
	
	return (double)INDEX[i].count / get_max_freq();
}

void print()
{
	for(int i=0; i<INDEX_SIZE; i++)
	{
		printf( "%s: ", INDEX[i].word );
		for( int j = 0; j<INDEX[i].count; j++)
			printf("%i, ", INDEX[i].indices[j] );
		printf( "\n" );
	}	
}

// Обработать слово
void treat_word( char* word, int index )
{
	//printf( "%s %i ", word, index );
	add_index( word, index );
}

int is_letter( char c )
{
	//1-буква
	if( c>='А' && c<='Я' )
		return 1;
	if( c>='а' && c<='я' )
		return 1;
	
	return 0;
}

int global_index = 0;

// Обработать строку из файла
void read_line( char* line )
{
	int start = -1;
	int gc = global_index;
	//printf( "gc=%i\n", gc);
	for(int i=0; line[i]!=0; i++, global_index++ )
		if( start>=0 )  // слово уже началось
	    {
		  if( !is_letter( line[i] ) )
		  {
			  // слово от start до i, i -- не буква
			  char c = line[i];
			  line[i] = 0;
			  //printf( "gc+start=%i\n", gc+start);
			  treat_word( line+start, gc+start );
			  line[i] = c;
			  start = -1;
		  }
		}
		else // слово не началось
		{
			if( is_letter( line[i] ) )
				start = i;
		}
}

// Обработать целый файл
void read( char* filename )
{
	char* line = malloc(LEN);
	FILE* f = fopen( filename, "r" );
	while( !feof(f) )
	{
		char* p = fgets( line, LEN, f );
		if( p != NULL )
		{
			read_line( line );
		}
	}
	
	fclose(f);
}

void print_ri( char* w )
{
	printf( "%s: %.3f\n", w, relevant_index( w ) );
}

int main()
{
	read( "d:/test/3_friends.txt" );
	//read( "d:/test/test.txt" );
	print();
	print_ri( "Робби" );
	print_ri( "коньяк" );
	return 0;
}
