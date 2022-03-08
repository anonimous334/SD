#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T value;
    Node<T> *next, *prev;
    Node (T value) {
	this->value = value;
        next = prev = NULL;
    }
    Node() {
        next = prev = NULL;
    }
};

template <typename T>
class ArrayList {
private:
    T *array;
    int size, capacity;
public:
    // Constructor
    ArrayList(){
         size = 0;
         capacity = 10; //capacitate initiala 10 ca asa vreau eu
         array = new T[capacity]; //adica array de 10, stii?
    }
    // Destructor
    ~ArrayList(){
         delete[] array;
    }

    /* Adauga un nod cu valoarea == value la inceputul vectorului. */
    void addFirst(T value){
	    if(size != capacity){
		    for(int i = size; i > 0; i--){
			    array[i] = array[i-1];
		    }
		    array[0] = value;
		    size++;
	    }
	    else{ //e de rau
		    T * futureArray = new T[capacity * 2];
		    for(int i = 0; i < size; i++){
			    futureArray[i+1] = array[i];
		    }
		    futureArray[0] = value;
		    size++;
		    capacity *= 2;
		    array = futureArray;
		    delete[] futureArray;
	    }
    }

    /* Adauga un nod cu valoarea == value la sfarsitul vectorului. */
    void addLast(T value){
	    if(size != capacity){ //e de bine
		    array[size] = value;
		    size++;
	    }
	    else{
		    T * futureArray = new T[capacity * 2];
		    for(int i = 0; i < size; i++){
			    futureArray[i] = array[i];
		    }
		    array[size] = value;
		    size++;
		    value *= 2;
		    delete[] futureArray;
	    }
    }

    /* Elimina elementul de la inceputul vectorului si intoarce valoarea
    acestuia. */
    T removeFirst(){
	    T removed = array[0];
	    for(int i = 0; i < size; i++){
		    array[i] = array[i+1];
	    }
	    size--;
	    return removed;
    }

    /* Elimina elementul de la sfarsitul vectorului si intoarce valoarea
     acestuia. */
    T removeLast(){
	    size--; //hacky
	    return array[size];
    }

    /* Elimina prima aparitie a elementului care are valoarea == value. */
    T removeFirstOccurrence(T value){
	    int poz = -1;
	    for(int i = 0; i < size; i++){
		    if(array[i] == value){
			    poz = i;
			    break;
		    }
	    }
	    if(poz >= 0){
		    for(int i = poz; i <size; i++){
			    array[i] = array[i+1];
		    }
		    size--;
	    }
	    else{
		    cout<<"NU S-A GASIT ELEMENTUL, PARE RAU, BOSS"<<endl;
	    }
    }

    /* Elimina ultima aparitie a elementului care are valoarea == value. */
    T removeLastOccurrence(T value){
	    int poz = -1;
	    for(int i = 0; i < size; i++){
		    if(array[i] == value)
		    	poz = i;
	    }
	    if(poz >= 0){
		    for(int i = poz; i <size; i++){
			    array[i] = array[i+1];
		    }
		    size--;
	    }
	    else{
		    cout<<"NU S-A GASIT ELEMENTUL, PARE RAU, BOSS"<<endl;
	    }
    }

    /* Afiseaza elementele vectorului pe o singura linie, separate printr-un
    spatiu. */
    void printList(){
          for(int i = 0; i < size; i++)
		     cout<<array[i]<<" ";
          cout<<endl;
    }

    /* Intoarce true daca vectorul este gol, false altfel. */
    bool isEmpty(){
          if(size == 0)
               return true;
          return false;
    }
};
