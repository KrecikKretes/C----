#include <iostream>
#include <random>
#include <iomanip>
#include <memory>
#include <string>
using namespace std;
random_device rd;

int* losowe(int le, int min, int max) {
	uniform_int_distribution<> ud(min, max);
	int* t = new int[le];
	for (int i = 0; i < le; i++) {
		*(t + i) = ud(rd);
		cout << *(t + i) << " ";
	}
	cout << endl << endl << endl;
	return t;
}
int* nieparzyste(int *tab, int n) {
	int a = 0;
	for (int i = 0; i < n; i++) {
		if (tab[i] % 2 == 1) {
			a++;
		}
	}
	a++;
	int c = 0;
	int* b = new int[a];
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			*(b + i) = --a;
			cout << *(b + i)<<endl;
		}else{
			if (tab[i-1] % 2 == 1) {
				*(b + c) = tab[i - 1];
				c++;
			};
		}
	}
	return b;
}
//Pierwszy element tablicy jest iloscia nieparzystych liczb w tablicy
int main(){
	setlocale(LC_CTYPE, "polish");
	int min;
	cout << "Podaj min";
	cin >> min;
	int max;
	cout << "Podaj max";
	cin >> max;
	int n;
	cout << "Podaj n";
	cin >> n;
	int* tab = losowe(n, min, max);
	int* niep = nieparzyste(tab, n);
	
}
