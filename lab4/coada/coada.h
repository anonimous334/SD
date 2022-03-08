#include <iostream>
using namespace std;
#define EMPTYCODE -1
#ifndef __QUEUE__H
#define __QUEUE__H

template <typename T, int N>
class Queue {
private:
        int head;
        int tail;
        int size;
        T queueArray[N];

public:
        Queue() {
		  cout << "COADA A FOST CREATA" << endl;
            head = EMPTYCODE;
		  tail = EMPTYCODE;
        }

        // Destructor
        ~Queue() {
            cout << "EXECUTE ORDER 66" << endl;
        }

        // Adauga la coada
        void enqueue(T x) {
            if((tail + 1) % N == head){
			  cerr << "COADA E CAM PLINA" << endl;
		  }
		  if(isEmpty()){
		  	head = 0;
			tail = 0;
			queueArray[tail] = x;
		  }
		  else{
			  tail = (tail+1) % N;
			  queueArray[tail] = x;
		  }

        }

        // Extrage din coada
        T dequeue() {
            if(isEmpty()){
			  cerr << "COADA E GOALA" << endl;
			  T junk;
			  return junk;
		  }
		  if(head == tail){ //exista doar un element
			  T removed = queueArray[tail];

			  head = -1;
			  tail = -1;

			  return removed;
		  } //nu mai exista
		  else{

			  head = (tail + 1)%N;
			  return queueArray[tail];
		  }

        }

        // Afla primul element
        T front() {
            if(isEmpty()){
			  cerr << "COADA E GOALA" << endl;
			  T junk;
			  return junk;
		  }
		  return queueArray[head];
        }

	   bool isEmpty() {
		if(head == EMPTYCODE && tail == EMPTYCODE)
		 	return 1;
		return 0;
        }

	   void printQueue(){
		   int size = (N + tail - head) % N;
		   size++;

		   for(int i = 0; i < size; i++){

			   int poz = (head + i) % N;
			   cout << queueArray[poz] << endl;
		   }
	   }
};
#endif
