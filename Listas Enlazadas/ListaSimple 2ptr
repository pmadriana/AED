#include <iostream>

using namespace std;

template <class T>
class Nodo
{
public:
    T val;
    Nodo *next;

    Nodo(){};
    Nodo(T val, Nodo* sig)
	{
		this->val = val;
		next = sig;
	}
	Nodo(T val)
	{
	    this->val=val;
	    next=NULL;
	}
};

template <class T>
class Lista
{
public:
    Nodo<T>* inicio=NULL;

    Lista(){
        this->inicio=NULL;
        //this->inicio->val = nullptr;
    }
    bool find(T x, Nodo<T> **&p);
    bool insert( T x);
    bool remove(T x);
    void print();

};

template <class T>
bool Lista<T>::find(T x, Nodo<T> **&p)
{
    p= &inicio;
    for(p= &inicio; (*p) && ((*p)->val < x) ; p = &((*p)->next));
    return (*p) && (*p)->val==x;
}

template <class T>
bool Lista<T>::insert(T x)
{
    Nodo<T> **p;
    if(find(x,p)) return 0;
    Nodo<T> *t = new Nodo<T>(x,NULL);
    t->next = (*p);
    *p = t;
    return 1;
}

template <class T>
bool Lista<T> :: remove(T x)
{
    Nodo<T> **p;
    if(!find(x,p)) return 0;
    Nodo<T> *t = *p;
    *p = t->next;
    delete t;
    return 1;
}

template <class T>
void Lista<T>:: print()
    {
        Nodo<T> *temp;
        temp = inicio;
        while (temp!= NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }


int main()
{
    Lista<int> *A = new Lista<int>;
    A->insert(2);
    A->insert(1);
    A->insert(3);
    A->remove(3);
    A->print();
    return 0;
}
