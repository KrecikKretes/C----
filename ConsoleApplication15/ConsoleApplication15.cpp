#include <iostream>
#include <string>
using namespace std;

const int K = 26 * 2 + 1;

void smallPrzerwa() {
    cout << endl << endl << "--------" << endl << endl;
}
void przerwa() {
    cout << endl<<endl << "---------------" << endl<<endl;
}
void bigPrzerwa(string tekst) {
    cout << endl << endl << "------------  "<<tekst<<"  ---------------------" << endl << endl;
}

int szukajNaiwny(string wzorzec, string tekst) {
    int N = tekst.length(), M = wzorzec.length();
    int i = 0, j = 0;
    while (i < N && j < M) {
        if (tekst[i] != wzorzec[j]) {
            i = i - j;
            j = -1;
        }
        i++;
        j++;
    }
    if (j == M) {
        return i - M+1;
    }else {
        return -1;
    }
}

void printSzukawnie(string s, int l, int p, int poziom) {
    for (int i = 0; i < poziom; i++) {
        cout << " ";
    }
    cout << s.substr(l, p) << endl;
}
int szukajNaiwnyOpis(string wzorzec, string tekst) {
    int N = tekst.length(), M = wzorzec.length();
    int i = 0, j = 0;
    while (i < N && j < M) {
        cout << " i = " << i << " j = " << j << endl;
        cout << tekst << endl;
        printSzukawnie(wzorzec, 0, M, i - j);
        if (tekst[i] != wzorzec[j]) {
            i = i - j;
            j = -1;
        }
        if (j != -1) {
            cout << "Znak " << ++j << " wzorca zgodny ze znakiem " << ++i << " tekstu";
            j--;
            i--;
        }else {
            cout << "\nNiezgodnosc znakow";
        }
        cout << endl << endl;
        i++;
        j++;
    }
    if (j == M) {
        return i - M+1;
    }else {
        return -1;
    }
}

void obliczPrzesunieciaKMP(int tab[], string wzorzec, int M) {
    int i = 0, j = 0;
    tab[0] = -1;
    for (i = 0, j = -1; i < M; i++, j++) {
        tab[i] = j;
        while (j >= 0 && wzorzec[i] != wzorzec[j]) {
            j = tab[j];
        }
    }
}

int szukajKMP(string wzorzec, string tekst) {
    cout << endl << "i - znak wzorca, j - znak tekstu" << endl;

    int N = tekst.length(), M = wzorzec.length();
    int i = 0, j = 0;

    int* przesun = new int[M];

    obliczPrzesunieciaKMP(przesun, wzorzec, M);

    smallPrzerwa();
    cout << endl<<"Tablica przesuniec: "<<endl;
    for (int x = 0; x < M; x++) {
        cout << przesun[x] <<endl;
    }
    cout << "Koniec tablicy" << endl << endl;

    for (i = 0, j = 0; i < N && j < M; i++, j++) {
        cout <<endl << "i = " << i << endl << "j = " << j << endl << endl;
        while (j >= 0 && tekst[i] != wzorzec[j]) {
            j = przesun[j];
        }
        cout <<endl<< tekst<<endl;
        printSzukawnie(wzorzec, 0, M, i - j);
        cout <<"Zgodne znaki:  1 - "<< (j+1) <<endl;
        cout << "Zgodne znaki w tekscie:  "<< (i-j)+1 << " do " << i+1 << endl;
        smallPrzerwa();
    }

    delete[] przesun;
    if (j == M) {
        return i - M + 1;
    }else {
        return -1;
    }
}

int indeks(char c) {
    switch (c)
    {
        case ' ': return 0;
        default:
            if (islower(c)) {
                return c - 'a' + 1;
            }else {
                return c - 'A' + 27;
            }
    }
}
void obliczPrzesunieciaBM(int tab[], string wzorzec, int M) {
    for (int i = 0; i < K; i++) {
        tab[i] = M;
    }
    for (int i = 0; i < M; i++) {
        tab[indeks(wzorzec[i])] = M - i - 1;
    }
}

int szukajBM(string wzorzec, string tekst) {
    int N = tekst.length(), M = wzorzec.length();
    int i = 0, j = 0;
    int przesun[K];
    obliczPrzesunieciaBM(przesun, wzorzec, M);

    smallPrzerwa();
    cout << endl << "Tablica przesuniec: " << endl;
    for (int x = 0; x < K; x++) {
        cout << przesun[x] << endl;
    }
    cout << "Koniec tablicy" << endl << endl;

    smallPrzerwa();
    
    cout << endl << "Przed petla   \ni = " << i << endl << "j = " << j << endl << endl;

    for (i = M - 1, j = M - 1; j > 0; i--, j--) {

        cout << endl << "i = " << i << endl << "j = " << j << endl << endl;

        cout << endl << tekst << endl;
        printSzukawnie(wzorzec, 0, M, i - j);
        smallPrzerwa();

        while (tekst[i] != wzorzec[j]) {
            int x = przesun[indeks(tekst[i])];
            if (M - j > x) {
                i = i + M - j;
            }else {
                i = i + x;
            }
            if (i >= N) {
                return -1;
            }
            j = M - 1;
        }
    }
    cout << endl << tekst << endl;
    printSzukawnie(wzorzec, 0, M, i - j);
    smallPrzerwa();
    cout << endl << "Caly wzorzec zgodny" << endl;
    return i;
}
int main(){
    bigPrzerwa("Naiwny");
    cout << szukajNaiwny("ABA", "AAABAA");
    przerwa();
    cout << szukajNaiwnyOpis("ABA", "AAABAA");
    przerwa();
    cout << szukajNaiwny("AC", "AAAAAABA");
    przerwa();
    cout << szukajNaiwny("ABA", "AAAAAABA");
    przerwa();
    cout << szukajNaiwny("CCCD", "CCCCCD");
    bigPrzerwa("KMP");
    cout << szukajKMP("ABA", "AAABAA");
    przerwa();
    cout << szukajKMP("ABCDABC", "ABCBDABCDABC");
    przerwa();
    cout << szukajKMP("ABABD", "ABABCABABABABD");
    przerwa();

    bigPrzerwa("Zad4");

    cout << szukajNaiwnyOpis("AAAB", "AAAAAAAAAAAAAB");
    przerwa();
    cout << szukajKMP("AAAB", "AAAAAAAAAAAAAB");

    bigPrzerwa("BM");

    cout << szukajBM("ABA", "AAABAA");
    przerwa();

    cout << szukajBM("lek", "Z pamietnika mlodej lekarki");

}