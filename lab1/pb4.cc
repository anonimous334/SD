#include <iostream>

#define NUM 3

using namespace std;

class MappingEntry{

public:

	int cheie;
	char* valoare;

	MappingEntry(int cheie, char* valoare){

		cout<<"Object is being created"<<endl;

		this->cheie = cheie;
		this->valoare = valoare;
	}

	~MappingEntry(){

		cout<<"Object is being deleted"<<endl;
	} 

};

int main(){

	char character = 'c';
	char* ptc = &character;
	MappingEntry statVar(NUM, ptc);

	MappingEntry * dinamVar = new MappingEntry(NUM, ptc);

	delete dinamVar;

	return 0;
}