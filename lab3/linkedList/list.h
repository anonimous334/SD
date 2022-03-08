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
class LinkedList {
private:
    Node<T> *first, *last;
public:
    // Constructor
    LinkedList(){
      first = NULL;
      last = NULL;
    }
    // Destructor
    ~LinkedList(){
      while(first != NULL){
        struct Node <T> * aux = new struct Node <T>;
        aux = first;
        first = first->next;
        delete aux;
      }

    }

    /* Adauga un nod cu valoarea == value la inceputul listei. */
    void addFirst(T value){
      if(first!=NULL){
        struct Node <T> * aux = new struct Node <T>;

        aux->value = value;
        aux->prev = NULL;
        aux->next = first;

        first->prev = aux;
        first = aux;
      }
      else{
        struct Node <T> * aux = new struct Node <T>;
        aux->value = value;
        aux->next = NULL;
        aux->prev = NULL;

        first = last = aux;

      }
    }

    /* Adauga un nod cu valoarea == value la sfarsitul listei. */
    void addLast(T value){
      if(last != NULL){
        struct Node <T> * aux = new struct Node <T>;

        aux->value = value;
        aux->next = NULL;
        aux->prev = last;

        last->next = aux;
        last = aux;
      }
      else{
        struct Node <T> * aux = new struct Node <T>;
        aux->value = value;
        aux->next = NULL;
        aux->prev = NULL;

        first = last = aux;
      }
    }

    /* Elimina elementul de la inceputul listei si intoarce
    valoarea acestuia. */
    T removeFirst(){
      if(first != NULL){
        struct Node <T> * aux = new struct Node <T>;
        aux = first;
        first = first->next;
        first->prev = NULL;

        T garbageValue = aux->value;

        delete aux;

        return garbageValue;
      }
      else{
        T garbageValue;
        cout<<"EMPTY LIST"<<endl;
        return garbageValue;
      }
    }

    /* Elimina elementul de la sfarsitul listei si intoarce
    valoarea acestuia. */
    T removeLast(){
      if(last != NULL){
        struct Node <T> * aux = new struct Node <T>;
        aux = last;
        last = last->prev;
        last->next = NULL;

        T garbageValue = aux->value;

        delete aux;

        return garbageValue;
      }
      else{
        T garbageValue;
        return garbageValue;
      }
    }

    /* Elimina prima aparitie a elementului care are valoarea == value. */
    T removeFirstOccurrence(T value){

      if(first == NULL){
        T error;
        cout<<"EMPTY LIST"<<endl;
        return error;
      }
      else{
        struct Node <T> *iter = new struct Node <T>;
        iter = first;
        while(iter){
          if(iter->value == value){
            iter->next->prev = iter->prev;
            iter->prev->next = iter->next;

            T garbageValue = iter->value;
            delete iter;
            return garbageValue;
          }
          else{
            iter = iter->next;
          }
        }
      }
    }

    /* Elimina ultima aparitie a elementului care are valoarea == value. */
    T removeLastOccurrence(T value){

      if(last == NULL){
        T error;
        cout<<"EMPTY LIST"<<endl;
        return error;
      }
      else{
        struct Node <T> * iter = new struct Node <T>;
        iter = last;
        while(iter){
          if(iter->value == value){
            iter->prev->next = iter->next;
            iter->next->prev = iter->prev;

            T garbageValue = iter->value;
            delete iter;
            return garbageValue;
          }
          else{
            iter = iter->prev;
          }
        }
      }
    }

    /* Afiseaza elementele listei pe o singura linie,
    separate printr-un spatiu. */
    void printList(){
      struct Node <T> * iter = new struct Node <T>;
      iter = first;

      while(iter){
        cout << iter->value << " ";
        iter = iter->next;
      }
      cout<<endl;
    }
	void reverse(){
		struct Node <T> *iter = new struct Node <T>;
		Node<T> *auxPtr;
		iter = first->next;
		first->prev = iter;
		first->next = NULL;
		while(iter->next != NULL){
			cout << iter->value << " ";
			auxPtr = iter->next;
			iter->next = iter->prev;
			iter->prev = auxPtr;

			iter = iter->prev;
		}
		last->next = last->prev;
		last->prev = NULL;

		iter = last;
		last = first;
		first = iter;

	}
    /* Intoarce true daca lista este vida, false altfel. */
    bool isEmpty(){
      if(first == NULL)
        return true;
      return false;
    }
};
