#include "nod.h"
#include <iostream>

/* Constructor fara parametri */
nod::nod() {
    this->valoare = 0;
    this->prioritate = 0;
    this->next = NULL;
}

/* Constructor cu parametri */
nod::nod(int x, int y, nod* p) {
    this->valoare = x;
    this->prioritate = y;
    this->next = p;
}

/* Constructor de copiere */
nod::nod(nod& p) {
    this->valoare = p.valoare;
    this->prioritate = p.prioritate;
    this->next = p.next;
}