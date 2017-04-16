
int main()
{
  struct student
  {
	char* name;
    int age;
    int	course;
  };
  
  struct group
  {
	student* students;
	int index_of_main;
  }; 
};
