#include <iostream>
#include <cmath>

using namespace std;

class point2d{

public:
	double x;
	double y;

	point2d(double x, double y){

		this->x = x;
		this->y = y;
	}

	double onox(){

		return x;
	}

	double onoy(){

		return y;
	}

	double dist(point2d p2){

		return(sqrt(pow((x - p2.x), 2) + pow((y - p2.y), 2)));
	}

};

int main(){

	point2d a(1, 2);
	point2d b(3, 4);

	cout<<a.onox()<<endl;

	cout<<b.onoy()<<endl;

	cout<<a.dist(b)<<endl;

	return 0;
}