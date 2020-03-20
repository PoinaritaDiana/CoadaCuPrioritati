#pragma once
#include "nod.h"
#include <iostream>
using namespace std;

class Pqueue {
    nod* start;
    int size;

    /* Pentru supraincarcarea operatorului "--" era mai la indemana daca aveam functia urmatoare care sterge toate elementele incepand de la un anumit nod (inclusiv)
     * Dar nu era neaparat necesara pentru ca exista metoda de eliminare a nodurilor

    private:
        void stergereElem(nod*);  //Sterge toate elementele din coada incepand cu elementul dat pana la final
    */
private:
    /* Getters pentru informatiile dintr-un nod care se afla pe o anumita pozitie in PQ*/
    int getPrioritate(int);
    int getValoare(int);
    nod* getNext(int);


public:
    Pqueue();  //Construtor fara parametri
    Pqueue(int, int);  //Constructor cu parametri
    Pqueue(Pqueue&);  //Constructor de copiere
    ~Pqueue();  //Destructor

    void adaugare(int, int);  //Adaugarea elementelor in coada
    void eliminare(int poz = 1);  //Eliminarea elementelor din coada: daca nu se introduce niciun numar, default este 1 (primul numar)
    int nrElem();  //Obtinerea numarului de elemente din coada
    int elemValMax(); //Obtinerea elementului maxim din coada (ca valoare)
    int valPriorMax(); //Obtinerea valorii prioritatii maxime din coada
    int valPriorMin(); //Obtinerea valorii prioritatii minime din coada

    Pqueue& operator +(Pqueue&);  //Supraincarcarea operatorului + pentru fuziunea a doua cozi
    Pqueue& operator ++(int);  //Supraincarcarea operatorului ++ care va creste cu 1 prioritatile elementelor din coada
    Pqueue& operator --(int); //Supraincarcarea operatorului -- care va scadea cu 1 prioritatile elementelor din coada

    Pqueue& operator = (Pqueue&);  //Supraincarcarea operatorului =

    //Supraincarcarea operatorilor de citire si afisare
    friend istream& operator >> (istream&, Pqueue&);
    friend ostream& operator << (ostream&, Pqueue&);

};