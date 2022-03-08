#include <iostream>

using namespace std;

class fractie{

public:

	int numit;
	int numar;

	fractie(int numar, int numit){

		int cmmdc = euclid(numar, numit);

		this->numar = numar / cmmdc;
		this->numit = numit / cmmdc;
	}

	fractie produs(fractie f){
		return fractie(numar * f.numar, numit * f.numit);
	}

	fractie impart(fractie f){

		return fractie(numar * f.numit, numit * f.numar);
	}

	double zecimal(){

		return (double)(((double)numar) / ( (double)numit));
	}

private:

	int euclid(int a, int b){

		int c;
    	while (b) {
        	c = a % b;
        	a = b;
        	b = c;
    	}
    	return a;
	}

};

int main(){

	fractie fr1(1, 2);
	fractie fr2(4, 6);

	fractie fr3 = fr1.produs(fr2);
	fractie fr4 = fr1.impart(fr2);
	double zecimEchiv = fr2.zecimal();

	cout<<fr3.numar<<"/"<<fr3.numit<<endl;
	cout<<fr4.numar<<"/"<<fr4.numit<<endl;
	cout<<zecimEchiv<<endl;

	return 0;
}
