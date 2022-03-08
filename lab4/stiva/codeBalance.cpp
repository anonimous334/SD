#include <iostream>
#include <fstream>
#include "stiva.h"
#include <cstring>
using namespace std;

int main(){

	Stack <char,1000>checkerStack;
	char fileName[20];
	string fileLine;
	cin>>fileName;
	ifstream inFile((const char *)fileName, std::ifstream::in);
	bool balanced = true;
	while(getline(inFile, fileLine)){
		int openParantCnt = 0;
		for(int i = 0; i < fileLine.length(); i++){
			if(fileLine[i] == '{'){
				checkerStack.push('{');
			if(fileLine[i] == '}'){
				if (checkerStack.peek() != '{')
					balanced = false;
					break;
				}else{
					cout << checkerStack.pop() << "2" << endl;
				}
			}
		}

	}
	cout << checkerStack.isEmpty() << endl;
	if(checkerStack.isEmpty()){
		balanced = true;
	}
	else{
		balanced = false;
	}

	cout << balanced << endl;

	return 0;
}
