#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstdlib>
using namespace std;

template <typename T>
class Node {
public:
    T value;
    string Svalue; // numero o letra
    string symbol; // 1 de los 4 simbolos

    Node<T> *next;

    Node(T value, string Svalue = "", string symbol = "", Node<T> *next = nullptr) {
        this->value = value;
        this->Svalue = Svalue;
        this->symbol = symbol;
        this->next = next;
    }

    void print(){
        cout<<value<<" "<<Svalue<< " "<<symbol<<endl;
    }

    ~Node() {
        next = nullptr;
    }
};

template <typename T>
class List {
    Node<T> *Head;
    T puntaje;
public:

    List() {
        Head = nullptr;
        this->puntaje = 0;
    }

    bool find(T value, Node<T> **&next, string Svalue = "", string symbol = "") {
        next = &(Head->next);
        while (*next != Head) {
            if ((*next)->value == value and (*next)->Svalue == Svalue and (*next)->symbol == symbol)
                return true;
            next = &(*next)->next;
        }
        return false;
    }

    bool remove(T value, string Svalue = "", string symbol = "") {
        if (Head != 0) {
            Node<T> **next;
            if (Head->value == value and Head->Svalue == Svalue and Head->symbol == symbol) {
                if (Head->next == Head) {
                    delete Head;
                    Head = nullptr;
                    return true;
                }
                Node<T> *ultimo = Head;
                for (; ultimo->next != Head; ultimo = ultimo->next);
                Node<T> *temp = Head->next;
                delete Head;
                Head = temp;
                ultimo->next = Head;
                return true;
            }
            if (find(value, next, Svalue, symbol)) {
                Node<T> *temp = (*next)->next;
                delete *next;
                *next = temp;
                return true;
            }
        }
        return false;
    }

    void insert(T value, string Svalue = "", string symbol = "") {
        //cout<<"Head: "<<Head<<endl;
        if (Head == 0) {
            Head = new Node<T>(value, Svalue, symbol);
            Head->next = Head;
            return;
        }

        Node<T> **next = &(Head->next);
        while (*next != Head) {
            next = &(*next)->next;
        }
        *next = new Node<T>(value, Svalue, symbol, *next);
    }

