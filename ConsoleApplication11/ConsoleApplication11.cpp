#include <iostream>
using namespace std;

void printArray(int tab[], int dlugosc, int ilosc, int j) {
	for (int i = 0; i < j; i++) {
		cout << tab[i] << ", ";
	}
	cout << "  ---  ";
	for (int i = j; i < dlugosc; i++) {
		cout << ", " << tab[i];
	}
	cout << "    " << ilosc;
	cout << endl;
}

void printArray(int tab[], int dlugosc) {
	for (int i = 0; i < dlugosc; i++) {
		cout << tab[i] << ", ";
	}


	cout << endl;
}

void insertionSert(int tab[], int dlugosc) {
	int ilosc = 0;
	for (int i = 1; i < dlugosc; i++) {
		int x = i;
		int j = i;
		int elem = tab[j];
		while (j > 0 && tab[j - 1] > elem) {
			tab[j] = tab[j - 1];
			j--;
			cout << endl << endl;
			ilosc++;
			printArray(tab, dlugosc, ilosc, x);
		}
		tab[j] = elem;

	}
}

void bubbleSort(int tab[], int dlugosc) {
	int temp;
	int zamiana = 0;
	int przebieg = 0;
	bool z = false;
	for (int i = 0; i < dlugosc; i++) {
		for (int j = 1; j < dlugosc - i; j++) {
			if (tab[j] < tab[j - 1]) {
				temp = tab[j];
				tab[j] = tab[j - 1];
				tab[j - 1] = temp;
				z = true;
				zamiana++;
				cout << " -----";
				printArray(tab, dlugosc);
			}
			
			przebieg++;
		}
		if (z == false) return;
		z = false;
	}
	cout << " Przebieg: " << przebieg << endl << "Zamieniono : " << zamiana << endl << "Puste : " << przebieg - zamiana;
}


int main() {
	int tab[6] = { 11, 13, 8, 1, 15, 6 };
	int dlug = 6;
	printArray(tab, dlug, 0, 0);
	cout << endl << endl;
	//insertionSert(tab, dlug);
	bubbleSort(tab, dlug);
	cout << endl << endl;
	printArray(tab, dlug, 0, 0);

	/*
		int tab2[6] = { 5,12,3,18,15,14 };
		printArray(tab2, dlug, 0,0);
		cout << endl << endl;
		insertionSert(tab2, dlug);
		cout << endl << endl;
		printArray(tab2, dlug, 0,0);

		int tab3[15] = { 9,29,3,11,2,16,12,18,19,13,6,8,14,7,17 };
		printArray(tab3, 15, 0,0);
		cout << endl << endl;
		insertionSert(tab3, 15);
		cout << endl << endl;
		printArray(tab3, 15, 0,0);
		*/
}