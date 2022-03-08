#include <iostream>
#include "coada.h"

using namespace std;

int main(){

	Queue<int, 10> q;

	cout << q.isEmpty() << endl;

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.enqueue(7);
	q.enqueue(8);
	q.enqueue(9);
	q.enqueue(10);
	q.enqueue(11);
	q.enqueue(12);
	q.enqueue(13);
	q.enqueue(14);
	q.enqueue(15);
	q.enqueue(16);
	q.enqueue(17);
	q.enqueue(18);
	q.enqueue(19);
	q.enqueue(20);

	q.printQueue();
	cout << q.isEmpty() << endl;

	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();

	q.printQueue();

	return 0;
}
