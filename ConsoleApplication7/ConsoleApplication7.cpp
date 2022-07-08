#include <iostream>
using namespace std;


struct element {
    int id;
    string nazwa;
    element* nastepny;
    static int ilosc;
};
int element::ilosc = 0;

void wyswietl(element* wl) {
    if (wl == nullptr) {
        cout << "\n Lista pusta: ";
    }
    else {
        cout << "\n Ilosc elementow na liscie: " << wl->ilosc;
        while (wl != nullptr) {
            cout << "\n Id: " << wl->id << "\n  Nazwa: " << wl->nazwa << "\n    Adres: " << wl << ", nastepny = " << wl->nastepny;
            wl = wl -> nastepny;
        }
    }
    cout << "\n";
}
void dodaj(element* &wl){
    element* wn = new element;
    cout << "\n Podaj id:";
    cin >> wn->id;
    cout << " Podaj nazwe: ";
    cin >> wn->nazwa;
    wn->ilosc++;
    wn->nastepny = wl;
    wl = wn;
    cout << " Adres do listy: " << wl << endl;
}
void usun(element*& wl, int i) {
    element* wn = new element;
    
    if (i == 1) {
        /*for (int j = 1; j < wl->ilosc; j++) {
            wn = wl;
            wl->id = wn->id;
            wl->nazwa = wn->nazwa;
            wl->nastepny = wn->nastepny;
        }
        wl->ilosc--;
        delete wl;*/
        wl = wl->nastepny;
        delete wl;
        wl->ilosc--;
    }else{

    }
}


int main(){
    element* lista = nullptr;
    dodaj(lista);
    dodaj(lista);
    dodaj(lista);
    wyswietl(lista);
    usun(lista, 1);
    wyswietl(lista);
}
