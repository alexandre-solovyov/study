
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char text[] = "Hello, world!";
  char* text2 = malloc(100);
  strcpy( text2, "My name is Alex" );
  
  printf( "%s\n", text );
  printf( "%s\n", text2 );
}