    void sort() {
        srand(time(NULL)); // permite generar numeros aleatorios

        Node<T> *nodo1 = Head;
        Node<T> *nodo2 = Head;
        for (int NumBarajeos = 0; NumBarajeos < 3; NumBarajeos++) {
            for (int PosCartaBaraja = 1; PosCartaBaraja <= 52; PosCartaBaraja++) {
                for (int PosAdelante = rand()%51 + 1; PosAdelante > 0; PosAdelante--) {
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

    void sumPuntaje(T puntaje) {
        this->puntaje += puntaje;
    }

    bool cFind(int cartaSelec, Node<T> *&pilaDescarte) {
        Node <T> **next = &Head;
        for (; cartaSelec > 1; cartaSelec--) {
            next = &(*next)->next;
        }

        if( (*next)->value ==50 or (*next)->Svalue == pilaDescarte->Svalue or (*next)->symbol == pilaDescarte->symbol)
        {
            pilaDescarte->value = (*next)->value;
            pilaDescarte->Svalue = (*next)->Svalue;
            pilaDescarte->symbol = (*next)->symbol;
            remove((*next)->value, (*next)->Svalue, (*next)->symbol);
            return 1;
        }

        return 0;
    }

    bool comprobarMazo() {
      return Head;
    }

    void Actual()
    {
        Node<T> **next = &Head->next;
        while((*next)->next!=Head)
        {

            next = &((*next)->next);
        }
        cout<<" "<<(*next)->Svalue<<" "<<(*next)->symbol<<endl;
    }

    int getValorCartas() {
        int puntajeTotal = 0;
        puntajeTotal += Head->value;
        for (Node<T> **next = &Head->next; *next && *next != Head; next = &(*next)->next)
            puntajeTotal += (*next)->value;
        return puntajeTotal;
    }

    void add_puntaje(int x)
    {
        puntaje += x;
    }
    void print() {
        int i=1;
        if (Head != nullptr) {
            //cout << endl << "Elementos dentro de la lista" << endl << endl;
                //cout << endl << "Elementos dentro de la lista" << endl << endl;
                Node<T> *temp = Head;
                do {
                    if (temp->Svalue != "" and temp->symbol != "") {
                        cout <<"    "<< i<<" )  "<<temp->Svalue<<" "<<temp->symbol<< endl;
                        i++;
                    }
                    /*cout << "-> " << temp->next->value << endl;*/
                    temp = temp->next;
                } while (temp != Head);
            }
    }
    void RepartirBaraja(int num_cartas, List<T>*& Baraja) {
        for (int j = 0; j < num_cartas; j++) {
            insert(Baraja->getValue(), Baraja->getSvalue(), Baraja->getSymbol());
            Baraja->remove(Baraja->getValue(), Baraja->getSvalue(), Baraja->getSymbol());

        }
    }
    T getValue() {
        return Head->value;
    }

    string getSvalue() {
        return Head->Svalue;
    }

    string getSymbol() {
        return Head->symbol;
    }

    ~List() {
        if (Head != 0) {
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

void nums_al(int n, int a[]) {
    int sinrep[52];
    for (int i = 0; i < 52; i++) {
        sinrep[i] = i;
    }
    random_shuffle(sinrep, sinrep + 52);

    for (int i = 0; i < n; i++) {
        a[i] = sinrep[i];

    }
}

 string to_string ( int Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }

void crear_baraja(int n, List<int> *&baraja) { ///tam baraja
    srand(time(NULL));
    int a[n];
    nums_al(n, a);
    for (int i = 0; i < n; i++) {
        int x = i % 13 + 1;
        string Svalue = (x == 1) ? "A" : (x == 11) ? "J" : (x == 12) ? "Q" : (x == 13) ? "K" : to_string(x); //El numero de la carta
        string symbol = (i < 13) ? "Espadas" : (i < 26) ? "Corazones" : (i < 39) ? "Rombo" : "Trebol";
        //cout<<"valores a ingresar: "<<x<<" "<<Svalue<<" "<<symbol<<endl;
        baraja->insert((x == 8) ? 50 : (x > 10) ? 10 : x, Svalue, symbol);
    }
    baraja->sort();
}

int main() {
    int numJugadores;
    int PuntajeGanador[3] = {100, 150, 200};
    system("color 29");
    cout<<"  _____   _      _____  _____  _____  _____ "<<endl;
cout<<" |  _  |  | |    |  _  |/  __ \\|  _  |/  ___|"<<endl;
cout<<"  \\ V /   | |    | | | || /  \\/| | | |\\ `--. "<<endl;
cout<<"  / _ \\   | |    | | | || |    | | | | `--. \\ "<<endl;
cout<<" | |_| |  | |____\\ \\_/ /| \\__/\\\\ \\_/ //\\__/ /"<<endl;
cout<<" \\___ _/  \\_____/ \\___/  \\____/ \\___/ \\____/" <<endl<<endl<<endl;

cout << "Bienvenido al juego de 8 locos" <<endl<<endl<< "Por favor ingresa el numero de jugadores" <<endl;
    cin >> numJugadores;
    while (numJugadores < 2 or numJugadores > 4) {
        cout << "El juego es de 2 a 4 jugadores, ingrese otro numero: ";
        cin >> numJugadores;
    }

    //crea la baraja

    List<int> *Baraja = new List<int>;
    crear_baraja(52, Baraja);

    List<int> *array_jug[numJugadores]; //crea a los jugadores
    for (int i = 0; i < numJugadores; i++)
        array_jug[i] = new List<int>();
    int num_cartas;
    if (numJugadores > 2)num_cartas = 8; else num_cartas = 7;// numero de cartas inicial para cada jugador

    //REPARTIR CARTAS//
    cout<<"repartiendo cartas:"<<endl;
    int jugadorActual = 0;
    int puntajeTotal, puntajes[4];
    for (int i = 0; i < numJugadores; i++) {
        array_jug[i]->RepartirBaraja(num_cartas, Baraja);
        cout << "\ncartas del Jugador " << i + 1 << endl;
        array_jug[i]->print();
    }


    //Paso 3 //

    Node<int> *pilaDescarte = new Node<int>(0);
    while (Baraja->getValue() == 8) {
        Baraja->sort();
    }

    pilaDescarte->value=Baraja->getValue();
    pilaDescarte->Svalue=Baraja->getSvalue();
    pilaDescarte->symbol=Baraja->getSymbol();


    Baraja->remove(Baraja->getValue(), Baraja->getSvalue(), Baraja->getSymbol());
    bool terminar_juego = 1;
    system ("cls");
    system("color 4A");
    while (terminar_juego) { //////////while general
        /// *********************************CAMBIO JUGADOR
        jugadorActual--;
        if (jugadorActual < 0) jugadorActual += numJugadores;
        switch(jugadorActual){
            case 3: system("color 4A");break;
            case 2: system("color 5C");break;
            case 1: system("color 1D");break;
            case 0: system("color 2F");break; }

        cout << "Es el turno del jugador:" << jugadorActual + 1 <<endl<<endl;

        /// ************************PASO 4
        cout << "Carta en la pila de descarte: " << pilaDescarte->Svalue<< " " << pilaDescarte->symbol<<endl<<endl;
        cout<<" Tu baraja:"<< endl;
        array_jug[jugadorActual]->print();


        /// ************************Paso 5 y 6
        int cartaSelec;
        bool cartaValida = 0;

        while (cartaValida == 0) {
            cout << "Seleccione una carta o presione 0 para sacar una carta de la baraja:" << endl;
            cin >> cartaSelec;

            /// ************************PASO 4

            while(cartaSelec<0 or cartaSelec>52){
                cout<<"numero de carta no valido"<<endl;
                cin>>cartaSelec;
            }
            if (cartaSelec == 0) {
                if (Baraja->comprobarMazo() == 0  ) {
                    cartaValida = 1;
                    continue;
                }
                array_jug[jugadorActual]->insert(Baraja->getValue(), Baraja->getSvalue(), Baraja->getSymbol());
                cartaValida = Baraja->remove(Baraja->getValue(), Baraja->getSvalue(), Baraja->getSymbol());
            } else {
                Node<int> **next;
                cartaValida = array_jug[jugadorActual]->cFind(cartaSelec,pilaDescarte);//////
            }
        }
        //cout<<"BARAJA JUG" <<endl;
       // if(array_jug[jugadorActual]->comprobarMazo()) array_jug[jugadorActual]->print(); else cout<<"nada";
        if (Baraja->comprobarMazo() == 0) {
            int menorPuntajePos, menorPuntaje = array_jug[0]->getValorCartas();
            puntajes[0] = menorPuntaje;
            menorPuntajePos = 0;
            puntajeTotal += array_jug[0]->getValorCartas();
            for (int i = 1; i < numJugadores; i++) {
                puntajeTotal += array_jug[0]->getValorCartas();
                puntajes[i] = array_jug[i]->getValorCartas(); ///puntaje de cada jugador
                if (menorPuntaje > array_jug[i]->getValorCartas()) {
                    menorPuntaje = array_jug[i]->getValorCartas();
                    menorPuntajePos = i;
                }
            }
            array_jug[menorPuntajePos]->add_puntaje(puntajeTotal);
            if ((array_jug[jugadorActual]->getValorCartas() > PuntajeGanador[numJugadores])) terminar_juego = 0;
        }else cout<<" ";
        int puntaje_tot = 0;
        if (!array_jug[jugadorActual]->comprobarMazo()) {
            cout<<"TE QUEDASTE SIN CARTAS!"<<endl;
            for (int i = 0; i < numJugadores; i++) {
                if(i != jugadorActual)
                    puntaje_tot += array_jug[i]->getValorCartas(); ///puntaje de cada jugador
            }
            array_jug[jugadorActual]->add_puntaje(puntaje_tot);
              cout << "PUNTAJE DEL JUGADOR SIN CARTAS: " <<puntaje_tot<<endl;
            cout<<endl<<endl;

            delete Baraja;
            for (int i = 0; i < numJugadores; i++) {
                delete array_jug[i];
            }
            List<int> *Baraja = new List<int>();
           for (int i = 0; i < numJugadores; i++)
            array_jug[i] = new List<int>();

            crear_baraja(52, Baraja);
         ///SIGUIENTE RONDAAAAAAAAAAAA
            for (int i = 0; i < numJugadores; i++) {
                array_jug[i]->RepartirBaraja(num_cartas, Baraja);
            }


            if (puntaje_tot > PuntajeGanador[numJugadores]) terminar_juego = 0;

    }
   system("cls");
    }
return 0;
}
