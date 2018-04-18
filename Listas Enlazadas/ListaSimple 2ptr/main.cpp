#include <iostream>

using namespace std;
 using namespace std;

template <class op>
class Mayor{
public:
	inline bool operator()(op a, op b){return (a>b);};
};

template <class op>
class Menor{
public:
	inline bool operator()(op a, op b){return a<b;};
};

template <class op>
void swap(op *i, op *j)
{
	op temp;
	temp = *i;
	*i = *j;
	*j = temp;
}

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

template <class T, class op>
class Lista
{
public:
    Nodo<T>* inicio=NULL;
    op operacion;
    Lista(){
        this->inicio=NULL;
        //this->inicio->val = nullptr;
    }
    bool find(T x, Nodo<T> **&p);
    bool insert( T x);
    bool remove(T x);
    void print();

};

template <class T, class op>
bool Lista<T, op>::find(T x, Nodo<T> **&p)
{
    p= &inicio;
    for(p= &inicio; (*p) && operacion((*p)->val, x) ; p = &((*p)->next));
    return (*p) && (*p)->val==x;
}

template <class T , class op>
bool Lista<T, op>::insert(T x)
{
    Nodo<T> **p;
    if(find(x,p)) return 0;
    Nodo<T> *t = new Nodo<T>(x,NULL);
    t->next = (*p);
    *p = t;
    return 1;
}

template <class T, class op>
bool Lista<T,op> :: remove(T x)
{
    Nodo<T> **p;
    if(!find(x,p)) return 0;
    Nodo<T> *t = *p;
    *p = t->next;
    delete t;
    return 1;
}

template <class T, class op>
void Lista<T,op>:: print()
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
  //  Mayor<int> asce;
    Lista<int, Menor<int> > *A = new Lista<int, Menor<int>>;
    A->insert(2);
    A->insert(1);
    A->insert(3);
    A->remove(3);
    A->print();
    return 0;
}
