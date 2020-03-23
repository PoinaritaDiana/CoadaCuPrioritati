#include <iostream>
#include "nod.h"
#include "Pqueue.h"
#include <cassert>
using namespace std;

void pqueueTests() {
	Pqueue pq1;
	pq1.adaugare(7,4);
	pq1.adaugare(4,5);
	pq1.adaugare(5,2);
	// Pq1: (4,5),(7,4),(5,2)

	assert(pq1.nrElem() == 3);  //test obtinere nr. elemente
	assert(pq1.valPriorMin() == 2);   //test obtinere valoare prioritate minima din coada
	pq1.eliminare(); //Se elimina primul element: Pq1:(7,4),(5,2)
	assert(pq1.nrElem() == 2);  //test pentru a vedea daca elementul a fost eliminat
	assert(pq1.valPriorMax() == 4);  //test obtinere valoare prioritate maxima din coada
	assert(pq1.elemValMax() == 7);  //test obtinere element maxim din coada (ca valoare)


	Pqueue pq2(1, 7);
	pq2.adaugare(5, 1);
	pq2.adaugare(4, 3);
	// Pq2: (1,7),(4,3),(5,1)
	
	//test supraincarcare operator = si test supraincarcare operator []
	Pqueue pq3;
	pq3 = pq2; // Pq3: (1,7),(4,3),(5,1)
	for (int i = 1; i <= pq2.nrElem(); i++) {
		assert(pq2[i] == pq3[i]);
	}

	//test supraincarcare operator ++
	++pq1; // Pq1: (7,5),(5,3)

	//test supraincarcare operator --
	--pq2; //Pq2: (1,6),(4,2)

	//test supraincarcare operator + 
	Pqueue pq4;
	pq4 = pq1 + pq2;  // Pq4: (1,6),(7,5),(5,3),(4,2)
	assert(pq4[1] == 1);
	assert(pq4[2] == 7);
	assert(pq4[3] == 5);
	assert(pq4[4] == 4);
	assert(pq4.nrElem() == 4);  //test obtinere nr. elemente


	//test destructor
	pq1.~Pqueue();
	assert(pq1.nrElem() == 0);
}

int main() {
	
	/* Am considerat ca daca valorea atribuita prioritatii este mai mare, atunci elementul respectiv are prioritate mai mare in coada
	 * De exemplu, pentru elementele de tipul (valoare, prioritate), PQ: start-> (2,5),(4,3),(2,1), unde (2,5) este elementul cu prioritatea cea mai mare
	 * Pozitia 1 inseamna primul element din coada (start/cel cu prioritatea cea mai mare)
	 */

	pqueueTests();
	cout << "Testele au trecut";

	/*
	Pqueue cp1;
	cin >> cp1;
	cout << cp1;

	Pqueue cp2;
	cin >> cp2;
	cout << cp2;

	Pqueue cp3;
	cout << cp3;

	// cp3.eliminare();  // Exceptie : "Coada este goala"

	Pqueue cp4(4, 6);
	cout << cp4;

	Pqueue cp5(2, 5);
	cout << cp5;
	
	// cp1.eliminare(4);  // daca size < 4, exceptie: "Valoarea introdusa se afla in afara intervalului"
	
	cp1.adaugare(6, 3);
	cout << cp1;
	cout << cp1.elemValMax() << endl;

	cp3.adaugare(17, 8);
	cp3.adaugare(2, 6);
	cout << cp3;
	cout << cp3.valPriorMax() << endl;
	cout << cp3.valPriorMin() << endl;

	cp5 = cp4;
	cout << cp5;
	cout << cp4;

	cp4.adaugare(2, 3);
	cout << cp4;
	cout << cp5;

	cout << cp4--;
	cout << cp4;

	cout << cp4 + cp5;

	cout << cp4++;
	cout << cp4;

	cp4.adaugare(1, 1);
	cp4.adaugare(3, 1);
	cout << cp4;
	cout << --cp4;
	*/
	
	return 0;
}
