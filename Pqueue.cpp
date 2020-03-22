#include "Pqueue.h"
#include "nod.h"
#include <iostream>
#include <exception>
using namespace std;

/* Pentru exceptii */
class PQEmpty : public exception{
    const char* what() const throw ()
    {
        return "Coada este goala.";
    }
};
class PQPoz : public exception{
    const char* what() const throw ()
    {
        return "Valoarea introdusa se afla in afara intervalului.";
    }
};


/* Construtor fara parametri */
Pqueue::Pqueue() {
    this->start = NULL;
    this->size = 0;
}

/* Constructor cu parametri*/
Pqueue::Pqueue(int x, int y) {
    nod* p = new nod(x, y, NULL);
    start = p;
    size = 1;
}

/* Constructor de copiere */
Pqueue::Pqueue(Pqueue& cp) {
    this->size = cp.size;
    nod* p = cp.start;
    this->start = new nod(p->valoare, p->prioritate, NULL);

    nod* q = this->start;
    p = p->next;
    while (p != NULL)
    {
        q->next = new nod(p->valoare, p->prioritate, NULL);
        q = q->next;
        p = p->next;

    }
}

/* Destructor */
Pqueue :: ~Pqueue() {
    nod* p = this->start;
    nod* q;
    while (p != NULL) {
        q = p;
        p = p->next;
        delete q;
    }
    this->start = NULL;
    this->size = 0;
}

/* Getters pentru informatiile dintr-un nod care se afla pe o anumita pozitie in PQ*/
int Pqueue::getPrioritate(int poz) {
    int j = 1;
    nod* p = start;
    while (j < poz) {
        p = p->next;
        j++;
    }
    return p->prioritate;
}
int Pqueue::getValoare(int poz) {
    int j = 1;
    nod* p = this->start;
    while (j < poz) {
        p = p->next;
        j++;
    }
    return p->valoare;
}
nod* Pqueue::getNext(int poz) {
    int j = 1;
    nod* p = start;
    while (j < poz) {
        p = p->next;
        j++;
    }
    return p->next;
}

/* Adaugarea elementelor in coada */
void Pqueue::adaugare(int val, int prior) {
    nod* p = new nod(val, prior, NULL);
    if (start == NULL)
        start = p;
    else {
        if (size == 1) {
            if (prior > start->prioritate)
            {
                p->next = start;
                start = p;
            }
            else
                start->next = p;
        }
        else {
            nod* q = start;
            if (q->prioritate < prior) {
                p->next = start;
                start = p;
            }
            else {
                while (q->next != NULL && q->next->prioritate > prior)
                    q = q->next;
                p->next = q->next;
                q->next = p;
            }
        }
    }
    size++;
}

/* Eliminarea elementelor din coada (de pe o anumita pozitie - incepand indexarea de la 1) */
void Pqueue::eliminare(int poz) {
    if (this->size == 0)
        throw PQEmpty();
    else {
        if (poz < 1 || poz > this->size)
            throw PQPoz();
        else {
            nod* p = start;
            if (poz == 1) {  //Daca poz=1, se sterge primul element
                start = start->next;
                delete p;
            }
            else {
                int j = 1;
                while (j < poz - 1)
                {
                    j++;
                    p = p->next;
                }
                nod* q = p->next;
                p->next = q->next;
                delete q;
            }
            this->size--;
        }
    }
}

/* Obtinerea numarului de elemente din coada: returnez size */
int Pqueue::nrElem() {
    return this->size;
}

/* Obtinerea elementului maxim din coada (ca valoare) */
int Pqueue::elemValMax() {
    if (start == NULL)
        throw PQEmpty();
    else {
        int valmaxima = start->valoare;
        nod* p = start->next;
        while (p != NULL)
        {
            if (p->valoare > valmaxima)
                valmaxima = p->valoare;
            p = p->next;
        }
        return valmaxima;
    }
}

/* Obtinerea valorii prioritatii maxime din coada */
int Pqueue::valPriorMax() {
    if (start == NULL)
        throw PQEmpty();
    else
        return this->start->prioritate; //Elementul cu cea mai mare prioritate este primul din coada: "start"
        // sau return this->start->valoare; (nu am inteles daca trebuie returnata valoarea sau prioritatea elementului cu cea mai mare prioritate)
}

/* Obtinerea valorii prioritatii minime din coada */
int Pqueue::valPriorMin() {
    if (start == NULL)
        throw PQEmpty();
    else {
        nod* p = start;
        while (p->next != NULL)
            p = p->next;
        return p->prioritate;  //Elementul cu cea mai mica prioritate este ultimul din coada
         // sau return this->start->valoare; (nu am inteles daca trebuie returnata valoarea sau prioritatea elementului cu cea mai mica prioritate)
    }
}

/* Supraincarcarea operatorului + pentru fuziunea a doua cozi */
Pqueue& Pqueue::operator + (Pqueue& cp) {
    Pqueue* cpnoua = new Pqueue;
    //Adaug toate elementele din coada curenta intr-o coada noua :cpnoua
    nod* p = this->start;
    while (p != NULL) {
        cpnoua->adaugare(p->valoare, p->prioritate);
        p = p->next;
    }
    //Adaug toate elementele din a doua coada in coada noua :cpnoua
    p = cp.start;
    while (p != NULL) {
        cpnoua->adaugare(p->valoare, p->prioritate);
        p = p->next;
    }
    delete p;
    cpnoua->size = this->size + cp.size;
    return *cpnoua;
}

