#include <iostream>
#include <string>
#include <cstring>
class Refugee{

private:
	string name;
	short int year;
	string country;
	bool wanted;

public:

	Refugee(){
		this->name = "";
		this->year = 0;
		this->country = "";
		this->wanted = true;
	}
	~Refugee(){
		cout << "Entry removed" << endl;
	}

	Refugee(string newEntry){

		int commaPos[3];
		int cnt = 0;
		for(int i = 0; i < strlen(newEntry); i++){
			if(newEntry[i] == ','){
				commaPos[cnt] = i;
				cnt++;
			}
		}

		for(int i = 0; i < commaPos[0]; i++)
			this->name[i] = newEntry[i];
		this->name[commaPos[0]] = '\0';

		string tempYear;
		for(int i = commaPos[0] + 1; i < commaPos[1]; i++)
			 tempYear[i] = newEntry[i];
		tempYear[commaPos[1]] = '\0';
		this->year = stoi(tempYear);

		for(int i = commaPos[1]+1; i < commaPos[2]; i++)
	}
	Refugee(const Refugee& otherEntry){
		this->name = otherEntry->name;
		this->year = otherEntry->year;
		this->country = otherEntry->country;
		this->wanted = otherEntry->wanted;

	}
	Refugee operator =(const Refugee& otherEntry){
		this->name = otherEntry->name;
		this->year = otherEntry->year;
		this->country = otherEntry->country;
		this->wanted = otherEntry->wanted;
	}

}
