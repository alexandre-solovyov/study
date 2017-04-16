
#include <string>
#include <vector>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>

class Aeroport 
{
public:
  void print();
  void generate();
  
  void save( FILE* );
  void load( FILE* );
	
private:
  char        name[4];
  double      area;
  int         etage;
  int         year;
  double      price;
};

void Aeroport::print()
{
	// c_str -- РїРµСЂРµРІРѕРґРёС‚ std::string РІ char*
	printf( "%s %.1f km2 %i et. %i %.1f mln rbl\n", name, area, etage, year, price);
}

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

void Aeroport::generate()
{
	strcpy( name, generate_code() );
	area = 1 + (rand()%100)/10.0;
	etage = (rand()%5)+1;
	year = (rand()%60)+1940;
	price = 1 + (rand()%100)/10.0;
}

void Aeroport::save( FILE* f )
{
	fwrite( this, 1, sizeof(Aeroport), f );
}

void save( char* filename, std::vector<Aeroport> a )
{
	FILE* f = fopen( filename, "w" );
	int n = a.size();
	fwrite( &n, 1, sizeof(int), f );
	for( int i=0; i<n; i++ )
		a[i].save( f );
	fclose(f);
}

void Aeroport::load( FILE* f )
{
	fread( this, 1, sizeof(Aeroport), f );
}

std::vector<Aeroport> load( char* filename )
{
	std::vector<Aeroport> a;
	FILE* f = fopen( filename, "r" );
	int n;
	fread( &n, 1, sizeof(int), f );
	a.resize( n );
	for( int i=0; i<n; i++ )
		a[i].load( f );
	fclose(f);
	return a;
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
				a[i].generate();
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
				a[i].print();
			return 0;
		}
	}
	return 0;
}
