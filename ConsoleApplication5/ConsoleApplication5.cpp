#include <iostream>
#include <random>
using namespace std;


template <class T> float srednia(unique_ptr<T>& tup, int r) {
    float suma = 0;
    for (int i = 0; i < r; i++) {
        suma += tup[i];
    }
    return suma / r;
}
template <class T> int ileMniejszych(T* tab, int r, T w) {

}



int main()
{
    setlocale(LC_CTYPE, "polish");

    random_device rd;
    uniform_real_distribution<float> udf(0, 10);

    try{
        int c1 = 7, c2 = 4;
        int r = c1 - c2;
        int iw = 5;
        double dw = 3.9;
        auto tup = make_unique<float[]>(r);
        for (int i = 0; i < r; i++) {
            tup[i] = udf(rd);
            cout << tup[i] << "   ";
        }
        cout << "\nSrednia = " << srednia(tup, r);
        cout << "Ilość mniejszych liczb = " << ileMniejszych(tup, r, iw);
        
    }
    catch (exception &e) {
        cout << endl << e.what();
        cout << endl << typeid(e).name();
    };
}

