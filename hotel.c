#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print( int* hotel, int len, int printZeros )
{
	int i, nb=0;
	for(i=0; i<len; i++)
	{
		if(hotel[i] !=0)
			nb++;
	}
	printf( "%i польз.: ", nb );
	for(i=0; i<len; i++)
	{
		if( hotel[i] != 0 || printZeros != 0 )
			printf("%i ", hotel[i]);
	}
	printf("\n");
}

int add( int user, int* hotel, int len )
{
	int i, q;
	// rand() -- получить очередное случайное число
	for( i=0; i<len; i++  )
	{
		// получить случайное число в заданном диапазоне от 0 до len-1
		q = rand()%len;
		if( hotel[q] == 0 )
		{
			hotel[q] = user;
			return 1;
		}
	}
	return 0;
}

int Remove( int user, int* hotel, int len )
{
	int i;
	for(i=0; i<len; i++)
		if(hotel[i]==user)
		{
			hotel[i]=0;
			return 1;
		}
	return 0;	
}

int main()
{
    int* p;
    int n = 25, i, k;
    p = malloc( n * sizeof( int ) );
	
	// Заполнение области памяти (БАЙТ) нулями
	memset( p, 0, n * sizeof( int ) );
	
	// Инициализация генератора случайных чисел при помощи текущего времени
	srand(time(0));
	
	print( p, n, 0 );
	add( 15, p, n );
	print( p, n, 0 );
	add( 25, p, n );
	add( 35, p, n );
	add( 50, p, n );
	print( p, n, 0 );
	Remove( 15, p, n );
	print( p, n, 0 );
	Remove( 55, p, n );
	print( p, n, 0 );
	
	/*
    for(i=0; i<n; i++)
    {
        p[i] = 0;
        printf(" %i ", p[i]);
    }
        printf("\n");
         for(i=0; i<n; i++)
         {
              p[2] = 15;
              printf(" %i ", p[i]);
         }
          printf("\n");
              for(i=0; i<n; i++)
              {
                  p[20] = 26;
                  printf(" %i ", p[i]);
              }
               printf("\n");
                    for(i=0; i<n; i++)
                    {
                             p[10] = 40;
                             printf(" %i ", p[i]);
                    }
                     printf("\n");
                     printf("\n");
 
                     for(i=0; i<n; i++)
                     {
                          if (p[i] == 26 )
                              {
                                  p[i] = 0;
                              
                              }    
                          printf(" %i ", p[i]);
                     }    
                   
 
 
 */
	free(p);
	return 0;
}    
