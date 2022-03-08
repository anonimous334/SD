#include <iostream>
#include "stiva.h"

using namespace std;

int main(){

	Stack <int, 10>myStack;

	myStack.displayStack();
	cout << myStack.isEmpty() << endl;

	myStack.push(2);
	myStack.push(5);
	myStack.push(7);
	myStack.displayStack();

	cout << myStack.pop() << endl;
	cout << myStack.peek() << endl;
	myStack.displayStack();

	cout << myStack.isEmpty() << endl;

	return 0;
}
