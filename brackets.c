#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int br( char* string )
{
	int i=0, k=0;
	while( string[i] )
	{
		if( string[i] == '(' )
			k++;
		if( string[i] == ')' )
			k-=1;
		if(k<0)
			return k;
		i++;
	}
	return k;
}

void print( char** c, int len )
{
	int i = 0;
	for(; i < len; i++)
	{
		printf("%s, ", c[i]);
	}
	printf("\n");
}

int strlen2( char** t, int len )
{
	int i, n;
	n=0;
	for(i=0; i<len; i++)
	{
		n+=strlen(t[i]);
	}
	return n;
}

char* unite( char** c, int len )
{
	int i, n;
	char* rez;

	n = strlen2(c, len);
	n++;
	
	rez = malloc(n);
	strcpy(rez, c[0]);
	for(i=1; i<len; i++ )
		strcat(rez, c[i]);
	return rez;
}

int main()
{
  char* s;
  s = malloc(100);
  strcpy(s, "(a+b)");
  printf( "%i\n", br(  "(a+b)"  ));
  printf( "%i\n", br(  "(a+b"  ));
  printf( "%i\n", br(  "a+b)"  ));
  printf( "%i\n", br(  ")("  ));
  printf( "%i\n", br(  "(()"  ));
  printf( "%i\n", br(  "(())"  ));
 
  free(s); 
  
  
  
  char* c[] = { "Alex", "Ivan", "Sergey" };
  print(c, 3);
  
  char** p;
  int i, j;
  p = malloc( 10 * sizeof(char*) );
  for( i=0; i<10; i++ )
	  p[i] = malloc(100);
  strcpy( p[0], "Alex" );
  strcpy( p[1], "Sergey" );
  strcpy( p[2], "Vasilij" );
  
  print(p, 3);  
  
  
  
  int** q = malloc(3*sizeof(int*));
  for( i=0; i<3; i++ )
	q[i] = malloc(4*sizeof(int));
  q[0][0] = 1;
  q[0][1] = 2;
  q[0][2] = 3;
  q[0][3] = 4;
  q[1][0] = 5;
  q[1][1] = 6;
  q[1][2] = 7;
  q[1][3] = 8;
  q[2][0] = 9;
  q[2][1] = 10;
  q[2][2] = 11;
  q[2][3] = 12;
  
  for(i=0; i<3; i++)
  {
	  for(j=0; j<4; j++)
		  printf( "%i, " , q[i][j] );
	  printf( "\n");
  }
  
  
  printf( "%s\n", unite(c, 3));
}
