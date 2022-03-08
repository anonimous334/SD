#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

class Persoana{

public:
	int age;
	char* name;

	Persoana(){

		this->age = 0;
		this->name = NULL;
	} //constructor default

	Persoana(int nr, const char* string){

		this->age = nr;
		this->name = strdup(string);
	} //constructor

	Persoana(const Persoana& other){

		this->age = other.age;
		this->name = strdup(other.name);
	} //copy constructor

	~Persoana(){
		
		if(name != NULL)
			delete name;
	} //destructor

	Persoana operator=(const Persoana& other){

		this->age = other.age;
		this->name = strdup(other.name);
	} //assignment operator

};

int main(){

	Persoana a(19, "Razvan");
	Persoana b = a;
	Persoana c;

	printf("%s %d\n", a.name, a.age);
	printf("%s %d\n", b.name, b.age);
	printf("%s %d\n", c.name, c.age);

	return 0;
}