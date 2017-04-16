
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <iostream>

class Data
{
public:
  Data( const char* q );
  void print();
  Data operator+( Data s );
  int len();

private:
  char* p;
};


  Data::Data( const char* q )
  {
	p = strdup(q);
  }
  
  void Data::print()
  {
	printf( "%s\n", p );
  }
  
  Data Data::operator+( Data s )
  {
	char* r;
	r = (char*)malloc( strlen(p) + strlen(s.p) + 2 );
	strcpy( r, p );
	strcat( r, " " );
	strcat( r, s.p );
	return Data(r);
  }
  
  int Data::len()
  {
	return strlen(p);
  }

using namespace std;

int main()
{
	Data s1("hello"), s2("world");
	Data s3 = s1 + s2;
	s3.print();
	printf( "%i\n", s3.len() );
	
	int n = 10;
	cout << n << endl;
}
