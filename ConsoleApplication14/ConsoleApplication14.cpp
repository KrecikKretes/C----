#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

int ilosc = 0;
int ilosc2 = 0;

void przerwa() {
	cout << endl << " ----------------- " << endl << endl;
}

void wyswietl(unordered_map<string, int> zlote_medale) {
	for (auto iter = zlote_medale.begin(); iter != zlote_medale.end(); iter++) {
		if (iter == zlote_medale.begin()) {
			ilosc == 0;
		}
		ilosc++;
		cout << iter->first << " : " << iter->second << endl << endl;
	}
}

void wyswietl(unordered_map<int, int> potegi) {
	for (auto iter = potegi.begin(); iter != potegi.end(); iter++) {
		cout << iter->first << " : " << iter->second << endl << endl;
	}
}


void wyswietl_dokladnie(unordered_map<string, int> zlote_medale) {
	for (int i = 0; i < zlote_medale.bucket_count(); i++) {
		if (i == 0) {
			ilosc2 = 0;
		}
		cout << "Bucket size : " << zlote_medale.bucket_size(i) << "     i = " << i << endl;
		if (zlote_medale.bucket_size(i) == 0) {
			ilosc2++;
		}

	}
	cout << "Bucket count : " << zlote_medale.bucket_count() << endl;
	cout << "Puste pojemniki : " << ilosc2 << endl;
}


int main() {
	unordered_map<string, int> slownik1;

	slownik1["klucz1"] = 10;
	slownik1["klucz2"] = 20;

	cout << "Element o kluczu klucz1 ma wartosc: " << slownik1.at("klucz1") << endl;

	przerwa();

	unordered_map<string, int> zlote_medale = {
		{"Australia", 1},
		{"Kanada", 4}
	};

	zlote_medale["Austria"] = 7;
	zlote_medale["Lotwa"] = 0;
	zlote_medale["USA"] = 8;

	zlote_medale.insert(make_pair("Nowa Zelandia", 2));

	string klucz = "klucz";

	if (zlote_medale.find(klucz) == zlote_medale.end()) {
		cout << "Nie znaleziono elementu o kluczu : " << klucz << endl;
	}
	else {
		cout << "Znaleziono element o kluczu : " << klucz << endl;
	}

	unordered_map<string, int>::iterator it = zlote_medale.find(klucz);

	if (it == zlote_medale.end()) {
		cout << "Nie znaleziono elementu o kluczu : " << klucz << endl;
	}
	else {
		cout << "Znaleziono element o kluczu : " << klucz << endl;
	}
	
	przerwa();

	cout << "Wszystkie panstwa i medale: \n";

	wyswietl(zlote_medale);
	
	
	wyswietl_dokladnie(zlote_medale);

	przerwa();

	float load_factor = (float)ilosc / (float)zlote_medale.bucket_count();
	cout << "Load factor reczny : " << load_factor<<endl;
	cout << "Load factor auto : " << zlote_medale.load_factor()<<endl;


	przerwa();

	string klucz_usuwania = "Lotwa";
	zlote_medale.erase(klucz_usuwania);
	wyswietl(zlote_medale);
	wyswietl_dokladnie(zlote_medale);

	przerwa();

	for (auto iter = slownik1.begin(); iter != slownik1.end(); iter++) {
		zlote_medale.insert(make_pair(iter->first, iter->second));
	}

	wyswietl(zlote_medale);
	wyswietl_dokladnie(zlote_medale);

	przerwa();

	unordered_map<int, int> potegi;
	for (int i = 0; i < 21; i++) {
		potegi.insert(make_pair(i, i * i));
	}
	wyswietl(potegi);


	przerwa();


	unordered_map<string, int> slownik;
	string tekst = "struktura slownik algorytm struktura cplusplus algorytm program slownik biblioteka slownik";
	stringstream ss(tekst);
	string slowo;
	int zast;
	while (ss >> slowo) {
		if (slownik.find(slowo) == slownik.end()) {
			slownik.insert(make_pair(slowo, 1));
		}
		else {
			slownik[slowo]++;
		}
	}
	wyswietl(slownik);

	przerwa();
}