#include <iostream>

using namespace std;

class complex{

public:
	double re;
	double im;

	complex(double re, double im){

		this->re = re;
		this->im = im;
	}

	complex add(complex a, complex b){

		return (complex(a.re + b.re, a.im + b.im)); 
	}

	complex substract(complex a, complex b){

		return (complex(a.re - b.re, a.im - b.im));
	}

	complex product(complex a, complex b){

		return (complex(a.re * b.re - a.im - b.im, a.re * b.im + a.im * b.re));
	}

};

int main(){

	complex z1(1, 2);
	complex z2(3, 4);

	complex z3 = z3.add(z1, z2);

	complex z4 = z4.substract(z1, z2);

	complex z5 = z5.product(z1, z2);

	cout<<z3.re<<" "<<z3.im<<endl;
	cout<<z4.re<<" "<<z4.im<<endl;
	cout<<z5.re<<" "<<z5.im<<endl;

	return 0;
}