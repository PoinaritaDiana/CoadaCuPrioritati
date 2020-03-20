#pragma once
#include <iostream>
class Pqueue;
class nod
{
    int valoare;
    int prioritate;
    nod* next;

public:
    friend Pqueue;
    nod();  //constructor fara parametri
    nod(int, int, nod*); //constructor cu parametri
    nod(nod&); //constructor de copiere
    // ~nod();  ?Nu cred ca este nevoie


 /* Pentru supraincarcarea operatorului << am nevoie de getters pentru nod, care trebuie declarati public in clasa nod;
  * In cerintele de la laborator este observatia ca toate metodele care nu sunt cerute explicit sa fie declarate private;
  * Deci am facut getters pentru nod in clasa Pqueue in functie de pozitia pe care o avea nodul respectiv in coada
 */
};

