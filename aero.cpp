
#include <string>
#include <vector>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>

typedef struct 
{
	std::string name;
	double area;
	int    etage;
	int    year;
	double price;
} Aeroport;

char generate_char()
{
	return 'A' + rand()%('Z'-'A');
}

char* generate_code()
{
	int n = 3;
	char* c = (char*)malloc(n+1);
	for( int i=0; i<n; i++)
		c[i] = generate_char();
	c[n] = 0;
	return c;
}

Aeroport generate()
{
	Aeroport a;
	
	a.name = generate_code();
	a.area = 1 + (rand()%100)/10.0;
	a.etage = (rand()%5)+1;
	a.year = (rand()%60)+1940;
	a.price = 1 + (rand()%100)/10.0;
	
	return a;
}

void print( Aeroport a )
{
	// c_str -- РїРµСЂРµРІРѕРґРёС‚ std::string РІ char*
	printf( "%s %.1f km2 %i et. %i %.1f mln rbl\n", a.name.c_str(), a.area, a.etage, a.year, a.price);
}

void save( const char* filename, std::vector<Aeroport> a )
{
	FILE* p = fopen(filename, "w");
	int n = a.size();
	for(int i=0; i<n; i++)
      fprintf( p, "%s %.1f km2 %i et. %i %.1f mln rbl\n", a[i].name.c_str(), a[i].area, a[i].etage, a[i].year, a[i].price );
  
	fclose(p);
}

std::vector<Aeroport> load( const char* filename )
{
	std::vector<Aeroport> res;
	FILE* p = fopen(filename, "r");
	if( p==NULL )
		return res;
	
	const int LEN = 128;
	char buffer[LEN];
	while( !feof(p) )
	{
		char* q = fgets( buffer, LEN, p );
		if( q!=NULL )
		{
			q[strlen(q)-2] = 0;
			//printf( "%s\n", buffer );
			char name[4];
			double area;
			int etage;
			int year;
			double price;
			sscanf( buffer, "%s %lf km2 %d et. %d %lf mln rbl", name, &area, &etage, &year, &price );
			Aeroport a;
			a.name = name;
			a.area = area;
			a.etage = etage;
			a.year = year;
			a.price = price;
			res.push_back( a );
		}
	}
	
	fclose(p);
	return res;
}

void print_help()
{
	std::cout << "--help либо -h  - запуск программы в режиме получения справки" << std::endl;
	std::cout << "-с [N] [file_name]  - запуск программы в режиме создания электронной таблицы записей, N –количество записей, file_name – имя текстового файла, в котором будет сохранен массив (таблица) записей" << std::endl;
	std::cout << "-r [N] [file_name]  - запуск программы в режиме чтения содержимого текстового файла file_name, на экран должны быть выведены не более N записей" << std::endl;
}

int main( int argc, char** argv )
{
	srand(time(0));
	
	if( argc==2 )
	{
		if( strcmp( argv[1], "--help" )==0 || strcmp( argv[1], "-h" )==0 )
		{
  		  print_help();
		}
		return 0;
	}
	
	if( argc==4 )
	{
		if( strcmp(argv[1], "-c")==0 )
		{
			int n;
			sscanf( argv[2], "%d", &n );
			char* filename = argv[3];
			std::vector<Aeroport> a;
			a.resize( n );  // РёР·РјРµРЅРёС‚СЊ СЂР°Р·РјРµСЂ РІРµРєС‚РѕСЂР° (СѓРІРµР»РёС‡РёС‚СЊ РјР°СЃСЃРёРІ)
			for( int i=0; i<n; i++)
				a[i] = generate();
			save( filename, a );
			return 0;
		}
		if( strcmp(argv[1], "-r")==0 )
		{
			int n;
			sscanf( argv[2], "%d", &n );
			char* filename = argv[3];
			std::vector<Aeroport> a = load( filename );
			for( int i=0, s=a.size(); i<s && i<n; i++ )
				print( a[i] );
			return 0;
		}
	}
	return 0;
}