/* Supraincarcarea operatorului ++ care va creste cu 1 prioritatile elementelor din coada: cp++ */
Pqueue& Pqueue::operator ++(int) {
    Pqueue* old = new Pqueue(*this);

    if (this->start == NULL) {
        return *old;
    }

    nod* p = this->start;
    while (p != NULL)
    {
        p->prioritate += 1;
        p = p->next;
    }
    return *old;
}

/* Varianta de supraincarcare ++ : ++cp - Nu am stiut care se cere */
Pqueue& Pqueue:: operator++(){
    nod* p = this->start;
    while(p!=NULL){
        p->prioritate++;
        p=p->next;
    }
    return *this;
}


/* Supraincarcarea operatorului -- care va scadea cu 1 prioritatile elementelor din coada (si elimina elementele cu proprietatea 0) cp-- */
Pqueue& Pqueue::operator -- (int) {
    Pqueue* old = new Pqueue(*this);

    if (this->start == NULL) {
        return *old;
    }
    int ok = 0; //ok devine 1 in momentul in care am gasit primul element care are prioritatea 0 dupa scadere
    int nr = 0; //nr. de elemente parcurse pana la primul element care are prioritatea 0 dupa scadere
    nod* p = this->start;
    while (p != NULL && ok == 0)
    {
        nr++;
        p->prioritate--;
        if (p->prioritate == 0 && ok == 0)
            ok = nr; //in ok retin acum pozitia primului element care are prioritatea 0
        p = p->next;
    }
    //Pe pozitia "ok" se gaseste primul element care are prioritatea 0, deci si elementele de dupa el vor avea prioritatea 0 si trebuie eliminate
    if (ok != 0) // Daca sunt elemente de sters
        while (ok <= this->size)
            this->eliminare(ok);

    return *old;
}

/* Varianta de supraincarcare -- : --cp - Nu am stiut care se cere */
Pqueue& Pqueue:: operator--(){
    int ok = 0; //ok devine 1 in momentul in care am gasit primul element care are prioritatea 0 dupa scadere
    int nr = 0; //nr. de elemente parcurse pana la primul element care are prioritatea 0 dupa scadere
    nod* p = this->start;
    while(p!=NULL && ok==0){
        nr++;
        p->prioritate--;
        if(p->prioritate==0 && ok==0)
            ok=nr;
        p=p->next;
    }
    if (ok != 0) // Daca sunt elemente de sters
        while (ok <= this->size)
            this->eliminare(ok);
    return *this;
}



/* Supraincarcarea operatorului = */
Pqueue& Pqueue::operator = (Pqueue& cp)
{
    this->~Pqueue();
    this->size = cp.size;
    nod* p = cp.start;
    this->start = new nod(p->valoare, p->prioritate, NULL);

    nod* q = this->start;
    p = p->next;
    while (p != NULL) {
        this->adaugare(p->valoare, p->prioritate);
        p = p->next;
    }
    return *this;
}

/* Supraincarcare operator >> */
istream& operator >> (istream& cin, Pqueue& cp) {
    cp.~Pqueue();
    int n, val, prior;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val >> prior;
        cp.adaugare(val, prior);
    }
    return cin;
}

/* Supraincarcare operator << */
ostream& operator << (ostream& cout, Pqueue& cp) {
    nod* p = cp.start;
    int nr = 1;
    while (p != NULL)
    {
        cout << "(" << cp.getValoare(nr) << "," << cp.getPrioritate(nr) << ")" << " , ";
        p = cp.getNext(nr);
        nr++;
    }
    cout << endl;
    return cout;
}


/* Functia care sterge toate elementele din coada incepand cu elementul dat pana la final

void Pqueue::stergereElem(nod* prim) {
    nod* p, * q;
    p = prim;
    while (p != NULL) {
        q = p;
        p = p->next;
        delete q;
        this->size--;
    }
}

*/

/* Supraincarcarea operatorului -- : varianta cu functia "stergereElem"

Pqueue& Pqueue::operator --(int) {
    Pqueue* old = new Pqueue(*this);

    if (this->start == NULL) {
        return *old;
    }

    nod* p = start;
    nod* prev;

    // Caz pentru primul nod
    p->prioritate--;
    if (p->prioritate == 0) {
        this->stergereElem(p);  //Se sterg toate elementele de dupa elementul p(inclusiv)
        this->start = NULL;
        this->size = 0;
        return *old;
    }

    prev = p;
    p = p->next;
    int ok = 0;
    while (p != NULL && ok == 0) {
        p->prioritate--;
        // Verific daca trebuie sa elimin elemente
        if (p->prioritate == 0) {
            this->stergereElem(p);
            prev->next = NULL;
            ok = 1;
        }
        if (ok == 0) {
            prev = p;
            p = p->next;
        }
    }
    return *old;
}
*/
