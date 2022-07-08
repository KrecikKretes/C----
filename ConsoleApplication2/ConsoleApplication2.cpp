#include <iostream>
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
void wyswietl(unique_ptr<pomiar> &a){
	cout << a->numer << "  " << a->opis << "  " << a->odczyt << endl;
}


int main(){
	
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