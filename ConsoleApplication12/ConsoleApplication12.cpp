#include <iostream>
#include<cmath>
using namespace std;

void printArray(int tab[], int dlu) {
	if (dlu > 0) {
		cout << tab[0];
	}
	for (int i = 1; i < dlu; i++) {
		cout << ", " << tab[i];
	}
	cout << endl;
}

int linearSearch(int tab[], int dlu, int x) {
	for (int i = 0; i < dlu; i++) {
		if (x == tab[i]) {
			return ++i;
		}
	}
	return -1;
}

int binarySearchITER(int tab[], int dlu, int x) {
	int lewy = 0, prawy = dlu - 1, srodek = 0;
	bool znaleziono = false;

	while (lewy <= prawy && znaleziono == false) {
		cout << lewy << "     " << prawy<<endl;
		
		srodek = (lewy + prawy) / 2;
		if (x == tab[srodek]) {
			znaleziono = true;
		}
		else {
			if (x > tab[srodek]) {
				lewy = srodek + 1;
			}
			else {
				prawy = srodek - 1;
			}
		}
	}
	if (znaleziono) {
		return srodek;
	}
	else {
		return -1;
	}
}



int binarySearchREKU(int tab[], int lewy, int prawy, int x) {
	if(lewy <= prawy) {
		int srodek = (lewy + prawy) / 2;
		if (x == tab[srodek]) {
			return srodek;
		}else{
			if (x > tab[srodek]) {
				binarySearchREKU(tab, srodek, prawy, x);
			}
			else {
				binarySearchREKU(tab, lewy, srodek, x);
			}
		}
	}
}

void zamien(int tab[], int a, int b) {
	int temp = tab[a];
	tab[a] = tab[b];
	tab[b] = temp;
}

int podzial(int tab[], int lewy, int prawy) {
	int x = lewy;
	for (int i = lewy + 1; i <= prawy; i++) {
		if (tab[i] < tab[lewy]) {
			x++;
			zamien(tab, x, i);
		}
	}
	zamien(tab, lewy, x);
	return x;
}

int hoareSearch(int tab[], int lewy, int prawy, int k) {
	if (lewy == prawy) {
		return tab[lewy];
	}
	int x = podzial(tab, lewy, prawy);
	if (k == x) {
		return k;
	}
	else {
		if (k < x) {
			hoareSearch(tab, lewy, x, k);
		}
		else {
			hoareSearch(tab, x, prawy, k);
		}
	}
}



void quickSort(int tab[], int lewy, int prawy) {
	if (lewy < prawy) {
		int os = podzial(tab, lewy, prawy);
		quickSort(tab, lewy, os - 1);
		quickSort(tab, os + 1, prawy);
	}
}

int main(){
	int tab[6] = { 5, 7, 9, 11, 14, 16 };
	int tab2[6] = { 1,10,13,12,9,18 };
	int tab3[6] = { 9,14,5,4,13,12 };

	cout << "------------------------------------------" << endl;
	printArray(tab, 6);
	cout << "------------------------------------------" << endl;

	cout << linearSearch(tab, 6, 0)<<endl;
	cout << linearSearch(tab, 6, 5) << endl;
	cout << linearSearch(tab, 6, 11) << endl;
	cout << linearSearch(tab, 6, 16) << endl;

	cout << "------------------------------------------" << endl;
	printArray(tab2, 6);
	cout << "------------------------------------------" << endl;

	cout << linearSearch(tab2, 6, 10) << endl;
	cout << linearSearch(tab2, 6, 13) << endl;
	cout << linearSearch(tab2, 6, 9) << endl;

	cout << "------------------------------------------" << endl;
	printArray(tab, 6);
	cout << "------------------------------------------" << endl;

	cout << binarySearchITER(tab, 6, 0) <<endl<<endl;
	cout << binarySearchITER(tab, 6, 5) << endl<<endl;
	cout << binarySearchITER(tab, 6, 11) << endl<<endl;
	cout << binarySearchITER(tab, 6, 16) << endl<<endl;

	cout << "------------------------------------------"<<endl;
	printArray(tab, 6);
	cout << "------------------------------------------" << endl;
	cout << binarySearchREKU(tab,0, 6, 5) << endl << endl;
	cout << binarySearchREKU(tab,0, 6, 11) << endl << endl;
	cout << binarySearchREKU(tab,0, 6, 16) << endl << endl;

	quickSort(tab3, 0, 5);
	cout << "------------------------------------------" << endl;
	printArray(tab3, 6);
	cout << "------------------------------------------" << endl;
	cout << hoareSearch(tab3, 0, 5, 1);



}