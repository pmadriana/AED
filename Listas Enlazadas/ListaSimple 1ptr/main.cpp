#include <iostream>

using namespace std;
template <class T>
class Nodo
{
public:
    T val;
    Nodo *next;
    Nodo(T nro, Nodo *sigue=NULL)
    {
        val=nro;
        next=sigue;
    }
    ~Nodo(){
        cout << "Se elimina el nodo " << val << endl;
    }
};

template <class T>
class ListaSimple
{
public:
    Nodo<T>* inicio=NULL;

    Lista(){
        this->inicio=NULL;
        //this->inicio->val = nullptr;
    }

    bool buscar(T n)
    {
           Nodo<T> *temp;
           temp=inicio;
           //if(temp->val==n)
             //   return 1;
           while (temp && temp->val < n){
                    temp = temp->next;
            }
            return temp && temp->val==n;

    }

    void insertar(T n)
    {
        Nodo<T> *nuevo;
        nuevo = new Nodo<T>(n, NULL);

        if(inicio==NULL){
            inicio=nuevo;
        }
        else
        {
            if(!buscar(n))
            {

                Nodo<T> *temp;
                    temp=inicio;
                    if(n < temp->val)
                    {
                        inicio=nuevo;
                        nuevo->next = temp;
                    }else{
                    while(temp->next !=  NULL && temp->next->val < n){
                        temp = temp->next;
                    }

                        nuevo->next=temp->next;
                        temp->next=nuevo;

            }}
        }

    }
    void delet( T n)
    {
       if(buscar(n))
       {
           Nodo<T>* temp;
           temp=inicio;
           if(inicio->val==n)
           {
               inicio = inicio->next;
           }
           else
           {
               while(temp->next->val != n)
                temp = temp->next ;
            if (temp->next== NULL) temp = NULL;
            temp->next=temp->next->next;
           }

       }
       else

       {
           cout<<"no existe ese elemento o la lista esta vacia"<<endl;
       }

    }
    void print()
    {
        Nodo<T> *temp;
        temp = inicio;
        while (temp!= NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    ListaSimple<int>A;
    A.insertar(8);
    A.insertar(6);
    A.delet(6);
    A.insertar(10);
    A.insertar(7);
    A.insertar(9);
    A.delet(8);
    A.delet(10);
    A.delet(7);
    A.delet(9);
    A.print();

}
