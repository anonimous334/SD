#include <iostream>
#include "list.h"

using namespace std;

int main() {
LinkedList<int> List;
cout << "isEmpty (da)" << endl;
cout << List.isEmpty() << endl;
cout << "addFirst" << endl;
List.addFirst(5);
List.printList();
cout << "isEmpty (nu)" << endl;
cout << List.isEmpty() << endl;
List.addFirst(20);
List.addFirst(3);
List.addFirst(1);
List.addFirst(20);
List.addFirst(11);
List.printList();
cout << "removeFirstOccurrencec 20" << endl;
List.removeFirstOccurrence(20);
List.printList();
List.addFirst(20);
List.addFirst(7);
cout << "addLast" << endl;
List.addLast(8);
List.printList();
cout << "removeLastOccurrence 20" << endl;
List.removeLastOccurrence(20);
List.printList();
cout << "removeFirst" << endl;
List.removeFirst();
List.printList();
cout << "removeLast" << endl;
List.removeLast();
List.printList();
cout << "c" << endl;
List.reverse();
List.printList();
return 0;
}
