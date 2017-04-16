
#include <stdio.h>

char CONSONANTS[]  = "бвгджзйклмнпрстфхцчшщ";
char CONSONANTS2[] = "БВГДЖЗЙКЛМНПРСТФХЦЧШЩ";

int ALL = 0; // Все слова
int DOUBLE = 0; // Все слова c удвоенными согласными

char* find_char( char* str, char c )
{
  char* p;
  for( p = str; *p!=0; p++ )
	if( *p == c )
		return p;
  return NULL;
}

int get_length( char* str )
{
  char* p;
  int len = 0;
  for( p = str; *p!=0; p++ )
  {
	  len++;
  }
  return len;
}

int is_consonant( char c )
{
	char* p = find_char(CONSONANTS, c);
	if( p != NULL )
		return p - CONSONANTS;
	
	p = find_char(CONSONANTS2, c);
	if( p != NULL )
		return p - CONSONANTS2;
	else
		return -1;
}

void has_double_letter( char* s )
{
	ALL++;
	
	//printf( "%s\n", s );
	int i;
	int n = get_length(s);	
	for(i=0; i<n-1; i++)
	{
		//printf( "i=%i %i\n", i, is_consonant(s[i]) );
		if( is_consonant(s[i])>=0 && is_consonant(s[i])==is_consonant(s[i+1]) )
		{
			// Удвоенная согласная!!!
			DOUBLE++;
			printf( "%s\n", s );
			break;
		}
	}
}

void get_words( char* s )
{
	int i;
	int n = get_length(s);
	int word_start = 0;
	char* w;
	for(i=0; i<n; i++)
	{
		if(s[i]==' ')
		{
			w = s + word_start;
			s[i] = 0;
			has_double_letter(w);
			s[i] = ' ';
			word_start = i+1;
		}
	}
	w = s + word_start;
	has_double_letter( w );
}

int main()
{
	FILE* f = fopen("3_friends.txt", "r");
	const int n = 200;
	char s[n];
	char* p;
	
	while(!feof(f))
	{
		p = fgets( s, n, f );
		if( p )
		{
			//printf( "%s", s );
			s[get_length(s)-2] = 0;
			get_words( s );
		}
	}
	
	fclose(f);
	
	//has_double_letter( "стол" );
	//printf( "%i %i\n", ALL, DOUBLE);
	//has_double_letter( "зеленеет" );
	//printf( "%i %i\n", ALL, DOUBLE);
	//has_double_letter( "сбалансированный" );
	//printf( "%i %i\n", ALL, DOUBLE);
	
	//has_double_letter( "   \n" );
	printf( "%i %i\n", ALL, DOUBLE);
	
	
	return 0;
}
