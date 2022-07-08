#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <random>
#include <memory>
using namespace std;

struct rower {
    int id;
    string nazwa;
    float cena;
    rower(int _id, string _nazwa, float _cena) {
        id = _id;
        nazwa = _nazwa;
        cena = _cena;
    }
    rower(){}
};
void wyswietl(vector<rower> vr) {
    for (auto e : vr)
        cout << "\n" << e.id << " " << e.nazwa << " " << e.cena;
}
auto wybraneWgNazwy(vector<rower> vr) {
    char lit;
    cout << "\n Wpisz 1. lit nazwy: ";
    cin >> lit;
    auto itf = vr.begin();
    vector<rower> wybrane{};
    while (itf != vr.end()) {
        itf = find(itf, vr.end(), lit);
        if (itf != vr.end()) {
            wybrane.push_back(vr[itf - vr.begin()]);
            itf++;
        }
    }
    return wybrane;
}

int main(){
    setlocale(LC_CTYPE, "polish");
    vector<rower> rowery{ 2 };
    rowery[0] = { 1, "kellys", 2900 };
    rowery.at(1) = { 2, "giant", 3400 };
    rowery.push_back({ 3, "kellys", 1900 });
    rower r1({ 4,"kross", 2300 });
    rowery.push_back(r1);
    rower* r2 = new rower(5, "ktm", 2800);
    rowery.push_back(*r2);
    auto upr = make_unique<rower>(6, "ghost", 4600);
    rowery.push_back(*upr);
    wyswietl(rowery);

    cout << " \n Wybrane rowery: ";
    wyswietl(wybraneWgNazwy(rowery));
}
