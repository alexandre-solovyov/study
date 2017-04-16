
#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE* f = fopen("test_write", "w");
  char s[] = "Hello, world!";
  int b[] = { 1, 2, 3, 4, 5 };
  
  fputs( s, f );
  int N = 100, a, i;
  for(i=1; i<=N; i++)
  {
	a = i*i;
	fprintf( f, "%i^2 = %i\n", i, a );
  }
  
  fwrite( b, sizeof(int), 5, f );
  
  fclose(f);
}
