#include <iostream>

using namespace std;

class Fractie{

public:

	int numarator;
	int numitor;

	Fractie(){

		this->numarator = 0;
		this->numitor = 1;
	}

	Fractie(int nr, int nu){

		int cmmdc = euclid(nr, nu);
		this->numarator = nr / cmmdc;
		this->numitor = nu / cmmdc;

	}

	Fractie(const Fractie& other){

		this->numarator = other.numarator;
		this->numitor = other.numitor;
	}

	Fractie operator=(const Fractie& other){

		this->numarator = other.numarator;
		this->numitor = other.numitor;
	}

	Fractie operator*(const Fractie& other){
		
		Fractie result;
		
		result.numarator = numarator * other.numarator;
		result.numitor = numitor * other.numitor;

		return result;
	}
	Fractie operator/(const Fractie& other){
		
		Fractie result;
		
		result.numarator = this->numarator * other.numitor;
		result.numitor = numitor * other.numarator;
		
		return result;
	}
	double operator<(const Fractie& other){

		return (double) ( (double)numarator / (double)numitor);
	}

	~Fractie(){
	}	

private:

	int euclid(int a, int b){
		int c;
		while(b){
		    c = a % b;
		    a = b;
		    b = c;
		}
		return a;
	}

};

int main(){

	Fractie a(2, 8);
	Fractie b = a;
	Fractie c;
	Fractie d(3, 5);
	double zec;

	Fractie prod = a*b;
	Fractie impa = b/d;
	zec = a<a;

	cout << a.numarator << "/" << a.numitor << endl;
	cout << b.numarator << "/" << b.numitor << endl;
	cout << c.numarator << "/" << c.numitor << endl;
	cout << prod.numarator << "/" << prod.numitor << endl;
	cout << prod.numarator << "/" << prod.numitor << endl;
	cout<<zec;

	return 0;
}
