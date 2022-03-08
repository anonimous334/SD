#include <iostream>
#include "list.h"
using namespace std;

int main(){
	ArrayList<char> list;
	cout << list.isEmpty() << endl;
	list.addFirst('a');
	list.addFirst('b');
	list.addFirst('c');
	list.addLast('d');
	list.addLast('a');
	list.addFirst('f');
	list.addLast('g');
	list.addLast('a');
	list.addLast('a');
	list.addFirst('j');
	list.addLast('k');
	list.printList();
	list.removeFirst();
	list.removeLast();
	list.removeFirstOccurrence('a');
	list.removeLastOccurrence('a');
	cout << list.isEmpty() << endl;
	list.printList();

	ArrayList<int>ilist;
	ilist.addFirst(1);
	ilist.addFirst(8);
	ilist.addFirst(3);
	ilist.addLast(4);
	ilist.addLast(8);
	ilist.addFirst(6);
	ilist.addLast(7);
	ilist.addLast(8);
	ilist.addLast(9);
	ilist.addFirst(10);
	ilist.addLast(8);
	ilist.printList();
	ilist.removeFirst();
	ilist.removeLast();
	ilist.removeFirstOccurrence(8);
	ilist.removeLastOccurrence(8);
	cout << list.isEmpty() << endl;
	ilist.printList();


	return 0;
}
