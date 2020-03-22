#include <iostream>
#include "nod.h"
#include "Pqueue.h"
using namespace std;

int main() {
	
	/* Am considerat ca daca valorea atribuita prioritatii este mai mare, atunci elementul respectiv are prioritate mai mare in coada
	 * De exemplu, pentru elementele de tipul (valoare, prioritate), PQ: start-> (2,5),(4,3),(2,1), unde (2,5) este elementul cu prioritatea cea mai mare
	 * Pozitia 1 inseamna primul element din coada (start/cel cu prioritatea cea mai mare)
	 */
	
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
	
	/* cp1.eliminare(4);  // daca size < 4, exceptie: "Valoarea introdusa se afla in afara intervalului"
	 cout << cp1;
	 */
	
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
	cout << cp4--;
	cout << cp4;
	
	return 0;
}
