#include <iostream>
using namespace std;

struct wezel{
    int klucz;
    wezel* lewe;
    wezel* prawe;
};

wezel* drzewo = NULL;

void insert_BST(int x, wezel*& w) {
    if (w == NULL) {
        w = new wezel;
        w->klucz = x;
        w->lewe = NULL;
        w->prawe = NULL;
    }
    else {
        if (x < w->klucz) {
            insert_BST(x, w->lewe);
        }
        else {
            insert_BST(x, w->prawe);
        }
    }
}

void build_BST(int n, wezel*& w) {
    for (int i = 1; i <= n; i++) {
        cout << "Wpisz wartosc : ";
        int x;
        cin >> x;
        insert_BST(x, w);
    }
}

void wyswietl_BST_inorder(wezel* &w) {
    if (w != NULL) {
        if (w->lewe == NULL) {
            cout << endl << w->klucz;
        }
        else {
            wyswietl_BST_inorder(w->lewe);
            cout << endl << w->klucz;
        }
        if (w->prawe != NULL) {
            wyswietl_BST_inorder(w->prawe);
        }
    }
}

int check_BST(wezel*& w, int x) {
    if (x == w->klucz) {
        cout << "\nZnaleziono klucz. Adres klucza : " << w;
    }
    else {
        if (x < w->klucz) {
            if (w->lewe == NULL) {
                cout << "\nKlucza nie ma";
                return 0;
            }
            else {
                check_BST(w->lewe, x);
            }
        }
        else {
            if (w->prawe == NULL) {
                cout << "\nKlucza nie ma";
                return 0;
            }
            else {
                check_BST(w->prawe, x);
            }
        }
    }
}

void delete_BST(wezel* w, int x) {
    wezel *wk = w;
    wezel *p;
    if (x == w->klucz) {
        w = w->lewe;
        p = w->prawe;
        p->klucz = w->prawe->klucz;
        delete w;
        do{
            if (p->klucz < wk->lewe->klucz) {
                w = 
            }
        }(w != NULL);
    }
    else {
        if (x < w->klucz) {
            if (w->lewe == NULL) {

            }
            else {
                delete_BST(w->lewe, x);
            }
        }
        else {
            if (w->prawe == NULL) {
                
            }
            else {
                delete_BST(w->prawe, x);
            }
        }
    }
}

void wyswietl_drzewo(wezel* w, int h = 0) {
    if (w != NULL) {
        wyswietl_drzewo(w->prawe, h + 1);
        for (int i = 1; i <= h; i++) {
            cout << "  ";
        }
        cout << w->klucz << "\n";
        wyswietl_drzewo(w->lewe, h + 1);
    }
}

void wyswietl_drzewo1(wezel* w, int h = 1) {
    if (w != NULL) {
        for (int i = 0; i < (h * 2); i++) {
            for (int j = 1; j < h * 8; j=j+h) {
                cout << " ";
            }
            cout << w->klucz;
            for (int j = 1; j < h * 8; j = j + h) {
                cout << " ";
            }
        };
        cout << endl;

        wyswietl_drzewo(w->prawe, h + 1);
        for (int i = 1; i <= h; i++) {
            cout << "  ";
        }
        cout << w->klucz << "\n";
        wyswietl_drzewo(w->lewe, h + 1);
    }
}


int main(){
    int x;
    build_BST(10, drzewo);
    wyswietl_drzewo(drzewo);
    cout << endl << endl << endl;
    wyswietl_BST_inorder(drzewo);
    cin >> x;
    check_BST(drzewo, x);


}