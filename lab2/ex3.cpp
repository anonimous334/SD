#include <iostream>

using namespace std;

class Complex{

public:

	int re;
	int im;

	Complex(){
		this->im = 0;
		this->re = 0;
	}

	Complex(const int a, const int b){
		this->im = b;
		this->re = a;
	}

	Complex(const Complex& other){

		this->im = other.im;
		this->re = other.re;
	}

	Complex operator=(const Complex& other){

		this->im = other.im;
		this->re = other.re;
	}

	~Complex(){

	}

	Complex operator+(const Complex& other){

		this->im = other.im + this->im;
		this->re = other.re + this->re;
	}

	Complex operator-(const Complex& other){

		this->im = this->im - other.im;
		this->re = this->re - other.re;
	}

	Complex operator*(const Complex& other){

		this->im = other.im * this->im;
		this->re = other.re * this->re;
	} 

};

int main(){

	Complex a(1,2);
	Complex b = a;

	cout << b.re << " " << b.im << endl;

	b+a;
	cout << b.re << " " << b.im << endl;

	b-a;
	cout << b.re << " " << b.im << endl;

	b*a;
	cout << b.re << " " << b.im << endl;
	return 0;
}