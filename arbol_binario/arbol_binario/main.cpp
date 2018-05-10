// arbol_binaria.cpp: define el punto de entrada de la aplicación de consola.
//

#include <iostream>
#include<stack>
#include<queue>
using namespace std;


template <class T>
class Cnode
{
public:
	T data;
	Cnode<T> *nodes[2];
	Cnode(T x)
	{
		data = x;
		nodes[0] = 0;
		nodes[1] = 0; //0 izquierda, 1 derecha
	}
	void print()
	{
		cout << data << endl;
	}
};

template <class T>
class Ctree
{
public:
	Cnode<T> *root; //raiz del arbol
					//Constructor
	Ctree()
	{
		root = 0;
	}

	//Funcion de busqueda
	bool find(T x, Cnode<T>**&pointer) //Ingresamos el dato a buscar y el puntero que lo apuntara por referencia
	{
		for (pointer = &root; *pointer != 0 && (*pointer)->data != x; pointer = &((*pointer)->nodes[((*pointer)->data)<x])); //bajamos por el arbol hasta la posicion correcta
		return ((*pointer) != 0); //si el puntero apunta a nulo, el nodo no existe
	}

	//Funcion insertar nodo
	bool insert(T x)
	{
		Cnode<T> **cursor; //cursor para desplazarnos por el array
		if (find(x, cursor)) //si el nodo ya existe
		{
			return 0; //no se puede insertar
		}
		*cursor = new Cnode<T>(x); //se inserta el nuevo nodo
		return 1;
	}

	//Funcion que busca la posicion con la que dicho nodo puede intercambiarse
	Cnode<T> **reemplazo(Cnode<T> **pointer)
	{
		Cnode<T> **posicion = pointer; //posicion que se retornara
		bool direccion = ((*posicion)->nodes[1]) != 0; //nos vamos al nodo derecho, si es que existe; de lo contrario, a la izquierda
		for (posicion = &((*posicion)->nodes[direccion]); (*posicion)->nodes[!direccion] != 0; posicion = &((*posicion)->nodes[!direccion])); //bajamos en la direccion opuesta
		return posicion;
	}


	//Funcion para eliminar nodo
	bool remove(T x)
	{
		Cnode<T> **cursor;
		if (find(x, cursor) == 0) //si el nodo no existe
		{
			return 0; //no se puede borrar
		}
		if ((*cursor)->nodes[0] != 0 && (*cursor)->nodes[1] != 0) //si el nodo tiene 2 hijos (caso 2)
		{
			Cnode<T> **cambio = reemplazo(cursor); //buscamos la posicion decendiente con la que puede intercambiarse
			(*cursor)->data = (*cambio)->data; //dicho nodo sube
			cursor = cambio; // y ahora el cursor apunta al nodo descendiente que se borrara
		}
		Cnode<T> *temporal = *cursor; //puntero al nodo que se va a eliminar, para que no se pierda su direccion
		*cursor = (*cursor)->nodes[(*cursor)->nodes[1] != 0]; //si el hijo derecho esta vacio, enlazamos el izquierdo
		delete temporal; //borramos el nodo
		return 1;
	}
	template <class T>
	class s_node
	{
	public:
		int estado;
		Cnode<T> *nodo;
		s_node<T>(Cnode<T> *puntero)
		{
			estado = 0;
			nodo = puntero;
		}
	};


	void print()
	{
		int radio = 0;
		queue< s_node<T> > recorrido;
		recorrido.push(s_node<T>(root));
		while (recorrido.size() != 0)
		{
			if (recorrido.front().estado != radio)
			{
				cout << endl;
				radio = radio + 1;
			}
			if (recorrido.front().estado != radio)
			{
				cout << endl;
				radio = radio + 1;
			}
			cout << recorrido.front().nodo->data << " ";
			if (recorrido.front().nodo->nodes[0] != 0)
			{
				recorrido.push(recorrido.front().nodo->nodes[0]);
				recorrido.back().estado = radio + 1;
			}
			if (recorrido.front().nodo->nodes[1] != 0)
			{
				recorrido.push(recorrido.front().nodo->nodes[1]);
				recorrido.back().estado = radio + 1;
			}
			recorrido.pop();
		}
	}

	//Auxiliar que retorna un puntero al fondo a la derecha
	Cnode<T> *fondo()
	{
		Cnode<T> *cursor;
		cursor = root;
		while ((cursor->nodes[1]) != 0)
		{
			cursor = cursor->nodes[1];
		}
		return cursor;
	}

};



int main()
{
	Ctree<int> bTree;
	bTree.insert(5);
	bTree.insert(3);
	bTree.insert(1);
	bTree.insert(2);
	bTree.insert(8);
	bTree.insert(7);
	bTree.insert(9);

	bTree.print();
	cout << endl;
	cout << "borrar" << endl;
	bTree.remove(5);
	cout << endl << endl;

	bTree.print();
	int z;
	cin >> z;


	return 0;
}