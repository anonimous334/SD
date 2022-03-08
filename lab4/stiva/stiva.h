#include <iostream>
using namespace std;
#define EMPTYCODE -1
#ifndef __STACK__H
#define __STACK__H

// Primul argument al template-ului este tipul de date Ts
// Al doilea argument este dimensiunea maxim a stivei N
template<typename T, int N>
class Stack {
 public:
	 // constructor
	 Stack() {

		 topLevel = EMPTYCODE;
		 for(int i = 0; i < N; i++)
		 	stackArray[i] = EMPTYCODE;

		// cout << "Stiva a fost creata" << endl;
	 }

	 // destructor
	 ~Stack() {
		 //cout << "Stiva a fost distrusa" <<endl;
	 }

	 // operator de adaugare
	 void push(T x) {

		 if(topLevel == N -1){
			cerr << "STACK OVERFLOW" << endl;
		 }
		 else{
			 if(topLevel == EMPTYCODE)
			 	topLevel = 0;

			 stackArray[topLevel] = x;
			 topLevel++;
		 }
	 }

	 // operatorul de stergere
	 T pop() {

		 if(topLevel != EMPTYCODE){
			 topLevel--;
			 return stackArray[topLevel];
		 }
		 else{
			 cerr << "OPERATIE IMPOSIBILA" << endl;
			 T junk;
			 return junk;
		 }
	 }

	 // operatorul de consultare
	 T peek() {

		 if(topLevel != EMPTYCODE){
			 return stackArray[topLevel - 1];
		 }
		 else{
			 cerr << "OPERATIE IMPOSIBILA" << endl;
			 T junk;
			 return junk;
		 }
	 }

	 // operatorul de verificare dimensiune
	 int isEmpty() {

		 if(topLevel == EMPTYCODE || topLevel == 0){
			 return 1;
		 }
		 return 0;
	 }

	 void displayStack(){

		 cout << "STIVA:" <<endl;
		 for(int i = 0; i < topLevel; i++)
		 	cout << stackArray[i] << " ";
		cout << endl;
	 }

 private:
	 // vectorul de stocare
	 T stackArray[N];

	 // pozitia in vector a varfului stivei
	 int topLevel;
};

#endif
