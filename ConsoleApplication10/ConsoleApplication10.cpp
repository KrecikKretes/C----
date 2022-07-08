#include <iostream>
#include <forward_list>
#include <string>
#include <stack>
using namespace std;

struct element {
	int id;
	string nazwa;
};

void wyswietl(forward_list<element> le, string opis) {
	int liczba = 0;
	cout << "\n " << opis;
	if (le.empty()) {
		cout << "\nLista jest pusta!";
		return;
	}
	cout << "\nLiczba elementow listy: " << distance(le.begin(), le.end());
	for (const auto& e : le) {
		cout << "\n" << e.id << " " << e.nazwa;
	}
	cout << endl << endl;
	/*for (auto it = le.begin(); it != le.end(); it++) {
		cout << "\n" << it->id << " " << (*it).nazwa;
	} */

	cout << le.begin() -> id << endl << le.front().id;

	forward_list<element> kopia;
	kopia = le;

	for (const auto& e : kopia) {
		
	}

	le.pop_front();
	cout << "\nLiczba elementow listy: " << distance(le.begin(), le.end());
	for (const auto& e : le) {
		cout << "\n" << e.id << " " << e.nazwa;
	}

}

int main() {
	forward_list<element> lista;
	wyswietl(lista, "0 wartosci : ");
	for (int i = 1; i <= 4; i++) {
		cout << "\n wpisz id: ";
		int idd;
		cin >> idd;
		lista.push_front({ idd, "e" + to_string(idd) });
	}
	wyswietl(lista, "Po dodaniu 4 elem : ");

	stack<element> stos;
	cout << "\nCzy pusty? " << boolalpha << stos.empty();
}