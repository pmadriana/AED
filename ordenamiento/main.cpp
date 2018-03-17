#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Mayor{
public:
	bool operator()(int a, int b){return a>b;};
};

class Menor{
public:
	bool operator()(int a, int b){return a<b;};
};
bool Mayor1(int a, int b){return a>b; }
class AbsolutoMayor{
public:
	bool operator()(int a, int b){
		if (a < 0){
			a = (a * -1);
		}
		if (b < 0){
			b = (b * -1);
		}
		return a > b;
	}
};

class AbsolutoMenor{
public:
	bool operator()(int a, int b){
		if (a < 0){
			a = (a * -1);
		}
		if (b < 0){
			b = (b * -1);
		}
		return a < b;
	}
};

void swap(int *i, int *j)
{
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}
int* generar(int tam)
{
	srand(time(NULL));
	int* ret = new int[tam];
	int* a = ret;
	for(int i=0 ; i<=tam; a++, i++)
	{
		*a = int(rand()) % 10 ;
	}
	return ret;
}
template <typename T>
void burbuja_fn(int *a, int *b, T fn)
{
	int *aux_primer, *aux_sig, *inicio, *aux_fin;
	aux_fin = b;
	int cont=0;
	while(aux_fin-a > 0){
		aux_primer = a;
		aux_sig= a+1; //aux_sig=aux_primer+1 ¿?
		for(b; b>a; b--)
		{
			if(fn(*aux_primer, *aux_sig))
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

void burbuja_pf(int *a, int *b, bool (*p)(int, int))
{
	int *aux_primer, *aux_sig, *inicio, *aux_fin;
	aux_fin = b;
	int cont=0;
	while(aux_fin-a > 0){
		aux_primer = a;
		aux_sig= a+1; //aux_sig=aux_primer+1 ¿?
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
void imprimir(int *a, int tam){
	
	for(int i = 0; i <= tam; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}


int main()
{
	int a[]= {-1,7,0,5,-20,3};
	int tam=1000;
	Mayor mayo;
	Menor meno;
	/*burbuja(a, a+tam, mayo);
	imprimir(a, tam);
	cout<<"fmek"<<endl;*/
	int *abeja = generar(tam);
	imprimir(abeja,tam);
	bool (*p)(int,int);
	p=Mayor1;
	burbuja_pf(abeja, abeja+tam, p);
	cout<<"ordenado"<<endl;
	imprimir(abeja, tam);
	
}
