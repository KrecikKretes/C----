#include <iostream>
#include <math.h>
#include <forward_list>
using namespace std;

const int Rmax = 10;
int liczbaKolizji = 0;
int liczbaPrzesuniec = 0;

void printArray(int tab[], int dlug) {
	if (dlug > 0) {
		cout << tab[0];
	}
	for (int i = 1; i < dlug; i++) {
		cout << ", " << tab[i];
	}
	cout << endl;
	cout << "Liczba kolizji : " << liczbaKolizji<<endl;
	if (liczbaPrzesuniec != 0) {
		cout << "Liczba przesuniec : " << liczbaPrzesuniec << endl;
	}
}

unsigned int obliczHash1(int klucz) {
	return klucz % Rmax;
}

void wstawZKolizja(int tab[], int elem) {
	int poz = obliczHash1(elem);
	
	//Mają takie same reszty z dzielenia
	if (tab[poz] != 0) {
		liczbaKolizji++;
		cout << "----------" << endl << tab[poz] << " zostal nadpisany przez " << elem << endl << "-----------"<< endl <<endl;
	}
	if (elem != 0) {
		tab[poz] = elem;
	}	
}

void printList(forward_list<int>& lista) {
	for (auto el : lista) {
		cout << el << ", ";
	}
}
int printListReturn(forward_list<int>& lista) {
	for (auto el : lista) {
		return el;
	}
}

void printArray(forward_list<int>* tab, int dlug) {
	for (int i = 0; i < dlug; i++) {
		cout << "Poz. " << i << ": ";
		printList(tab[i]);
		cout << endl;
	}
	cout << endl;
	cout << "Liczba kolizji : " << liczbaKolizji << endl;
}

void wstaw(forward_list<int>* tab, int elem) {
	int poz = obliczHash1(elem);
	if (!tab[poz].empty() && elem != 0){
		liczbaKolizji++;
		cout << endl <<"----------" << endl << printListReturn(tab[poz]) << " zostal nadpisany przez " << elem << endl << "-----------" << endl << endl;
	}
	tab[poz].push_front(elem);
}


void wstawPL(int tab[], int elem) {
	int poz, zw=0;
	do{
		if (zw != 0) {
			liczbaPrzesuniec++;
			if (zw == 1) {
				liczbaKolizji++;
			}
		}
		poz = (obliczHash1(elem)+ zw) % Rmax;
		zw++;
	} while (tab[poz] != 0);
	tab[poz] = elem;
}

int main(){
	cout << endl << "-------- Tablica --------" << endl;

	int tab[Rmax] = { 0 };
	int tabP[10] = { 14,15,1,7,3,13,5,10,6,19 };
	printArray(tabP, 10);
	for (int i = 0; i < 10; i++) {
		wstawZKolizja(tab, tabP[i]);
	}
	printArray(tab, 10);
	

	cout << endl <<"-------- Lista --------"<<endl;

	liczbaKolizji = 0;
	forward_list<int>* tabH2 = new forward_list<int>[Rmax];
	for (int i = 0; i < 10; i++) {
		wstaw(tabH2, tabP[i]);
	}
	printArray(tabH2, Rmax);


	cout << endl <<endl << "-------- Probkowanie --------" << endl <<endl;

	liczbaKolizji = 0;
	int tabPL[10] = { 0 };
	for (int i = 0; i < 10; i++) {
		wstawPL(tabPL, tabP[i]);
	}
	printArray(tabPL, 10);
}