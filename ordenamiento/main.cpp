#include <iostream>
#include <thread>
#include <mutex>
#include <pthread.h>
#include <stdlib.h>
using namespace std;

template <typename T>
bool MenorAmayor(T a, T b)
{
    return a>b;
}
template <typename T>
void swap(T *p, T*q)
{
    T *temp;
    *temp=*p;
    *p = *q;
    *q= *temp;
}
template <typename T>
void Burbuja_pf(T *a, T *b, bool (*p)(T, T))
{
	int *aux_primer, *aux_sig, *aux_fin;
	aux_fin = b;
	int cont=0;
	while(aux_fin-a > 0){
		aux_primer = a;
		aux_sig= a+1;
		for(b; b>a; b--)
		{
			if(p(*aux_primer, *aux_sig))
			{
				swap(*aux_primer, *aux_sig); //verifica
				cont++;
			}

			*aux_primer++;
			*aux_sig++;
		}
		if(cont==0)
            break;
		b=aux_fin;
		aux_primer = a; //o aux_primer = inicio ?
		aux_sig= a+1;
		aux_fin--;

	}

}
template <typename T>
class Menor
{
public:
    inline bool cmp(T a, T b){return a>b; }
};
template <class T, class O>
//class Sort
//{
//public:
    //O op;
    void Burbuja_fun(T *a, T *b)
    {
        O op;
       int *aux_primer, *aux_sig, *aux_fin;
        aux_fin = b;
        int cont=0;
        while(aux_fin-a > 0){
            aux_primer = a;
            aux_sig= a+1;
            for(b; b>a; b--)
            {
                if(op.cmp(*aux_primer, *aux_sig))
                {
                    swap(*aux_primer, *aux_sig); //verifica
                    cont++;
                }

                *aux_primer++;
                *aux_sig++;
            }
            if(cont==0)
                break;
            b=aux_fin;
            aux_primer = a; //o aux_primer = inicio ?
            aux_sig= a+1;
            aux_fin--;

        }

    }

//};

template <typename T>

class Polimorfismo
{
public:
    virtual bool operacion(T a, T b);
    void Burbuja_fun(T *a, T *b)
    {
       int *aux_primer, *aux_sig, *aux_fin;
        aux_fin = b;
        int cont=0;
        while(aux_fin-a > 0){
            aux_primer = a;
            aux_sig= a+1;
            for(b; b>a; b--)
            {
                if(operacion(*aux_primer, *aux_sig))
                {
                    swap(*aux_primer, *aux_sig); //verifica
                    cont++;
                }

                *aux_primer++;
                *aux_sig++;
            }
            if(cont==0)
                break;
            b=aux_fin;
            aux_primer = a; //o aux_primer = inicio ?
            aux_sig= a+1;
            aux_fin--;

        }

    }
};
template <typename T>
class Asc: public Polimorfismo <T>
{
    bool operacion(T a, T b){return a>b;}
};
	int main()
	{
	    int a[] = {3,6,8,9,1,2};
	    int tam = sizeof(a)/sizeof(int)-1;
	    int *ptr = a;
	    cout<<"PUNTERO A FUNCION"<<endl;
	    //Burbuja_pf(ptr, ptr+tam, MenorAmayor<int>);
	    for(int i=0; i<=tam; i++)
            cout<<*(ptr+i)<<" ";
        cout<<endl;
        cout<<"FUNCTOR"<<endl;
//        Sort<int, Menor<int>> bubble;
//        bubble.Burbuja_fun(ptr,ptr+tam);
  ///  Burbuja_fun<int, Menor<int>>(ptr, ptr+tam);
        for(int i=0; i<=tam; i++)
            cout<<*(ptr+i)<<" ";
        cout<<endl;
        cout<<"POLIMORIFSMO"<<endl;
        Polimorfismo<int> *B = new Asc<int>;
        B->Burbuja_fun(ptr, ptr + tam);
        for(int i=0; i<=tam; i++)
            cout<<*(ptr+i)<<" ";
        cout<<endl;
	}
