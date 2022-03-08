#include <iostream>
#include "hashtable.h"
#include <string>

using namespace std;

unsigned int hashingFunction(int nr){	//basic hash function pt int

    return nr  % 10;
}

unsigned int charHashingFunction(string str){	//basic hash function pt strings

	const int magic = 8497;
	unsigned int hash = str.length() + magic;
	return hash;
}

int main(){

	//test int
	Hashtable<int, int> my_table(10, &hashingFunction);

	my_table.put(34588, 1);
	my_table.put(3458, 2);
	my_table.put(8345, 3);
	my_table.put(13459, 4);
	my_table.put(3345, 5);
	my_table.put(144345, 6);
	my_table.put(3125, 7);
	my_table.put(34123, 8);
	my_table.put(346, 9);
	my_table.put(346, 10);

	cout << endl;

	int a, b, c, d;
	a = my_table.get(346);
	b = my_table.get(3125);
	c = my_table.get(8345);
	d = my_table.get(444);
	cout << a << " " << b << " " << c << " " << d << endl;

	cout << endl;

	bool check1 = my_table.hasKey(3458);
	bool check2 = my_table.hasKey(1001);
	cout << check1 << " " << check2 << endl;

	cout << endl;

	my_table.remove(8345);
	my_table.remove(1111);
	my_table.remove(144345);

	cout<< endl;

/////////////////////////////////////////////////////////////////

	//test string
	Hashtable<string, char> char_table(10, &charHashingFunction);
	char_table.put("asda", 'a');
	char_table.put("adxcz", 'b');
	char_table.put("wqrqer", 'c');
	char_table.put("asdas", 'd');
	char_table.put("cvcxzxc", 'e');
	char_table.put("asda", 'f');
	char_table.put("sdasd3", 'g');

	char c1, c2, c3, c4;

	c1 = char_table.get("asda");
	c2 = char_table.get("wqrqer");
	c3 = char_table.get("cvcxzxc");
	c4 = char_table.get("razvan");

	cout << c1 << " " <<  c2 << " " << c3 << endl;

	return 0;
}
