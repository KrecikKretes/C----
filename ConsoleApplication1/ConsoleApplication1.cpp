#include <iostream>
#include <random>
#include <iomanip>
using namespace std;
random_device rd;

int* tab1w(int le, int min, int max) {
	uniform_int_distribution<> ud(min, max);
	int* t = new int[le];
	for (int i = 0; i < le; i++) {
		*(t + i) = ud(rd);
	}
	return t;
}

int** tab2w(int lw, int lk, int min, int max) {
	uniform_int_distribution<> ud(min, max);
	int** t = new int*[lw];
	for (int i = 0; i < lw; i++) {
		*(t + i) = new int[lk];
		for (int j = 0; j < lk; j++) {
			*(*(t + i) + j) = ud(rd);
		}
	}
	return t;
}

int* tab(int** t,int lw, int lk, int &b) {
	int  q = lw * lk;
	int* n = new int[q];
	for (int i = 0; i < q; i++) {
		n[i] = 0;
	}
	for (int i = 0; i < lw; i++) {
		for (int j = 0; i < lk; j++) {
			for (int a = 0; a <= b; a++) {
				if (t[i][j] != n[a]) {
					n[b] = t[i][j];
					b++;
				}
				else {
					break;
				}
			}
		}
	}
	return n;
}

void wyswietl(int* t, int le) {
	for (int i = 0; i < le; i++) {
		cout << *(t + i) << " ";
	}
}

void wyswietl2(int** t, int lw, int lk) {
	for (int i = 0; i < lw; i++) {
		for (int j = 0; j < lk; j++) {
			cout << setw(3)<<*(*(t + i) + j) << " ";
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_CTYPE, "polish");
	cout << "Podaj liczbę elementów: ";
	int n;
	cin >> n;
	int min = 1;
	int max = 9;
	int* t1 = tab1w(n, min, max);
	wyswietl(t1, n);

	cout << "\n\n\n";

	cout << "Podaj liczbę wierszy: ";
	int w;
	cin >> w;
	cout << "Podaj liczbę kolumn: ";
	int k;
	cin >> k;
	int** t2 = tab2w(w,k,min, max);
	wyswietl2(t2, w,k);
	int b = 0;
	int* t3 = tab(t2, w, k, b);
	

	delete[] t1;
	for (int i = 0; i < w; i++) {
		delete[] t2[i];
	}
	delete[] t2;
}


/* #include <iostream>
#include <memory>
#include <string>
using namespace std;

struct pomiar {
	int numer;
	string opis;
	float odczyt;
	void wyswietl();

	pomiar(int _numer, string _opis, float _odczyt) {
		numer = _numer;
		opis = _opis;
		odczyt = _odczyt;
		cout << "Powstal obiekt typu pomiar \n";
	}
	pomiar() {
		cout << "Powstal puty obiekt typu pomiar \n";
	}

	~pomiar() {
		cout << "Usuwanie obiektu typu pomiar o numerze " << numer << endl;
	}
};
void pomiar::wyswietl() {
	cout << numer << "  " << opis << "  " << odczyt << endl;
}
void wyswietl(unique_ptr<pomiar>& a) {
	cout << a->numer << "  " << a->opis << "  " << a->odczyt << endl;
}


int main() {

	{
		pomiar p1{ 1,"st",23.45f };
		pomiar* wp1 = &p1;
		cout << "P1 wskaznik: \n";
		wp1->wyswietl();

		pomiar* p2 = new pomiar{ 12,"dn",76.4f };
		p2->wyswietl();
		pomiar* p3 = new pomiar{};
		p3->numer = 13;
		p3->opis = "dn";
		p3->odczyt = 0.89f;
		p3->wyswietl();
		cout << "Usuwanie P2 i P3 za pomoca delete \n";
		delete p2;
		delete p3;
	}

	cout << endl << endl << endl << endl;
	{
		unique_ptr<pomiar> upp4(new pomiar);
		upp4->numer = 114;
		upp4->opis = "up";
		upp4->odczyt = 56.2f;
		upp4->wyswietl();
		auto upp5 = make_unique<pomiar>(115, "up", 39.87f);
		upp5->wyswietl();
		wyswietl(upp5);
	}


	cout << endl << endl << endl << endl;

	{
		auto spp7 = make_shared<pomiar>(227, "sp", 2.1f);
		spp7->wyswietl();
		shared_ptr<pomiar> spp8;
		spp8 = spp7;
		cout << "Spp7 wyswietlony za pomoca spp8 \n";
		spp8->wyswietl();
		cout << "Adresy spp7 oraz spp8: " << spp7.get() << "    " << spp8.get() << endl;
		cout << "Liczba wskaznikow pokazujaca na obiekt: " << spp8.use_count() << endl;
	}
	cout << "Koniec programu\n";

	cout << endl << endl << endl << endl;

	{
		auto upp5 = make_unique<pomiar>(115, "up", 39.87f);
		wyswietl(upp5);
	}
}
*/