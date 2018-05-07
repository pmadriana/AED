#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;


template <typename T>
class Node {
public:
    static int index;
    T value;
    string Svalue; // numero o letra
    string symbol; // 1 de los 4 simbolos
    Node<T> *next;

    Node(T value, string Svalue = "", string symbol = "", Node<T> *next = nullptr) {
        index = index;
        this->value = value;
        this->Svalue = Svalue;
        this->symbol = symbol;
        this->next = next;
    }

    ~Node() {
        next = nullptr;
    }
};
template <typename T>
int Node<T>::index = 1;

template <typename T>
class List {
    Node<T> *Head = nullptr;
public:
    List() {
        Head = nullptr;
    }

    bool find(T value, Node<T> **&next, string Svalue = "", string symbol = "") {
/*        for (next = &(Head->next);
             (*next)->value != value and (*next)->Svalue != Svalue and (*next)->symbol != symbol and
             (*next) != Head; next = &(*next)->next);
        return (*next)->value == value and (*next)->Svalue == Svalue and (*next)->symbol == symbol;*/
        next = &(Head->next);
        while (*next != Head) {
            if ((*next)->value == value and (*next)->Svalue == Svalue and (*next)->symbol == symbol)
                return true;
            next = &(*next)->next;
        }
        return false;
    }

    void remove(T value, string Svalue = "", string symbol = "") {
        if (Head != nullptr) {
            Node<T> **next;
            if (Head->value == value and Head->Svalue == Svalue and Head->symbol == symbol) {
                if (Head->next == Head) {
                    delete Head;
                    Head = nullptr;
                    return;
                }
                Node<T> *ultimo = Head;
                for (; ultimo->next != Head; ultimo = ultimo->next);
                Node<T> *temp = Head->next;
                delete Head;
                Head = temp;
                ultimo->next = Head;
                return;
            }
            if (find(value, next, Svalue, symbol)) {
                Node<T> *temp = (*next)->next;
                delete *next;
                *next = temp;
            }
        }
    }

    void insert(T value, string Svalue = "", string symbol = "") {

        if (Head == nullptr) {
            Head = new Node<T>(value, Svalue, symbol);
            Head->next = Head;
            cout<<"se entro aqui en jugador "<<Head->index<<endl;
            return;
        }

        Node<T> **next = &(Head->next);
        while (*next != Head) {
            next = &(*next)->next;
        }
        *next = new Node<T>(value, Svalue, symbol, *next);

        /*if (Head->value == value)
            return;
        if (Head->value > value) {
            Node<T> *ultimo = Head;
            while (ultimo->next != Head)
                ultimo = ultimo->next;
            Head = new Node<T>(value, Svalue, symbol, Head);
            ultimo->next = Head;
            return;
        }
        Node<T> **next;
        if (!find(value, next, symbol)) {
            *next = new Node<T>(value, Svalue, symbol, *next);
        }*/
    }

    void sort() {
        srand(time(NULL)); // permite generar numeros aleatorios

        Node<T> *nodo1 = Head;
        Node<T> *nodo2 = Head;
        for (int NumBarajeos = 0; NumBarajeos < 3; NumBarajeos++) {
            for (int PosCartaBaraja = 1; PosCartaBaraja <= 52; PosCartaBaraja++) {
                for (int PosAdelante = rand() % 51 + 1; PosAdelante > 0; PosAdelante--) {
                    nodo2 = nodo2->next;
                }
                int temp1 = nodo1->value;
                string temp2 = nodo1->Svalue;
                string temp3 = nodo1->symbol;

                nodo1->value = nodo2->value;
                nodo1->Svalue = nodo2->Svalue;
                nodo1->symbol = nodo2->symbol;

                nodo2->value = temp1;
                nodo2->Svalue = temp2;
                nodo2->symbol = temp3;
            }
        }
    }

    void print() {
        if (Head != nullptr) {
            //cout << endl << "Elementos dentro de la lista" << endl << endl;
            Node<T> *temp = Head;
            do {
                cout << "value: " << temp->value;
                if (temp->Svalue != "" and temp->symbol != "") {
                    cout << " Svalue: " << temp->Svalue
                         << " Symbol: " << temp->symbol << endl;

                }
                /*cout << "-> " << temp->next->value << endl;*/
                temp = temp->next;
            } while (temp != Head);
        }
    }

/*    void move() {
        Head = Head->next;
    }*/

    T getValue() {
        return Head->value;
    }

    string getSvalue() {
        return Head->Svalue;
    }

    string getSymbol() {
        return Head->symbol;
    }

    T getindex() {
        return Head->index;
    }

    ~List() {
        if (Head != nullptr) {
            Node<T> *temp = Head;
            Node<T> *next;
            Node<T> *ultimo = Head;
            for (; ultimo->next != Head; ultimo = ultimo->next);
            ultimo->next = nullptr;
            do {
                next = temp->next;
                delete temp;
                temp = next;
            } while (temp);
        }
    }
};

 string to_string ( int Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }


    void nums_al(int n, int a[])
    {
        int sinrep[52];
        for(int i=0; i<52; i++)
        {
            sinrep[i] = i;
        }
        random_shuffle(sinrep, sinrep+52);

        for(int i=0; i<n; i++)
        {
           a[i] = sinrep[i];

        }
    }
  void crear_baraja(int n, List<int> *&baraja) ///tam baraja
  {
      srand(time(NULL));
      int a[n];
      nums_al(n, a);
      for (int i = 0; i < n; i++) {
        int x = i % 13 + 1;
        string Svalue = (x == 1) ? "A" : (x == 11) ? "J" : (x == 12) ? "Q" : (x == 13) ? "K" : to_string(x); //El numero de la carta
        string symbol = (a[i] < 13) ? "Espadas" : (a[i] < 26) ? "Corazones" : (a[i] < 39) ? "Rombo": "Trebol";
        //cout<<"valores a ingresar: "<<x<<" "<<Svalue<<" "<<symbol<<endl;
        baraja->insert(x, Svalue, symbol);
    }
   baraja->sort();
  }


int main() {
    int numJugadores;
    cout << "Ingrese el numero de jugadores: ";
    cin >> numJugadores;
    while (numJugadores < 2 or numJugadores > 4) {
        cout << "El juego es de 2 a 4 jugadores, ingrese otro numero: ";
        cin >> numJugadores;
    }
    List<int> *Baraja = new List<int>;

    crear_baraja(52, Baraja);
    Baraja->print();
    cout<<"repartiendo cartas"<<endl;
/// CREANDO JUGADORES
    List<int>* array_jug[numJugadores];
    for(int i= 0; i< numJugadores; i++)
        array_jug[i]=new List<int>;
    for(int i=0; i<numJugadores; i++){
        int num_cartas;
        if(numJugadores>2)num_cartas=7; else num_cartas=8;
        crear_baraja(num_cartas, array_jug[i]);
    }
    ///end
    for(int i=0; i<numJugadores; i++){
        cout<<"jugador"<<i<<": "<<endl;
        array_jug[i]->print();
    }

    return 0;
}

